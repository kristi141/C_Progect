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
