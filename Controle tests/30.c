/*Задание:
for (i=0,a=2; a<v && i<m-1 ; a++){ 
      	for (s=0,j=0; j<i; j++)
           	if (a%A[j]==0) { s=1; break; }
      	if (s==0) A[i++]=a;
      	}
A[i]=0;

Программа выводит простые числа из заданного диапазона.
Например вводим диапазон - 100 и программа будет перебирать все числа от 1 до 100,
далее вводим количество простых чисел, например 5
Программа выведет: 2 3 5 7 11 

The program outputs prime numbers from a given range.
For example, enter the range - 100 and the program will iterate through all the numbers from 1 to 100,
then enter the number of prime numbers, for example 5
The program will output: 2 3 5 7 11 */

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
