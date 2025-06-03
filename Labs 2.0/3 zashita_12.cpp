/*Функция F12 вычисляет сумму всех чисел в двумерном массиве, 
представленном как массив указателей на массивы double, 
где каждая строка содержит n элементов.*/

#include <iostream>
using namespace std;

double F12(double* p[], int n) {
    double s = 0;

    for (int i = 0; p[i] != nullptr; i++) {
        for (int j = 0; j < n; j++) {
            s += p[i][j];
        }
    }

    return s;
}

int main() {
    // Статически определённые строки (по 3 элемента в каждой)
    double row0[] = {1.0, 2.0, 3.0};
    double row1[] = {4.0, 5.0, 6.0};
    double row2[] = {7.0, 8.0, 9.0};

    // Массив указателей на строки + NULL-терминатор
    double* matrix[] = {row0, row1, row2, nullptr};

    // В каждой строке по 3 элемента
    double result = F12(matrix, 3);

    cout << "Сумма: " << result << std::endl;

    return 0;
}

