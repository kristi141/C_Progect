#include <stdio.h>
#include <math.h>  

int main() {
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

    return 0;
}
