/*Задание:
for (s=0, sn = x, n=2; fabs(sn) > eps; n+=2){ 
    s += sn;
    sn= sn * x *x * (n -1) / (n+1); 
} 

Объяснение кода:
В данной программе мы считаем ряд. Подключаем стандартную библиотеку stdio.h 
и math.h, для функции fabs(), которая считает значение числа с плавающей 
запятой.
Переменные для удобства мы выносим из цикла for. Так же почти все переменные 
имеют тип данных double, так как вычисления, которые будут исполняться далее 
будут дробными.
Переменная s – хранит значение суммы членов ряда, sn – хранит значение 
текущего элемента ряда, x – значение переменной, для которой считается ряд, 
eps – значение эпсилон, n – хранит индекс текущего члена ряда и по условию 
равен двум.
Присваиваем переменной sn значение x, первый член ряда равен x.
Далее в цикле for мы начинаем считать сам ряд. Данный цикл будет продолжаться
 до тех пор, пока член ряда не станет достаточно малым, пока его значение не 
 приблизится к значению эпсилон. К значению n мы на каждой итерации 
 прибавляем 2.
Внутри цикла в переменную s каждую итерацию будет прибавляться значение нового 
члена ряда, эта часть как раз и отвечает за искомую нами сумму. 
В следующей строке мы вычисляем следующий член ряда. Мы берём текущее 
значение, умножаем его на x^2 , умножаем на коэффициент (n - 1) / (n + 1), и 
далее увеличиваем n на 2 и продолжаем находить искомые значения.
Первый член ряда будет равен значению x, то есть 1. Второй и последующие членя 
ряда начинаем искать по формуле в цикле. Далее происходят вычисления: 
2. n = 2  sn = x *  x^2 * (2 - 1) / (2 + 1) = x^3 * 1/3
3. n = 4  sn = x^3 * 1/3 * x^2 * (4 - 1) / (4 + 1) = x^5 * 1/3 * 1/5 = x^5 * 1/5  
4. n = 6  sn = x^5 * 1/5 *  x^2 * (6 - 1) / (6 + 1) = x^7 * 1/5  * 5/7 = x^7 * 1/7 и т.д.
Далее в конце программы мы выводим «Сумма ряда:» и значение суммы элементов ряда. 
Данный код выведет:
 «Сумма ряда: 7.542937»

Task:
for (s=0, sn = x, n=2; fabs(sn) > eps; n+=2){ 
    s += sn;
    sn= sn * x *x * (n -1) / (n+1); 
} 
Code explanation:
In this program, we count a number. We connect the standard library stdio.h
and math.h, for the fabs() function, which counts the value of a
floating-point number.
For convenience, we remove variables from the for loop. Also, almost all variables
have the double data type, since the calculations that will be performed next
will be fractional.
The variable s – stores the value of the sum of the members of the series, sn – stores the value
of the current element of the series, x – the value of the variable for which the series is considered,
eps – the value of epsilon, n – stores the index of the current member of the series and is conditionally
equal to two.
We assign the value x to the variable sn, the first term of the series is equal to x.
Next, in the for loop, we start counting the row itself. This cycle will continue
until the member of the series becomes small enough, until its value
approaches the value of epsilon. We add 2 to the value of n at each iteration
.
Inside the loop, the value of a new member of the series will be added to the variable s each iteration
, this part is exactly responsible for the amount we are looking for. 
In the next line, we calculate the next term of the series. We take the current one 
the value, multiply it by x ^2, multiply by the coefficient (n - 1) / (n + 1), and
then increase n by 2 and continue to find the desired values.
The first term of the series will be equal to the value of x, that is, 1. The second and subsequent members 
we begin to search for a number using the formula in the loop. Then the calculations take place: 
2. n = 2  sn = x *  x^2 * (2 - 1) / (2 + 1) = x^3 * 1/3
3. n = 4  sn = x^3 * 1/3 * x^2 * (4 - 1) / (4 + 1) = x^5 * 1/3 * 1/5 = x^5 * 1/5  
4. n = 6 sn = x^5 * 1/5* x^2 * (6 - 1) / (6 + 1) = x^7 * 1/5 * 5/7 = x^7* 1/7 , etc.
Next, at the end of the program, we output "The sum of the series:" and the value of the sum of the elements of the series. 
This code will output:
"The sum of the series: 7.542937»
*/

#include <stdio.h>
#include <math.h> 

int main() {
    double s = 0.0; 
    double sn;      
    double x = 1.0; 
    double eps = 1e-6;  
    int n = 2;      

    sn = x;  

    for (; fabs(sn) > eps; n += 2) {
        s += sn;  
        sn = sn * x * x * (n - 1) / (n + 1);  
    }

    printf("Сумма ряда: %lf\n", s);  

    return 0;
}