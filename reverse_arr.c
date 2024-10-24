#include <stdio.h>

int main() {
	 int arr[100001];
	 int num, i = 0;
	

	while (scanf_s("%d", &num)) {
		arr[i] = num;
		i++;
	
	}

	for (int j = i - 1; j >= 0; j--) {
		printf("%d ",arr[j]);
		if (num == "a") {
			break;
		}
	}

	return 0;

}