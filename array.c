#include <stdio.h>

int main() {
	// одномерный массив
	int arr[5] = { 1,4,6,8,5 }; // [] размер {} сами элементы
	arr[0] = 7; // перезапись элемента 

	printf("%d\n", arr[0]);

	//типа данных string  в с не существует 
	char word[] = {'h','e','l','l','o'};
	char words[] = "Hello world!";

	printf("%s\n",words); // %s как string  %c вывод одного символа

	// двумерный массив 
	int array[3][4] = {   // как матрица 3х4
		{1,2,3,4},
	    {5,6,7,8},
		{9,10,11,12}
	
	};
	array[1][1] = 22;

	printf("%d", array[0][2]);

	return 0;

}