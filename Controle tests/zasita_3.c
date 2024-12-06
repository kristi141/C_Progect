#include <stdio.h>

void F11() {
	int a, n, k, s;

	for (a = 10; a < 30000; a++) {
		for (n = a, s = 0; n != 0; n = n / 10){
			k = n % 10; 
			s = s + k;
		}

		if (a == s * s * s) {
			printf("%d\n", a);
		}
	}
}

int main() {
	F11();
	
	return 0;
}