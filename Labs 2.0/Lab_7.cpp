#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

// --- Проверка для строк char* (только буквы) ---
bool isValidCharString(const string& s) {
    for (char c : s) {
        if (!isalpha(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

// --- Дерево int* ---
class NodeInt {
public:
    int* data;
    vector<NodeInt*> children;
    int capacity;

    NodeInt(int* d, int cap) : data(d), capacity(cap) {}
    ~NodeInt() {
        for (auto c : children) delete c;
        delete data;
    }
};

class TreeInt {
    NodeInt* root = nullptr;
    int initialCapacity;

    NodeInt* findAvailable(NodeInt* node) {
        if (node->children.size() < node->capacity) return node;
        for (auto c : node->children) {
            NodeInt* found = findAvailable(c);
            if (found) return found;
        }
        return nullptr;
    }

    void flatten(NodeInt* node, vector<int*>& out) {
        if (!node) return;
        out.push_back(node->data);
        for (auto c : node->children) flatten(c, out);
    }

    void printNode(NodeInt* node, int level, int idx) {
        for (int i = 0; i < level; i++) cout << "    ";
        if (level > 0) cout << "|-- " << idx << ". ";
        cout << *node->data << endl;
        for (int i = 0; i < (int)node->children.size(); i++)
            printNode(node->children[i], level + 1, i + 1);
    }

    // Рекурсивная функция для вывода отсортированного дерева int
    int printSortedNode(const vector<int*>& flat, int index, int level) {
        if (index >= (int)flat.size()) return index;
        for (int i = 0; i < level; i++) cout << "    ";
        if (level > 0) cout << "|-- " << index << ". ";
        cout << *flat[index] << endl;
        int nextIndex = index + 1;
        for (int i = 0; i < initialCapacity; i++) {
            if (nextIndex < (int)flat.size())
                nextIndex = printSortedNode(flat, nextIndex, level + 1);
            else
                break;
        }
        return nextIndex;
    }

public:
    TreeInt(int cap) : initialCapacity(cap) {}
    ~TreeInt() { delete root; }

    void add(int val) {
        int* p = new int(val);
        if (!root) root = new NodeInt(p, initialCapacity);
        else {
            NodeInt* parent = findAvailable(root);
            if (parent)
                parent->children.push_back(new NodeInt(p, initialCapacity));
            else
                root->children.push_back(new NodeInt(p, initialCapacity));
        }
    }

    void print() {
        if (!root) {
            cout << "Дерево int* пусто!\n";
            return;
        }
        cout << "1. " << *root->data << endl;
        for (int i = 0; i < (int)root->children.size(); i++)
            printNode(root->children[i], 1, i + 1);
    }

    void printSorted() {
        if (!root) {
            cout << "Дерево int* пусто!\n";
            return;
        }
        vector<int*> flat;
        flatten(root, flat);
        sort(flat.begin(), flat.end(), [](int* a, int* b) { return *a < *b; });
        cout << "Отсортированное дерево int*:\n";
        printSortedNode(flat, 0, 0);
    }
};

// --- Дерево char* ---
class NodeChar {
public:
    char* data;
    vector<NodeChar*> children;
    int capacity;

    NodeChar(char* d, int cap) : data(d), capacity(cap) {}
    ~NodeChar() {
        for (auto c : children) delete c;
        delete[] data;
    }
};

class TreeChar {
    NodeChar* root = nullptr;
    int initialCapacity;

    NodeChar* findAvailable(NodeChar* node) {
        if (node->children.size() < node->capacity) return node;
        for (auto c : node->children) {
            NodeChar* found = findAvailable(c);
            if (found) return found;
        }
        return nullptr;
    }

    void flatten(NodeChar* node, vector<char*>& out) {
        if (!node) return;
        out.push_back(node->data);
        for (auto c : node->children) flatten(c, out);
    }

    void printNode(NodeChar* node, int level, int idx) {
        for (int i = 0; i < level; i++) cout << "    ";
        if (level > 0) cout << "|-- " << idx << ". ";
        cout << node->data << endl;
        for (int i = 0; i < (int)node->children.size(); i++)
            printNode(node->children[i], level + 1, i + 1);
    }

    // Рекурсивная функция для вывода отсортированного дерева char
    int printSortedNode(const vector<char*>& flat, int index, int level) {
        if (index >= (int)flat.size()) return index;
        for (int i = 0; i < level; i++) cout << "    ";
        if (level > 0) cout << "|-- " << index << ". ";
        cout << flat[index] << endl;
        int nextIndex = index + 1;
        for (int i = 0; i < initialCapacity; i++) {
            if (nextIndex < (int)flat.size())
                nextIndex = printSortedNode(flat, nextIndex, level + 1);
            else
                break;
        }
        return nextIndex;
    }

public:
    TreeChar(int cap) : initialCapacity(cap) {}
    ~TreeChar() { delete root; }

    void add(const string& str) {
        char* p = new char[str.length() + 1];
        strcpy(p, str.c_str());
        if (!root) root = new NodeChar(p, initialCapacity);
        else {
            NodeChar* parent = findAvailable(root);
            if (parent)
                parent->children.push_back(new NodeChar(p, initialCapacity));
            else
                root->children.push_back(new NodeChar(p, initialCapacity));
        }
    }

    void print() {
        if (!root) {
            cout << "Дерево char* пусто!\n";
            return;
        }
        cout << "1. " << root->data << endl;
        for (int i = 0; i < (int)root->children.size(); i++)
            printNode(root->children[i], 1, i + 1);
    }

    void printSorted() {
        if (!root) {
            cout << "Дерево char* пусто!\n";
            return;
        }
        vector<char*> flat;
        flatten(root, flat);
        sort(flat.begin(), flat.end(), [](char* a, char* b) { return strcmp(a,b) < 0; });
        cout << "Отсортированное дерево char*:\n";
        printSortedNode(flat, 0, 0);
    }
};

// --- Массив int* ---
class ArrayInt {
    vector<int*> data;
public:
    void add(int val) {
        int* p = new int(val);
        data.push_back(p);
    }
    void print() {
        if (data.empty()) {
            cout << "Массив int* пуст.\n";
            return;
        }
        cout << "Массив int*: ";
        for (auto p : data) cout << *p << " ";
        cout << endl;
    }
    void sortData() {
        sort(data.begin(), data.end(), [](int* a, int* b) { return *a < *b; });
    }
    ~ArrayInt() {
        for (auto p : data) delete p;
    }
};

// --- Массив char* ---
class ArrayChar {
    vector<char*> data;
public:
    void add(const string& str) {
        char* p = new char[str.length() + 1];
        strcpy(p, str.c_str());
        data.push_back(p);
    }
    void print() {
        if (data.empty()) {
            cout << "Массив char* пуст.\n";
            return;
        }
        cout << "Массив char*: ";
        for (auto p : data) cout << p << " ";
        cout << endl;
    }
    void sortData() {
        sort(data.begin(), data.end(), [](char* a, char* b) { return strcmp(a,b) < 0; });
    }
    ~ArrayChar() {
        for (auto p : data) delete[] p;
    }
};

int main() {
    int capacity;
    cout << "Введите начальную емкость узлов для деревьев: ";
    cin >> capacity;

    TreeInt treeInt(capacity);
    TreeChar treeChar(capacity);
    ArrayInt arrInt;
    ArrayChar arrChar;

    int option;
    do {
        cout << "\nМеню:\n"
             << "1. Добавить число в дерево int\n"
             << "2. Добавить строку в дерево char\n"
             << "3. Добавить число в массив int\n"
             << "4. Добавить строку в массив char\n"
             << "5. Показать дерево int\n"
             << "6. Показать дерево char\n"
             << "7. Показать массив int\n"
             << "8. Показать массив char\n"
             << "9. Отсортировать и показать дерево int\n"
             << "10. Отсортировать и показать дерево char\n"
             << "11. Отсортировать и показать массив int\n"
             << "12. Отсортировать и показать массив char\n"
             << "13. Выход\n"
             << "Выберите опцию: ";
        cin >> option;

        switch(option) {
            case 1: {
                int v; 
                cout << "Введите число: "; 
                if (!(cin >> v)) {
                    cout << "Ошибка: введено не число, данные не добавлены.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    treeInt.add(v);
                }
                break;
            }
            case 2: {
                string s; 
                cout << "Введите строку (только буквы): "; 
                cin >> s;
                if (!isValidCharString(s)) {
                    cout << "Ошибка: введена некорректная строка, данные не добавлены.\n";
                } else {
                    treeChar.add(s);
                }
                break;
            }
            case 3: {
                int v; 
                cout << "Введите число: "; 
                if (!(cin >> v)) {
                    cout << "Ошибка: введено не число, данные не добавлены.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    arrInt.add(v);
                }
                break;
            }
            case 4: {
                string s; 
                cout << "Введите строку (только буквы): "; 
                cin >> s;
                if (!isValidCharString(s)) {
                    cout << "Ошибка: введена некорректная строка, данные не добавлены.\n";
                } else {
                    arrChar.add(s);
                }
                break;
            }
            case 5:
                treeInt.print();
                break;
            case 6:
                treeChar.print();
                break;
            case 7:
                arrInt.print();
                break;
            case 8:
                arrChar.print();
                break;
            case 9:
                treeInt.printSorted();
                break;
            case 10:
                treeChar.printSorted();
                break;
            case 11:
                arrInt.sortData();
                arrInt.print();
                break;
            case 12:
                arrChar.sortData();
                arrChar.print();
                break;
            case 13:
                cout << "Выход...\n";
                break;
            default:
                cout << "Некорректная опция. Попробуйте снова.\n";
                break;
        }

    } while (option != 13);

    return 0;
}
