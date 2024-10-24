#include <stdio.h>

int main() {
	int array[100001];
	int num;
	int i = 0;
	int normal, reverse;

	scanf_s("%d", &num);

	num *= num;

	while (num > 0) {
		int digit = num % 10;
		array[i] = digit;
		i++;
		num /= 10;
	}

	for (int j = i - 1; j >= 0; j--) {
		printf("%d", array[j]);
		normal = array[j];
	}

	printf("\n");

	for (int k = 0; k < i; k++) {
		printf("%d", array[k]);
		reverse = array[k];
	}

	printf("\n");


	if (normal == reverse) {
		printf("The square of a given number is a palindrome "); //Квадрат данного числа является палиндромом
	}
	else {
		printf("The square of a given number is not a palindrome "); //Квадрат данного числа не является палиндромом
	}

	if (i % 2) {
		printf("and odd number of digits\n");
	}
	else {
		printf("and even number of digits\n");
	}

	return 0;

}