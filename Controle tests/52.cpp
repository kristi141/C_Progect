#include <stdio.h>

int main() {
    int k = 0;
    int A[1001];
    int n = 6;

    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // индекс максимального элемента
    for (int i = 1; i < n; i++) {
        if (A[i] > A[k]) {
            k = i;
        }
    }

    printf("Максимальный элемент: %d = %d\n", k, A[k]);

    return 0;
}
