#include <stdio.h>

int main() {

    for (int num = 1; num <= 10000; num++) {
        int square = num * num; 

        int array[100001]; 

        int i = 0, temp = square;
        int normal = 0, reverse = 0;

        while (temp > 0) {

            array[i] = temp % 10;
            i++;
            temp /= 10;
        }

        for (int j = i - 1; j >= 0; j--) {

            normal = normal * 10 + array[j];
        }

        for (int k = 0; k < i; k++) {

            reverse = reverse * 10 + array[k];
        }

        if (normal == reverse) {

            if (i % 2 == 0) {
                printf("%d\n", square);
            }
        }
    }

    return 0;
}