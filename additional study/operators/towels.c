/*В программе должен быть реализован алгоритм решения следующей задачи. 
Набор полотенец, который стоил s рублей, продается со скидкой m%. 
Сколько рублей стоят два набора полотенец со скидкой? 
Переменные s и m читаются из входного потока, записанные в виде целых чисел одну строчку через пробел. 

The program must implement an algorithm for solving the following problem. 
A set of towels that cost s rubles is sold at a m% discount. How many rubles do two sets of discounted towels cost? 
The variables s and m are read from the input stream, written as integers one line separated by a space..*/

#include <stdio.h>

int main()
{
    double s, m;
    
    scanf("%lf %lf", &s, &m);

    s *= 2;
    s -= s * m / 100.0;
    
    printf("%.2f\n",s);

    return 0;

}