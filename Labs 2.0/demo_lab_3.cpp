#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stack {
private:
    int* stackArr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        stackArr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] stackArr;
    }

    void push(int item) {
        if (top < capacity - 1) {
            stackArr[++top] = item;
        }
    }

    int pop() {
        return (top == -1) ? -1 : stackArr[top--];
    }

    bool emptyCheck() {
        return top == -1;
    }

    int valueReturn() {
        return (top == -1) ? -1 : stackArr[top];
    }
};

// Функции для сопоставления скобок
char getMatchingOpeningBracket(char closing) {
    switch (closing) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        case '>': return '<';
        default: return '\0';
    }
}

char getMatchingClosingBracket(char opening) {
    switch (opening) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        case '<': return '>';
        default: return '\0';
    }
}

// Функция для извлечения вложенных скобок
vector<string> extractInnerBrackets(string& input) {
    vector<string> extractedFragments;

    while (true) {
        Stack stack(input.size());
        int start = -1, end = -1;
        bool found = false;

        // Ищем самую внутреннюю пару скобок
        for (int i = 0; i < input.size(); i++) {
            char ch = input[i];

            // Открывающая скобка
            if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
                stack.push(i);
            } 
            // Закрывающая скобка
            else if (ch == ')' || ch == ']' || ch == '}' || ch == '>') {
                if (!stack.emptyCheck() && input[stack.valueReturn()] == getMatchingOpeningBracket(ch)) {
                    start = stack.pop();
                    end = i;
                    found = true;
                    break; // Берем только самый вложенный фрагмент
                }
            }
        }

        if (!found) break; // Если скобок не осталось, выходим из цикла

        // Извлекаем содержимое скобок
        string fragment = input.substr(start + 1, end - start - 1);
        extractedFragments.push_back(fragment);

        // Удаляем найденный фрагмент вместе со скобками
        input.erase(start, end - start + 1);
    }

    // Добавляем остаток строки
    if (!input.empty()) {
        extractedFragments.push_back(input);
    }

    return extractedFragments;
}

int main() {
    string input;
    cout << "Введите строку со скобками: ";
    getline(cin, input);

    vector<string> result = extractInnerBrackets(input);

    cout << "Извлеченные фрагменты:\n";
    for (const string& fragment : result) {
        cout << fragment << endl;
    }

    return 0;
}
