//T(n)=2n+1 ∈O(n)

#include <iostream>
#include <cstring>
using namespace std;

int counter = 0; // Счётчик рекурсивных вызовов

void F8(char*& p, char* s) {
    counter++; // Подсчёт вызовов

    if (*s == '\0') return;

    *p++ = *s;        // Прямой ход
    F8(p, s + 1);     // Рекурсивный вызов
    *p++ = *s;        // Обратный ход
}

int main() {
    char *q, S[160];
    q = S;
    F8(q, (char*)"abcdefghij");
    *q = 0;

    cout << "Результат: " << S << endl;
    cout << "Количество рекурсивных вызовов: " << counter << endl;
    cout << "Количество операций копирования символов: " << strlen("abcd") * 2 << endl;

}
