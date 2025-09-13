/* Продолжите программу, которая генерирует псевдослучайные вещественные числа в диапазоне от a до b (включительно). 
Целые числа a и b (a < b) считываются из входного потока. 
Значения формируются путем уменьшения исходного диапазона значений [0; RAND_MAX] до диапазона [a; b]

Continue the program that generates pseudorandom real numbers in the range from a to b (inclusive).
The integers a and b (a < b) are read from the input stream. 
The values are formed by reducing the initial range of values [0; RAND_MAX] to the range [a; b]*/

#include <stdio.h>
#include <stdlib.h>
#define RAND_MAX 32767

int main(void)
{
    int a, b;
    double  aa, bb, c, d, e, f, g, h, i, j;
    scanf("%d %d", &a, &b);

    // здесь продолжайте программу
    aa = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    bb = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    c = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    d = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    e = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    f = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    g = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    h = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    i = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    j = ((double)rand() / (double)RAND_MAX) * (b - a) + a;
    
    printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",aa, bb, c, d, e, f, g, h, i, j);

    return 0;
}