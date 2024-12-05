#include <stdio.h>
#include <math.h>  

int sumOfNumber() { // 13 F1
    int a;
    int s = 0;

    printf("Введите число :\n");
    scanf("%d", &a);

    for (int n = a; n != 0; n = n / 10) {
        int k = n % 10;
        s = s + k;
    }
    printf("Сумма цифр: %d\n ", s);
} //F1

int reverseNumber() { //15 F2
    int n, s = 0, k, a;

    printf("Введите число: \n");
    scanf("%d", &a);

    for (n = a; n != 0; n = n / 10) {
        k = n % 10;
        s = s * 10 + k;
    }

    printf("Перевернутое число: %d\n", s);
} //F2

int primeNumbers() { //24 F3
    int j = 0, s, m;
    int n = 6;
    int A[1001];
    int B[1001];

    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        int array = A[i];

        if (array <= 1) {
            continue;
        }

        s = 0;
        for (m = 2; m <= sqrt(array); m++) {
            if (array % m == 0) {
                s = 1;
                break;
            }
        }

        if (s == 0) {
            B[j++] = array;
        }
    }
    B[j] = 0;

    printf("Простые числа: ");

    for (int k = 0; k < j; k++) {
        printf("%d ", B[k]);
    }
    printf("\n");

} //F3

int rangePrimeNumber() { // 30 F4
    int i = 0, s, a, v, m, j;
    int A[1001];

    printf("Введите границу диапазона: \n");
    scanf("%d", &v);

    printf("Введите количество простых чисел: \n");
    scanf("%d", &m);

    for (a = 2; a < v && i < m; a++) {
        s = 0;

        for (j = 0; j < i; j++) {

            if (a % A[j] == 0) {
                s = 1;
                break;
            }
        }

        if (s == 0) {
            A[i++] = a;
        }
    }

    A[i] = 0;

    printf("Найденные простые числа: ");

    for (j = 0; j < i; j++) {
        printf("%d ", A[j]);
    }
    printf("\n");

} //F4

int duplicateNumbers() { // 37 F5
    int n = 5;
    int c[1001];
    int i, b, s = 0;

    printf("Введите %d целых чисел:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    for (i = 0; i < n - 1; i++) {
        int m = 1;

        for (int j = i + 1; j < n; j++) {
            if (c[i] == c[j]) {
                m++;
            }
        }

        if (m > s) {
            s = m;
            b = c[i];
        }
    }

    if (s > 1) {
        printf("Элемент с наибольшим количеством повторений: %d (встречается %d раза)\n", b, s);
    }
    else {
        printf("Все элементы уникальны.\n");
    }
} //F5

int sumToNegativeNumber() { // 41 F6
    int k = 0, s = 0, i = 0;
    int A[1001];
    int n;

    printf("Введите количество элементов массива: \n");
    scanf("%d", &n);

    printf("Введите элементы массива:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    i = 0;

    for (; i < n && k == 0; i++) {
        if (A[i] < 0) {
            k = 1;
        }
        else {
            s = s + A[i];
        }
    }

    printf("Сумма элементов до первого отрицательного: %d\n", s);
} //F6

int maxNumber() { // 52 F7
    int k = 0;
    int A[1001];
    int n = 6;

    printf("Введите %d целых чисел:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 1; i < n; i++) {
        if (A[i] > A[k]) {
            k = i;
        }
    }

    printf("Максимальный элемент: %d \n", A[k]);
} //F7

int main() {
    int x;

    printf("Выберете функцию для работы:\n ");
    printf("1.F1\n 2.F2\n 3.F3\n 4.F4\n 5.F5\n 6.F6\n 7.F7\n");

    while (scanf("%d", &x)) {

        switch (x) {
        case 1:
            printf("Выбранная функция считает сумму цифр в числе\n\n");
            sumOfNumber();
            break;

        case 2:
            printf("Выбранная функция выводит число в обратном порядке\n\n");
            reverseNumber();
            break;

        case 3:
            printf("Выбранная функция выводит простые числа из заданных\n\n");
            primeNumbers();
            break;

        case 4:
            printf("Выбранная функция выводит простые числа из заданного диапазона\n\n");
            rangePrimeNumber();
            break;

        case 5:
            printf("Выбранная функция ищет количество повторений из заданных чисел\n\n");
            duplicateNumbers();
            break;

        case 6:
            printf("Выбранная функция считает сумму элементов в массиве до первого отрицательного\n\n");
            sumToNegativeNumber();
            break;

        case 7:
            printf("Выбранная функция ищет максимальный элемент\n\n");
            maxNumber();
            break;

        case 0:
            printf("Программа остановлена");
            break;

        default:
            printf("Выбрана некорректная опция!\n");
            break;
        }

        if (x == 0) {
            break;
        }
    }

    return 0;
}