/*Последовательность Фибоначчи образуется так: первые два числа равны 1 и 1, а 
каждый следующий равен сумме двух предыдущих. То есть, имеем последовательность вида: 1, 1, 2, 3, 5, 8, 13, ... 
Вычислите последовательность Фибоначчи длиной n (n - натуральное число, читаемое из входного потока). 
Выведите числа полученной последовательности в одну строку через пробел.

The Fibonacci sequence is formed as follows: the first two numbers are 1 and 1, and
each subsequent number is equal to the sum of the previous two. That is, we have a sequence of the form: 1, 1, 2, 3, 5, 8, 13, ...
Calculate the Fibonacci sequence of length n (n is a natural number read from the input stream). 
Print the numbers of the resulting sequence in one line separated by a space.*/

#include <stdio.h>

int main()
{
    int n;
    int fib = 1, i = 1, j = 1;
    
    if(scanf("%d ", &n) != 0){
        printf("1 ");
    }
    
    while(n > 1){
       printf("%d ",fib);
        
       fib = i + j ;
        
        i = j;
        j = fib;

        n--;
        
    }
        

  return 0;
}