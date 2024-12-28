#include <stdio.h>
#include <stdlib.h>
#define _INT_MAX 2147483647

// Функция для сравнения элементов (для qsort)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Функция для слияния n отсортированных частей          
void mergeSort(int* arr, int n, int size, int* partSizes) {
    int totalSize = 0;
    for (int i = 0; i < n; i++) {
        totalSize += partSizes[i];
    }

    int* indices = (int*)calloc(n, sizeof(int)); // Индексы для каждой части
    int* result = (int*)malloc(totalSize * sizeof(int)); // Массив результата
    int resultIndex = 0;

    while (resultIndex < totalSize) {
        int minVal = _INT_MAX;
        int minPart = -1;

        // Найти минимальный элемент среди всех частей
        for (int i = 0; i < n; i++) {
            if (indices[i] < partSizes[i]) { // Если в части есть элементы
                int partStart = (i == 0) ? 0 : partSizes[i - 1];
                if (arr[partStart + indices[i]] < minVal) {
                    minVal = arr[partStart + indices[i]];
                    minPart = i;
                }
            }
        }

        // Добавить минимальный элемент в результат
        result[resultIndex++] = minVal;
        indices[minPart]++;
    }

    // Скопировать результат в исходный массив
    for (int i = 0; i < totalSize; i++) {
        arr[i] = result[i];
    }

    free(indices);
    free(result);
}

void sortAndMerge(int* arr, int size, int n) {
    int partSize = size / n;
    int* partSizes = (int*)malloc(n * sizeof(int));

    // Разделение массива на части и сортировка
    for (int i = 0; i < n; i++) {
        int start = i * partSize;
        int end = (i == n - 1) ? size : start + partSize;
        partSizes[i] = end - start;
        qsort(arr + start, end - start, sizeof(int), compare);
    }

    // Однократное слияние
    mergeSort(arr, n, size, partSizes);

    free(partSizes);
}

// Тестирование
int main() {
    int size, n;

    // Ввод размера массива
    printf("Введите размер массива: \n");
    scanf("%d", &size);

    // Выделение памяти под массив
    int* arr = (int*)malloc(size * sizeof(int));

    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Ввод количества частей
    printf("Введите количество частей для разделения: \n");
    scanf("%d", &n);

    if (n > size) {
        printf("Количество частей не может быть больше размера массива.\n");
        free(arr);
        return 1;
    }

    printf("Исходный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Сортировка и объединение
    sortAndMerge(arr, size, n);

    // Вывод результата
    printf("Отсортированный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}
