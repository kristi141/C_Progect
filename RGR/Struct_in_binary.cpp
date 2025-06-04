#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string FILENAME = "data.bin";

// Запись строки по индексу
void writeStringToFile(const string& filename, int index, const string& text) {
    fstream file(filename, ios::binary | ios::in | ios::out);

    if (!file) {
        cerr << "Не удалось открыть файл для записи.\n";
        return;
    }

    int count;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (index >= count || index < 0) {
        cerr << "Индекс вне допустимого диапазона.\n";
        return;
    }

    file.seekg(sizeof(int) + index * sizeof(long), ios::beg);
    long offset;
    file.read(reinterpret_cast<char*>(&offset), sizeof(long));

    file.seekp(0, ios::end);
    long newOffset = file.tellp();

    int len = text.size();
    file.write(reinterpret_cast<char*>(&len), sizeof(int));
    file.write(text.c_str(), len);

    file.seekp(sizeof(int) + index * sizeof(long), ios::beg);
    file.write(reinterpret_cast<char*>(&newOffset), sizeof(long));

    file.close();
}

// Чтение строки по индексу
string readStringFromFile(const string& filename, int index) {
    ifstream file(filename, ios::binary);

    if (!file) {
        cerr << "Не удалось открыть файл для чтения.\n";
        return "";
    }

    int count;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (index >= count || index < 0) {
        cerr << "Индекс вне допустимого диапазона.\n";
        return "";
    }

    file.seekg(sizeof(int) + index * sizeof(long), ios::beg);
    long offset;
    file.read(reinterpret_cast<char*>(&offset), sizeof(long));

    if (offset == 0) {
        return "[пусто]";
    }

    file.seekg(offset, ios::beg);
    int len;
    file.read(reinterpret_cast<char*>(&len), sizeof(int));

    string result(len, '\0');
    file.read(&result[0], len);

    return result;
}

// Инициализация файла
void initializeFile(const string& filename, int size) {
    ofstream file(filename, ios::binary);
    
    if (!file) {
        cerr << "Не удалось создать файл.\n";
        return;
    }

    file.write(reinterpret_cast<const char*>(&size), sizeof(int));
    vector<long> pointers(size, 0);
    file.write(reinterpret_cast<const char*>(pointers.data()), sizeof(long) * size);
    file.close();
}

// Получение количества строк из файла
int getArraySize(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) return -1;

    int count;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    return count;
}

// Главное меню
void showMenu() {
    cout << "\n--- Меню ---\n";
    cout << "1. Ввести строку по индексу\n";
    cout << "2. Прочитать строку по индексу\n";
    cout << "3. Показать все строки\n";
    cout << "4. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    int size;
    cout << "Введите количество строк: ";
    cin >> size;
    cin.ignore();
    initializeFile(FILENAME, size);

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int index;
            string text;
            cout << "Введите индекс строки: ";
            cin >> index;
            cin.ignore();
            cout << "Введите строку: ";
            getline(cin, text);
            writeStringToFile(FILENAME, index, text);
        }
        else if (choice == 2) {
            int index;
            cout << "Введите индекс строки для чтения: ";
            cin >> index;
            cin.ignore();
            string result = readStringFromFile(FILENAME, index);
            cout << "Строка с индексом " << index << ": " << result << "\n";
        }
        else if (choice == 3) {
            int count = getArraySize(FILENAME);
            cout << "--- Все строки ---\n";
            for (int i = 0; i < count; ++i) {
                string result = readStringFromFile(FILENAME, i);
                cout << "Строка " << i << ": " << result << "\n";
            }
        }
        else if (choice == 4) {
            cout << "Выход из программы.\n";
        }
        else {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }

    } while (choice != 4);

    return 0;
}
