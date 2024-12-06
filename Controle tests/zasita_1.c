#include <stdio.h>

int F5(int a) {
	int s = 0;
	for ( int n = 2; n < a; n++)
	{
		if (a % n == 0) 
			s++;
	}
	if (s == 0) { 
		return 1; 
	}
	else {
return 0;
	}
	
}

int main() {
	int a;
	printf("Введите число:\n");
	scanf("%d", &a);

	if (F5(a)) {
		printf("простое число\n");
	}
	else {
		printf("составное число\n");
	}

	return 0;
}