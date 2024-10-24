#include <stdio.h>
#include <stdbool.h>


int main() {
	int x;

	scanf_s("%d", &x);

	if (x == 5 || x == 60) { // || или && и 
		printf("Yes\n");
	}
	else if (x > 100 && x == 100) {
		printf("Not found!\n");
	}
	else {
		printf("No\n");
	}

	bool isHasCar = true;

	if (isHasCar) { //if(isHasCar == true)
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	
	return 0;

}