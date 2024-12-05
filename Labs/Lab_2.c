/*В данной программе мы считаем ряд. Подключаем стандартную библиотеку stdio.h и math.h, для функции fabs() и asin(),
 которая считает значение числа с плавающей запятой.
Программа вычисляет значения функции arcsin(x) с использованием разложения в ряд и сравнивает результаты с точным значением.
Перед главной функцией main находится функция sumOfRows в которой происходят вычисления суммы ряда для арксинуса. 
Данная функция принимает три переменные 
х – главное значение для которого мы ищем арксинус, 
eps – значение эпсилон, 
necessaryIterations – переменная которая хранит количество итераций которые были необходимы для того чтобы дойти до эпсилон. 
Далее внутри объявлены переменные sum – хранит сумму членов ряда, 
temp – временная переменная для хранения текущего члена ряда, 
iteration – счетчик итераций. 
Дальше находится цикл while в котором происходят вычисления суммы ряда. Цикл будет продолжаться до тех пор пока значение больше эпсилон. 
Внутри цикла мы начинаем добавлять текущий член ряда к общей сумме т увеличиваем значения счетчика на 1. 
Далее обновляем значение temp и ищем по формуле следующий член ряда.
Потом полученное количество итераций записываем в переменную necessaryIterations для функции main. Возвращаем сумму ряда. 
Объявляем переменные в главной функции: х – значение для которого выполняется вычисление (от 0.1 до 0.9), 
resultSum – результат вычислений суммы, 
ArcsinValue – значение арксинуса, 
eps – значение эпсилон , 
necessaryIterations – количество итераций которые были необходимы для вычисления суммы.
Далее идет цикл for в котором перебираются значения х от 0.1 до 0.9. 
Внутри цикла вызываем функцию суммы ряда в которой и происходят вычисления членов ряда и их суммы. 
Далее присваиваем переменной ArcsinValue значение для конкретного х и считаем разницу между встроенной функцией и написанной.
После выводим значения.  
Программа выводит сначала значение х, далее сумму ряда а после значение из встроенной функции. 
После этого выводится разница в вычислениях и количество потребовавшихся итераций.

In this program, we count a number. We connect the standard library stdio.h and math.h, for the fabs() and asin() functions,
which counts the value of a floating-point number.
The program calculates the values of the arcsin(x) function using a series expansion and compares the results with the exact value.
In front of the main function is the sumOfRows function, in which the sum of the series for the arcsine is calculated. 
This function takes three variables
x – the main value for which we are looking for the arcsine,
eps – the value of epsilon, 
necessaryIterations is a variable that stores the number of iterations that were needed to reach epsilon. 
Further, the variables sum are declared inside – it stores the sum of the members of the series, 
temp is a temporary variable for storing the current member of the series,
iteration is an iteration counter. 
Next is the while loop in which the sum of the series is calculated. The cycle will continue until the value is greater than epsilon. 
Inside the loop, we start adding the current term of the series to the total sum and increase the counter values by 1. 
Next, we update the temp value and use the formula to search for the next member of the series.
Then we write the resulting number of iterations to the necessaryIterations variable for the main function. We return the amount of the row. 
Declaring variables in the main function: x is the value for which the calculation is performed (from 0.1 to 0.9),
resultSum is the result of calculating the sum, 
ArcsinValue – the value of the arcsin, 
eps is the epsilon value , 
necessaryIterations – the number of iterations that were needed to calculate the sum.
Next comes the for loop in which the values of x from 0.1 to 0.9 are iterated over. 
Inside the loop, we call the sum function of the series in which the members of the series and their sum are calculated. 
Next, we assign the ArcsinValue variable a value for a specific x and consider the difference between the built-in function and the written one.
After that, we output the values.  
The program outputs first the value of x, then the sum of the series, and then the value from the built-in function. 
After that, the difference in calculations and the number of iterations required are displayed. */

#include <stdio.h>
#include <math.h>

double sumOfRows(double x, double eps, int* necessaryIterations) {
    double sum = 0.0;
    double temp = x;
    int iteration = 0;

    while (fabs(temp) > eps) {
        sum += temp;
        iteration++;
        temp *= (x * x) * ((2 * iteration - 1.0) / (2 * iteration)) * ((2 * iteration - 1.0) / (2 * iteration + 1));
    }

    *necessaryIterations = iteration;
    return sum;
}

int main() {
    double x, resultSum, ArcsinValue, differenseValue, eps = 1e-6;
    int necessaryIterations;


    for (x = 0.1; x <= 0.9; x += 0.1) {
        resultSum = sumOfRows(x, eps, &necessaryIterations);
        ArcsinValue = asin(x);
        differenseValue = fabs(resultSum - ArcsinValue);


        printf("Шаг : %0.1lf \n", x);
        printf("Сумма : %0.4lf\n", resultSum);
        printf("Значение arcsin(x) : %0.4lf\n", ArcsinValue);
        printf("Разница : %0.6lf\n", differenseValue);
        printf("Необходимое количество итераций : %d\n\n", necessaryIterations);

    }

    return 0;
}
