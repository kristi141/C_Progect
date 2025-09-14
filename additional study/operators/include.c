/*В программу ниже добавьте директивы условной компиляции так, чтобы при наличии макроимени PERIMETR_CALC 
вычислялся и выводился периметр, а при отсутствии макроимени PERIMETR_CALC вычислялась и выводилась площадь.

Add conditional compilation directives to the program below so that if there is a macroname PERIMETR_CALC 
the perimeter was calculated and displayed, and in the absence of the macroname PERIMETR_CALC, the area was calculated and displayed.*/

#include <stdio.h>

#define PERIMETR_CALC

int main(void)
{
    int a, b;
    if(scanf("%d, %d", &a, &b) != 2) {
        printf("Input error.");
        return 0;
    }
#ifndef PERIMETR_CALC
    int res = a * b;
    printf("%d", res);
#else    
    int res = 2 * (a + b);
    printf("%d", res);
#endif
    
    return 0;
}