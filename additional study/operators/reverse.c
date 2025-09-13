/*Требуется развернуть четырехзначное число

You need to expand a four-digit number */

#include <stdio.h>

int main()
{
    int value;
    
    scanf("%d", &value);
    
    int a = value % 10;
    int b = (value / 10) % 10;
    int c = (value / 100) % 10;
    int d = value / 1000;
    
    printf("%d %d %d %d", a, b, c, d);

}