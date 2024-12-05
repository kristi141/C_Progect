/*Задание:
for (n=a, s=0; n!=0; n=n/10)
      { k=n%10; s=s+k;} 

Программа считает сумму цифр в числе.
В данном примере сумма 12345 равна 15, что и выводит программа.	  

The program counts the sum of digits in a number.
In this example, the sum of 12345 is 15, which is what the program outputs.*/

#include <stdio.h>

int main() {
	int a = 12345;
	int s = 0;

for (int n = a; n != 0; n = n/10){
	int k = n % 10;
	s = s + k;
} 
	printf("%d ", s);

return 0;
}