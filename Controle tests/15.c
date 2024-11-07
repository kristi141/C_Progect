#include <stdio.h>

int main() {
    int n, s = 0, k, a;

    printf("Введите число: \n");
    scanf("%d", &a);

    for (n = a; n != 0; n = n / 10) {
        k = n % 10;
        s = s * 10 + k;
    }

    printf("Перевернутое число: %d\n", s);

    return 0;
}
