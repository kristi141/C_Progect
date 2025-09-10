/*Продолжите программу, которая должна с помощью функции printf() вывести текущее время, 
хранимое в переменных: h - часы; m - минуты; s - секунды в формате: hh:mm:ss

Continue the program, which should print the current time using the printf() function, 
stored in variables: h - hours; m - minutes; s - seconds in the format: hh:mm:ss */

#include <stdio.h>

int main(void)
{
    unsigned char h = 11, m = 8, s = 1;

    printf("%02u:%02u:%02u", h, m, s);

    return 0;
}