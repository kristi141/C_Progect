#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class TextEditor {
    string filename;
    fstream file;
    vector<streampos> lineOffsets; // Смещения начала строк
    vector<int> lineMap; // Отображение индексов строк

    int totalLines = 0;
    int viewStart = 0;
    const int viewSize = 10; // Кол-во строк в окне просмотра

public:
    TextEditor(const string& fname) : filename(fname) {
        indexFile();
    }

    void indexFile() {
        file.open(filename, ios::in);
        
        if (!file.is_open()) {
            cerr << "Не удалось открыть файл.\n";
            exit(1);
        }

        lineOffsets.clear();
        lineMap.clear();

        streampos pos = file.tellg();
        string line;

        while (getline(file, line)) {
            lineOffsets.push_back(pos);
            pos = file.tellg();
        }

        totalLines = lineOffsets.size();
        for (int i = 0; i < totalLines; ++i)
            lineMap.push_back(i);

        file.clear(); // Сброс EOF-флага
    }

    void clearScreen() {
#ifdef _WIN32
        int res = system("cls");
#else
        int res = system("clear");
#endif
        (void)res;
    }

    void display() {
        clearScreen();

        for (int i = viewStart; i < viewStart + viewSize && i < lineMap.size(); ++i) {
            printLine(lineMap[i]);
        }

        cout  << "\nДоступные команды:\n"
                 << "  d <n>      — удалить строку под номером n\n"
                 << "  c <n>      — копировать строку под номером n\n"
                 << "  s <a> <b>  — поменять строки a и b местами\n"
                 << "  u          — прокрутка вверх\n"
                 << "  j          — прокрутка вниз\n"
                 << "  w <имя>    — сохранить результат в новый файл\n"
                 << "  q          — выйти из редактора\n"
                 << "\nВведите команду:\n> ";
    }

    void printLine(int index) {
        file.seekg(lineOffsets[index]);
        string line;
        getline(file, line);
        cout << index + 1 << ": " << line << "\n";
    }

    void deleteLine(int lineNumber) {
        if (lineNumber < 1 || lineNumber > (int)lineMap.size()) {
            cout << "Неверный номер строки\n";
            return;
        }

        lineMap.erase(lineMap.begin() + (lineNumber - 1));
    }

    void copyLine(int lineNumber) {
        if (lineNumber < 1 || lineNumber > (int)lineMap.size()) {
            cout << "Неверный номер строки\n";
            return;
        }

        lineMap.insert(lineMap.begin() + lineNumber, lineMap[lineNumber - 1]);
    }

    void swapLines(int a, int b) {
        if (a < 1 || b < 1 || a > (int)lineMap.size() || b > (int)lineMap.size()) {
            cout << "Неверный номер строки\n";
            return;
        }

        swap(lineMap[a - 1], lineMap[b - 1]);
    }

    void scrollUp() {
        if (viewStart > 0) viewStart--;
    }

    void scrollDown() {
        if (viewStart + viewSize < (int)lineMap.size()) viewStart++;
    }

    void saveToFile(const string& outFilename) {
        ofstream out(outFilename);

        if (!out.is_open()) {
            cout << "Ошибка при сохранении файла.\n";
            return;
        }

        for (int idx : lineMap) {
            file.seekg(lineOffsets[idx]);
            string line;
            getline(file, line);
            out << line << '\n';
        }

        out.close();
        cout << "Сохранено в файл: " << outFilename << "\n";
    }

    void run() {
        string input;

        while (true) {
            display();
            getline(cin, input);

            if (input.empty()) continue;

            istringstream iss(input);
            char cmd;
            iss >> cmd;

            switch (cmd) {
                case 'q':
                    return;

                case 'd': {
                    int n;
                    if (iss >> n) deleteLine(n);
                    else cout << "Формат: d <номер строки>\n";
                    break;
                }

                case 'c': {
                    int n;
                    if (iss >> n) copyLine(n);
                    else cout << "Формат: c <номер строки>\n";
                    break;
                }

                case 's': {
                    int a, b;
                    if (iss >> a >> b) swapLines(a, b);
                    else cout << "Формат: s <строка1> <строка2>\n";
                    break;
                }

                case 'u':
                    scrollUp();
                    break;

                case 'j':
                    scrollDown();
                    break;

                case 'w': {
                    string outFile;
                    if (iss >> outFile) saveToFile(outFile);
                    else cout << "Формат: w <имя файла для сохранения>\n";
                    break;
                }

                default:
                    cout << "Неизвестная команда.\n";
                    break;
            }
        }

        file.close();
    }
};

int main() {
    string fname;
    cout << "Введите имя текстового файла: ";
    cin >> fname;

    cin.ignore(); // Очистка символа новой строки
    TextEditor editor(fname);
    editor.run();

    return 0;
}
