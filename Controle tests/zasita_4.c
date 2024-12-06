#include <stdio.h>

 int F8(int a){
 int n,k,s;
 for (n=a, s=0; n!=0; n=n/10)
 { 
     k=n%10; 
     s=s+k;
     
 }
 return s;} 

int main() {
	int a;
	printf("Введите число:\n");
	scanf("%d", &a);
	
	printf("Сумма цифр числа: %d\n", F8(a));

	return 0;
}