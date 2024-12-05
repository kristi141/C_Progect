/*Задание:
for (i=1,k=0; i<10; i++)
     if (A[i]>A[k]) k=i;

Программа перебирает все элементы в массиве и выводит максимальный.
Например вводим 5 1 3 -1 5 7
Программа выводит 7

The program iterates through all the elements in the array and outputs the maximum.
For example, enter 5 1 3 -1 5 7
The program outputs 7 */

#include <stdio.h>

int main() {
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

    return 0;
}
