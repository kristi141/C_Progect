#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>

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

// Функция для ввода записи с клавиатуры
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

// Функция для вывода таблицы
void displayTable(const vector<Student>& students) {
    cout << "\nСписок студентов:\n";

    for (const auto& student : students) {
        cout << student.surname << " " << student.gradeCount << " оценок: ";
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << "Средний балл: " << student.average << "\n";
    }
}

// Функция для сохранения в файл
void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);

    for (const auto& student : students) {
        file << student.surname << " " << student.gradeCount;

        for (int grade : student.grades) {
            file << " " << grade;
        }
    }
    file.close();
}

// Функция для загрузки из файла
vector<Student> loadFromFile(const string& filename) {
    vector<Student> students;
    ifstream file(filename);

    while (!file.eof()) {
        Student student;

        file >> student.surname >> student.gradeCount;
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

// Функция сортировки
void sortTable(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.average < b.average;
        }
    );
}

// Функция поиска студента
Student* searchStudent(vector<Student>& students, const string& surname) {
    for (auto& student : students) {
        if (student.surname == surname) {
            return &student;
        }
    }
    return nullptr;
}

// Функция удаления записи
void deleteStudent(vector<Student>& students, const string& surname) {
    students.erase(remove_if(students.begin(), students.end(), [&](const Student& s) {
        return s.surname == surname;
        }
    ), 
        students.end()
    );
}

// Функция редактирования записи
void editStudent(vector<Student>& students, const string& surname) {
    Student* student = searchStudent(students, surname);

    if (student) {
        *student = inputStudent();
    }
    else {
       cout << "Студент не найден!\n";
    }
}

// Функция вычисления суммы всех средних баллов
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
        cout << "\nМеню:\n";
        cout << "1. Ввод записи\n2. Просмотр таблицы\n3. Сохранить в файл\n4. Загрузить из файла\n5. Сортировка\n6. Поиск\n7. Удаление\n8. Редактирование\n9. Вычислить сумму средних баллов\n0. Выход\n";
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

        case 5:
            sortTable(students);
            cout << "Таблица отсортирована\n";
            break;

        case 6: {
            string searchName;
            cout << "Введите фамилию для поиска: ";
            cin >> searchName
                ;
            Student* found = searchStudent(students, searchName);
            if (found) {
               cout << "Найден: " << found->surname << " со средним баллом " << found->average << "\n";
            }
            else {
                cout << "Студент не найден!\n";
            }
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
