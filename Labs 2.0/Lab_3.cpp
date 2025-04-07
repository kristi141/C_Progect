#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stack {
private:
    char* stackArr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        stackArr = new char[size];
        top = -1;
    }

    ~Stack() {
        delete[] stackArr;
    }

    void push(char item) {
        if (top == capacity - 1) return;
        stackArr[++top] = item;
    }

    char pop() {
        if (top == -1) return '\0';
        return stackArr[top--];
    }

    bool emptyCheck() {
        return top == -1;
    }

    char valueReturn() {
        if (top == -1) return '\0';
        return stackArr[top];
    }

    int size() const {
        return top + 1;
    }

    void clear() {
        top = -1;
    }
};

vector<string> findRepeatingFragmentsWithCustomStack(const string& input) {
    vector<string> fragments;
    Stack s(input.size());
    int start = 0;

    for (int i = 0; i <= input.size(); ++i) {
        if (i < input.size()) {
            char ch = input[i];
            if (s.emptyCheck() || ch == s.valueReturn()) {
                s.push(ch);
            } else {
                // Разрыв цепочки
                if (s.size() >= 4 && s.valueReturn() != ' ') {
                    fragments.push_back(input.substr(start, s.size()));
                }
                s.clear();
                s.push(ch);
                start = i;
            }
        } else {
            // Конец строки — финальная проверка
            if (s.size() >= 4 && s.valueReturn() != ' ') {
                fragments.push_back(input.substr(start, s.size()));
            }
        }
    }

    return fragments;
}

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    vector<string> result = findRepeatingFragmentsWithCustomStack(input);

    cout << "Найденные фрагменты:\n";
    for (const string& frag : result) {
        cout << frag << endl;
    }

    return 0;
}
