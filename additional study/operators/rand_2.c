/*Продолжите программу, которая генерирует псевдослучайные целые числа в диапазоне от a до b (включительно). 
Числа a и b (a < b) считываются из входного потока. Для формирования диапазона значений используйте 
арифметическую операцию вычисления целого остатка от деления.
Сгенерируйте десять псевдослучайных чисел и выведите их в консоль в одну строчку через пробел.

Continue with the program that generates pseudorandom integers in the range from a to b (inclusive). 
The numbers a and b (a < b) are read from the input stream. To form a range of values, use
the arithmetic operation of calculating the integer remainder of the division.
Generate ten pseudo-random numbers and output them to the console in one line separated by a space. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    int  aa, bb, c, d, e, f, g, h, i, j;
    scanf("%d %d", &a, &b);

    aa = rand() % (b - a + 1) + a;
    bb = rand() % (b - a + 1) + a;
    c = rand() % (b - a + 1) + a;
    d = rand() % (b - a + 1) + a;
    e = rand() % (b - a + 1) + a;
    f = rand() % (b - a + 1) + a;
    g = rand() % (b - a + 1) + a;
    h = rand() % (b - a + 1) + a;
    i = rand() % (b - a + 1) + a;
    j = rand() % (b - a + 1) + a;
    
    printf("%d %d %d %d %d %d %d %d %d %d ",aa, bb, c, d, e, f, g, h, i, j);

    return 0;
}