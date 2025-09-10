/* Продолжите программу, которая должна с помощью функции printf() вывести текущее время, 
хранимое в переменных: h - часы; m - минуты; s - секунды в формате шестнадцатеричных чисел 
с выводом префикса 0x: 0xhh:0xmm:0xss

Continue the program, which should print the current time using the printf() function, 
stored in variables: h - hours; m - minutes; s - seconds in hexadecimal format 
with 0x prefix output: 0xhh:0xmm:0xss */

#include <stdio.h>

int main(void)
{
    unsigned char h = 17, m = 45, s = 5;

    printf("%#04x:%#04x:%#04x", h, m, s);

    return 0;
}