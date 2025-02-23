#include <stdio.h>

// Функция для поиска всех трехзначных чисел Армстронга
int find_armstrong_numbers(int results[], int max_size) {
    int count = 0; // Счетчик найденных чисел Армстронга

    // Перебор всех трехзначных чисел
    for (int num = 100; num < 1000; num++) {
        int sum = 0, temp = num;

        // Разбиение числа на цифры и вычисление суммы кубов цифр
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit * digit; // Куб цифры через умножение
            temp /= 10;
        }

        // Проверяем, является ли число числом Армстронга
        if (sum == num) {
            if (count < max_size) { // Убедимся, что не превышаем размер массива
                results[count++] = num;
            } else {
                break; // Если массив переполнен, прекращаем
            }
        }
    }

    return count; // Возвращаем количество найденных чисел
}

int main() {
    // Тест 1: Максимальный размер массива - 10
    int results1[10];
    int count1 = find_armstrong_numbers(results1, 10);
    printf("Тест 1 (max_size = 10): Найдено %d чисел Армстронга:\n", count1);
    for (int i = 0; i < count1; i++) {
        printf("%d ", results1[i]);
    }
    printf("\n");

    // Тест 2: Максимальный размер массива - 2
    int results2[2];
    int count2 = find_armstrong_numbers(results2, 2);
    printf("Тест 2 (max_size = 2): Найдено %d чисел Армстронга:\n", count2);
    for (int i = 0; i < count2; i++) {
        printf("%d ", results2[i]);
    }
    printf("\n");

    // Тест 3: Максимальный размер массива - 5
    int results3[5];
    int count3 = find_armstrong_numbers(results3, 5);
    printf("Тест 3 (max_size = 5): Найдено %d чисел Армстронга:\n", count3);
    for (int i = 0; i < count3; i++) {
        printf("%d ", results3[i]);
    }
    printf("\n");

    return 0;
}
