/*for (s=0, sn = x, n=2; fabs(sn) > eps; n+=2)
{ s += sn;
sn= sn * x *x * (n -1) / (n+1); } */

#include <stdio.h>
#include <math.h>  // Для функции fabs()

int main() {
    double s = 0.0;  // Сумма ряда
    double sn;       // Текущий член ряда
    double x = 1.0;  // Примерное значение x (можно изменить по желанию)
    double eps = 1e-6;  // Точность для прекращения вычислений (эпсилон)
    int n = 2;        // Начальное значение для n (член с четным числом)

    sn = x;  // Первый член ряда (может зависеть от ряда, который вы вычисляете)

    // Цикл продолжается, пока абсолютное значение текущего члена ряда больше eps
    for (; fabs(sn) > eps; n += 2) {
        s += sn;  // Добавляем текущий член к общей сумме
        sn = sn * x * x * (n - 1) / (n + 1);  // Вычисляем следующий член ряда
    }

    printf("Сумма ряда: %lf\n", s);  // Вывод суммы ряда

    return 0;
}
