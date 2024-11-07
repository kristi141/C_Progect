#include <stdio.h>

int main() {
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

    return 0;
}
