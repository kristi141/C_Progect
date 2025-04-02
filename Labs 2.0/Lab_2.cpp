#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Student {
    string surname;
    int gradeCount;
    vector<int> grades;
    double average;
};

// Функция для вычисления среднего балла
void calculateAverage(Student& student) {
    if (student.gradeCount == 0) {
        student.average = 0.0;
        return;
    }

    int sum = 0;
    for (int grade : student.grades) {
        sum += grade;
    }
    student.average = static_cast<double>(sum) / student.gradeCount;
}

// Функция для ввода студента
Student inputStudent() {
    Student student;

    cout << "Введите фамилию: ";
    cin >> student.surname;

    cout << "Введите количество оценок: ";
    cin >> student.gradeCount;
    student.grades.resize(student.gradeCount);

    cout << "Введите " << student.gradeCount << " оценок: ";
    for (int& grade : student.grades) {
        cin >> grade;
    }
    calculateAverage(student);
    return student;
}

// Вывод таблицы
void displayTable(const vector<Student>& students) {
    cout << "\nСписок студентов:\n";
    for (const auto& student : students) {
        cout << student.surname << " (" << student.gradeCount << " оценок): ";
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << "| Средний балл: " << student.average << "\n";
    }
}

// Сохранение в файл
void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    for (const auto& student : students) {
        file << student.surname << " " << student.gradeCount;
        for (int grade : student.grades) {
            file << " " << grade;
        }
        file << "\n"; // Добавляем перевод строки для корректной загрузки
    }
    file.close();
}

// Загрузка из файла
vector<Student> loadFromFile(const string& filename) {
    vector<Student> students;
    ifstream file(filename);

    if (!file) {
        cout << "Не удалось открыть файл для чтения.\n";
        return students;
    }

    Student student;
    while (file >> student.surname >> student.gradeCount) {
        student.grades.resize(student.gradeCount);
        for (int& grade : student.grades) {
            file >> grade;
        }
        calculateAverage(student);
        students.push_back(student);
    }

    file.close();
    return students;
}

// Сортировка
void sortTable(vector<Student>& students, int sortType) {
    switch (sortType) {
    case 1:
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.average < b.average;
        });
        break;
    case 2:
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.surname < b.surname;
        });
        break;
    case 3:
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.gradeCount < b.gradeCount;
        });
        break;
    default:
        cout << "Неверный тип сортировки!\n";
        return;
    }
    cout << "Таблица отсортирована\n";
}

// Поиск по фамилии
Student* searchStudent(vector<Student>& students, const string& surname) {
    for (auto& student : students) {
        if (student.surname == surname) {
            return &student;
        }
    }
    return nullptr;
}

// Поиск студентов по среднему баллу или количеству оценок
void searchByCriteria(const vector<Student>& students, int searchType) {
    if (students.empty()) {
        cout << "Список студентов пуст!\n";
        return;
    }

    if (searchType == 1) {
        string searchName;
        cout << "Введите фамилию для поиска: ";
        cin >> searchName;
        Student* found = searchStudent(const_cast<vector<Student>&>(students), searchName);
        if (found) {
            cout << "Найден: " << found->surname << " со средним баллом " << found->average << "\n";
        } else {
            cout << "Студент не найден!\n";
        }
    } else if (searchType == 2 || searchType == 3) {
        double searchValue;
        cout << "Введите значение для поиска: ";
        cin >> searchValue;

        bool found = false;
        for (const auto& student : students) {
            if ((searchType == 2 && student.gradeCount == searchValue) ||
                (searchType == 3 && abs(student.average - searchValue) < 1e-9)) {
                cout << "Найден: " << student.surname << "\n";
                found = true;
            }
        }
        if (!found) cout << "Совпадений не найдено.\n";
    } else {
        cout << "Неверный тип поиска!\n";
    }
}

// Удаление студента
void deleteStudent(vector<Student>& students, const string& surname) {
    students.erase(remove_if(students.begin(), students.end(),
        [&](const Student& s) { return s.surname == surname; }), students.end());
}

// Редактирование студента
void editStudent(vector<Student>& students, const string& surname) {
    Student* student = searchStudent(students, surname);
    if (student) {
        *student = inputStudent();
    } else {
        cout << "Студент не найден!\n";
    }
}

// Подсчет общей суммы средних баллов
double calculateTotalAverage(const vector<Student>& students) {
    double sum = 0.0;
    for (const auto& student : students) {
        sum += student.average;
    }
    return sum;
}

int main() {
    vector<Student> students;
    int choice;
    string filename = "Students.txt";

    do {
        cout << "Меню:"<< endl;
        cout << "1. Ввод записи"<< endl; 
        cout << "2. Просмотр таблицы"<< endl; 
        cout << "3. Сохранить в файл"<< endl;  
        cout << "4. Загрузить из файла"<< endl;  
        cout << "5. Сортировка"<< endl; 
        cout << "6. Поиск"<< endl; 
        cout << "7. Удаление"<< endl;
        cout << "8. Редактирование"<< endl;
        cout << "9. Вычислить сумму средних баллов"<< endl; 
        cout << "0. Выход"<< endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            students.push_back(inputStudent());
            break;

        case 2:
            displayTable(students);
            break;

        case 3:
            saveToFile(students, filename);
            cout << "Данные сохранены\n";
            break;

        case 4:
            students = loadFromFile(filename);
            cout << "Данные загружены\n";
            break;

         case 5: {
                int sortType;
                cout << "Выберите тип сортировки:\n";
                cout << "1 - По среднему баллу\n";
                cout << "2 - По фамилии\n";
                cout << "3 - По количеству оценок\n";
                cout << "Введите номер: ";
                cin >> sortType;

                sortTable(students, sortType);
                break;
            }


            case 6: {
                int searchType;
                cout << "Выберите критерий поиска:\n";
                cout << "1 - По фамилии\n";
                cout << "2 - По количеству оценок\n";
                cout << "3 - По среднему баллу\n";
                cout << "Введите номер: ";
                cin >> searchType;

                searchByCriteria(students, searchType);
                 break;
            }

             case 7: {
                string deleteName;
                cout << "Введите фамилию для удаления: ";
                cin >> deleteName;

                deleteStudent(students, deleteName);
                break;
             }

            case 8: {
                string editName;
                cout << "Введите фамилию для редактирования: ";
                cin >> editName;

                editStudent(students, editName);
                break;
            }

            case 9:
                cout << "Общая сумма средних баллов: " << calculateTotalAverage(students) << "\n";
                break;
            }
    } while (choice != 0);

    return 0;
}
