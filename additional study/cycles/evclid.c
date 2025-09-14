/*  Напишите программу, которая вычисляет наибольший общий делитель (НОД) двух натуральных чисел a, b 
по алгоритму Евклида. Алгоритм реализуется по следующей схеме:

Шаг 1. Читаем из входного потока два натуральных числа a, b, записанных в одну строчку через пробел.
Шаг 2. Определяем наименьшее из двух чисел a, b
Шаг 3. Делаем цикл: пока меньшее число больше 0
Шаг 4.         большему числу присваиваем целый остаток от деления на меньшее число; (используется операция %)
Шаг 5.         большее число становится меньшим, а меньшее - большим
Шаг 6. Большее число выводим в консоль в виде одного числа.

Write a program that calculates the greatest common divisor (GCD) of two natural numbers a, b
using the Euclidean algorithm. The algorithm is implemented according to the following scheme:

Step 1. We read from the input stream two natural numbers a, b, written in one line separated by a space.
Step 2. Determine the smallest of the two numbers a, b
Step 3. We make a cycle: while the smaller number is greater than 0
Step 4. Assign the whole remainder of the division by the smaller number to the larger number; (the % operation is used)
Step 5.         A larger number becomes smaller, and a smaller number becomes larger.
Step 6. Output the larger number to the console as a single number.*/

#include <stdio.h>

int main()
{
    int a, b, min, max;
    
    scanf("%d %d", &a, &b);
    
    if(a < b){
        min = a;
        max = b;
    }else{
        min = b;
        max = a;
    }
    
    while(min > 0){
        int ost = max % min;
        
        max = min;
        min = ost;
    }
    
    printf("%d",max);
    

        return 0;
}