/* Напишите программу, которая считывает из входного потока три целых положительных числа (длины сторон треугольника), 
записанных в одну строчку через пробел. С помощью вложенных тернарных операций необходимо проверить, 
что эти числа могут описывать длины сторон треугольника. Выведите в консоль строку "yes", если числа образуют 
длины сторон треугольника, и "no" в противном случае.

Критерий проверки: у любого треугольника длина каждой стороны всегда должна быть меньше суммы двух других.

Write a program that reads from the input stream three positive integers (the lengths of the sides of a triangle)
written in one line separated by a space. Using nested ternary operations, it is necessary to verify
that these numbers can describe the lengths of the sides of a triangle. Print the string "yes" to the console if the numbers form
the lengths of the sides of the triangle, and "no" otherwise.

Verification criterion: for any triangle, the length of each side must always be less than the sum of the other two.  */

#include <stdio.h>

int main()
{
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    if(a >= 1 && b >= 1 && c >= 1){
    
    int res = (a >= b + c) ? "no" : (b >= a + c ? "no" : (c >= a + b ? "no" : "yes"));
    
    printf("%s", res);
    }
    
    return 0;

}