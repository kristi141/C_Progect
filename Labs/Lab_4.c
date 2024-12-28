#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
 
void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
} 
 
void shellSortModified(int arr[], int n) { 
    int step = n; 
 
    while (step > 1) { 
        step /= 2; 
        bool swapped; 
 
        do { 
            swapped = false; 
            for (int i = 0; i < n - step; i++) { 
                if (arr[i] > arr[i + step]) { 
                    int temp = arr[i]; 
                    arr[i] = arr[i + step]; 
                    arr[i + step] = temp; 
                    swapped = true; 
                } 
            } 
        } while (swapped); 
    } 
} 
 
int main() { 
    int n; 
 
    printf("Введите размер массива: \n"); 
    if (scanf("%d", &n) != 1 || n <= 0) { 
        printf("Ошибка ввода размера массива.\n"); 
        return 1; 
    } 
 
    int* arr = (int*)malloc(n * sizeof(int)); 
    if (arr == NULL) { 
        printf("Ошибка выделения памяти.\n"); 
        return 1; 
    } 
 
    printf("Введите элементы массива:\n"); 
    for (int i = 0; i < n; i++) { 
        if (scanf("%d", &arr[i]) != 1) { 
            printf("Ошибка ввода элемента массива.\n"); 
            free(arr); 
            return 1;  
        } 
    } 
    shellSortModified(arr, n); 
 
    printf("Отсортированный массив: \n"); 
    printArray(arr, n); 
 
    free(arr); 
    return 0; 
}