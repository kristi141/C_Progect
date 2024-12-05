/*Задание:
for (n=a, s=0; n!=0; n=n/10)
      { k=n%10; s=s*10+k;}
      
Программа выводит число в обратном порядке.
Например при вводе 12345 программа выведет 54321.

The program outputs the number in reverse order.
For example, if you enter 12345, the program will output 54321.*/

#include <stdio.h> 

int reverseNumber(){
      int n, s = 0, k, a;

    printf("Введите число: \n");
    scanf("%d", &a);

    for (n = a; n != 0; n = n / 10) {
        k = n % 10;
        s = s * 10 + k;
    }

    printf("Перевернутое число: %d\n", s);
}

int main() {

reverseNumber();
    return 0;
}
