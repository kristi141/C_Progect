#include <stdio.h>

int main() {
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

    return 0;
}
