#include <stdio.h>
#include <stdbool.h>


int main() {
	for (int i = 0; i <= 10;i++) {
		printf("%d\n", i);
	}

	int isHasCar = true;
	int x = 0;
	while (isHasCar) { // будет выполняться до тех пор пока пользователь не введёт 1
		scanf_s("%d", &x);

		if (x == 1) {
			isHasCar = false;
		}
	}

	int i = 0;
	while (i < 10) {
		printf("%d\n", i);
		i++;
	}

	//bool isHasCar = false;  // не запускать
	//do {
	//	printf("yes");  // do выполняется обязательно а потом идёт проверка
	//} while (!isHasCar);


	return 0;

}