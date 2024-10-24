#include <stdio.h>
#include <stdlib.h>

int main() {
	// %d
	// short  не большие значения от -32т до +32т памяти использует меньше
	// unsigned short от 0 до 64 тыс памяти тоже меньше
	// unsigned int  только положительные значения
	// long в 2 раза больше чем int
	// long long в 2 раза больше чем long

	// %f (%.2f  после запятой будет 2 знака)
	//float a = 4.5f;  в конце ставится f
	// double после точки диапазон больше чем у float
	
	// %Lf
	// long double ещё больше диапазон 

	// %c
	// char sym = '%';  1 символ и только одинарные ковычки 

	// bool a = true; только true false нужно подключать библиотеку <stdbool.h>

	// const нельзя перезаписать верхний регистр название ААА

	int x, y, result; // int  большой диапазон значений 

	scanf_s("%d", &x);
	scanf_s("%d", &y);

	x += 5; // x = x + 5
	y++; // y = y + 1

	result = x + y;

	printf("Result = %d\n", result);  // \n пробел
	printf("%d + %d = %d\n", x, y, result);

	system("pause"); // + stdlib.h вывод с паузой 

	return 0;

}