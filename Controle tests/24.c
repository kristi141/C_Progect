/*Задание:
for (j=0,i=0; i<n ; i++){
      	for (s=0,m=2; m<A[i]; m++)
           if (A[i]%m==0) { s=1; break; }
      	if (s==0) B[j++]=A[i];
      	}
B[j]=0; 

Программа выводит простые числа из заданных.
Например при вводе 1 2 3 4 5 6 программа выведет 2 3 5, так как это простые числа.

The program outputs prime numbers from the given ones.
For example, if you enter 1 2 3 4 5 6, the program will output 2 3 5, since these are prime numbers. */

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
