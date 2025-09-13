/*Продолжите программу. Необходимо проверить, что биты 3 и 5 переменной bits включены (установлены в 1). 
Если это так, то выведите в консоль значение переменной bits 
в виде целого десятичного числа, иначе целое число -1.

Continue the program. It is necessary to check that bits 3 and 5 of the bits variable are enabled (set to 1). 
If this is the case, output the value of the bits variable
to the console as an integer decimal number, otherwise the integer -1. */

#include <stdio.h>

int main(void)
{
    unsigned char bits, mask;
    scanf("%hhu", &bits);
    mask = 40;

    if((bits & mask) == mask){
        printf("%d",bits);
    }else{
        printf("-1");
    }

    return 0;
}