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