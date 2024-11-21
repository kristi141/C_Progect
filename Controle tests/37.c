#include <stdio.h>

int main() {
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

    return 0;
}
