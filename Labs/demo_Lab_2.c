/*for (s=0, sn = x, n=2; fabs(sn) > eps; n+=2){ 
    s += sn;
    sn= sn * x *x * (n -1) / (n+1); 
} */

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