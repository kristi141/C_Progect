/*Продолжите программу, которая читает из входного потока два целых числа, записанных в одну строчку через пробел, 
в две целочисленные переменные с некоторыми именами: <имя_переменной_1> и <имя_переменной_2>. 
Затем, с помощью макроопределения MUL_VAR_NAME, используя операцию ##, объявите третью переменную с именем:

mul_<имя_переменной_1>_<имя_переменной_2>

и присвойте ей значение произведения двух исходных переменных. Выведите значение переменной
mul_<имя_переменной_1>_<имя_переменной_2> в консоль в виде одного целого числа.

Continue the program, which reads from the input stream two integers written in one line separated by a space
into two integer variables with some names: <name of the variable_1> and <name of the variable_2>. 
Then, using the macro definition MUL_VAR_NAME, using the ## operation, declare a third variable named:

mul_<variable name_1>_<variable name_2>

and assign it the value of the product of the two original variables. Print the value of the variable
mul_<variable name_1>_<variable name_2> to the console as a single integer.*/

#include <stdio.h>

#define MUL_VAR_NAME(A,B) mul_##A##_##B

int main(void)
{

    int a_1, a_2;
    
    scanf("%d %d", &a_1, &a_2);
    
    int MUL_VAR_NAME(a_1,a_2) = a_1 * a_2;
    
    printf("%d",  MUL_VAR_NAME(a_1,a_2));

    return 0;
}