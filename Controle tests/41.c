/*Задание:
for (k=0,s=0,i=0; i<n && k==0; i++){
	if (A[i]<0) k=1;
	s=s+A[i];
	}

 Программа считает сумму элементов в массиве до первого попавшегося отрицательного.
 Например вводим 5 1 3 -1 5 7
 Программа мыводит 4   

 The program counts the sum of the elements in the array to the first negative one.
 For example, enter 5 1 3 -1 5 7
The program outputs 4 */

#include <stdio.h>

int sumToNegativeNumber(){
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
}

int main() {
   
   sumToNegativeNumber();

    return 0;
}
