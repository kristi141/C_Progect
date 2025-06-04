

#include <iostream>
using namespace std;

int operations = 0; // Счётчик операций

void F10(int* p, int nn) {
    operations++; // Счёт рекурсивных вызовов

    if (nn == 1) {
        *p = 0;
        return;
    }

    int i;
    for (i = 2; nn % i != 0; i++) {
        operations++; // Счёт итераций поиска делителя
    }

    *p = i;
    F10(p + 1, nn / i);
}

int main() {
    int A[100];
    int number = 60; // можно менять

    F10(A, number);

    cout << "Разложение числа " << number << " на множители: ";
    for (int i = 0; A[i] != 0; i++) {
        cout << A[i] << " ";
    }
    cout << "\nОбщее количество операций (итерации + вызовы): " << operations << endl;
}
