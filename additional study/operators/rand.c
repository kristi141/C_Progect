/*Продолжите программу, которая генерирует семь целых псевдослучайных чисел в диапазоне от 0 до N (включительно). 
Число N меньше значения константы RAND_MAX. Для формирования диапазона значений используйте арифметическую операцию 
вычисления целого остатка от деления. Выведите сгенерированные числа в консоль в одну строчку через пробел.

Continue the program, which generates seven pseudorandom integers in the range from 0 to N (inclusive). 
The number N is less than the value of the RAND_MAX constant. To form a range of values, use the arithmetic operation
of calculating the integer remainder of the division. Print the generated numbers to the console in one line separated by a space.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, a, b, c, d, e, f, g;
    scanf("%d", &N);

    a = rand() % (N + 1);
    b = rand() % (N + 1);
    c = rand() % (N + 1);
    d = rand() % (N + 1);
    e = rand() % (N + 1);
    f = rand() % (N + 1);
    g = rand() % (N + 1);
    
    printf("%d %d %d %d %d %d %d", a, b, c, d, e, f, g);

    return 0;
}