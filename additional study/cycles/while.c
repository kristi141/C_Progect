/*Напишите программу, которая читает из входного потока натуральное число n (целое, положительное), 
которое содержит от 2-х и более цифр. Используя цикл while, вычислить сумму цифр числа n. 
Результат вывести в консоль в виде одного целого числа.

Write a program that reads from the input stream a natural number n (positive integer)
that contains 2 or more digits. Using the while loop, calculate the sum of the digits of the number n.
Output the result to the console as a single integer.*/

#include <stdio.h>

int main()
{
    int n;
    int S = 0;
    
    scanf("%d ", &n);
    
    while(n > 0){
        S += n % 10;
        n /= 10;
    }
        

 printf("%d ", S); 
}