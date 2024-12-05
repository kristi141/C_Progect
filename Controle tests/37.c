/*Задание:
for (s=0, i=0; i<n-1; i++){
      	for (j=i+1, m=0; j<n; j++)
        	if (c[i]==c[j]) m++;
      	if (m > s) s=m, b=i;
      	}

Программа ищет количество повторений из заданных чисел.
В программу вводится 5 чисел и программа выводит сколько чисел повторяется.
Например вводим 1 2 1 2 1
Программа выведет Элемент с наибольшим количеством повторений: 1 (встречается 3 раза)
Если повторяющихся элементов нет то программа выводит что все элементы уникальны.

The program searches for the number of repetitions from the given numbers.
5 numbers are entered into the program and the program outputs how many numbers are repeated.
For example, enter 1 2 1 2 1
The program will output the Element with the most repetitions: 1 (occurs 3 times)
If there are no duplicate elements, the program outputs that all the elements are unique. */

#include <stdio.h>

int duplicateNumbers(){
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
}

int main() {
   
   duplicateNumbers();
   
    return 0;
    
}
