/*Задание:
for (n=a, s=0; n!=0; n=n/10)
      { k=n%10; s=s+k;} 

Программа считает сумму цифр в числе.
В данном примере сумма 12345 равна 15, что и выводит программа.	  

The program counts the sum of digits in a number.
In this example, the sum of 12345 is 15, which is what the program outputs.*/

#include <stdio.h>

int sumOfNumber(){
  int a;
	int s = 0;
	
	printf("Введите число :\n");
	scanf("%d", &a);

for (int n = a; n != 0; n = n/10){
	int k = n % 10;
	s = s + k;
} 
	printf("Сумма цифр: %d ", s);
}

int main() {

sumOfNumber();

return 0;
}