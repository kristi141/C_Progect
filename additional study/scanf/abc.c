/*Напишите программу, которая считывает из входного потока два целых числа a, b, 
записанных в одну строку через пробел. Поменяйте местами значения переменных a и b так, 
чтобы a принимало значение b, а b принимало значение a. Программу реализовать 
с добавлением еще одной целочисленной переменной. 
Выведите значения переменных a и b в консоль в одну строчку через пробел.

Write a program that reads two integers a, b, from the input stream 
given in one word separated by a space. Swap the values ​​of functions a and b, 
so that a takes on the value of b, and b takes on the value of a. Implement the program 
with the addition of another integer variable. 
You define the values ​​of functions a and b in the console on one line separated by a space. */

#include <stdio.h>

int main()
{
    int a,b,c;
    
    scanf("%d %d", &a, &b);
    
    c = a;
    a = b;
    b = c;
    
    
    printf("%d %d", a , b);
    
    return 0;    
}    