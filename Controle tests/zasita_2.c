#include <stdio.h>

int F4(int a) {
	int n;
	for ( n = 2; n < a; n++)
	{
		if (a % n == 0) { 
			break; 
		}
	}
	if (n == a) { 
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

	if (F4(a)) {
		printf("не четное число\n");
	}
	else {
		printf("четное число\n");
	}

	return 0;
}