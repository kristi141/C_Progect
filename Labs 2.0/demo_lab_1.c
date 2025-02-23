#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>

#define MAX_LENGTH 256  // Максимальная длина входной строки
#define MAX_WORDS 100   // Максимальное количество слов в строке

// Функция находит самое длинное слово в строке и возвращает указатель на него
wchar_t* longestWord(wchar_t *str) {
    wchar_t *longest = NULL, *word = NULL;
    int maxLength = 0, length = 0;

    while (*str) {
        if (iswalpha(*str)) {
            if (!word) word = str; // Начало слова
            length++;
        } else {
            if (word && length > maxLength) {
                maxLength = length;
                longest = word;
            }
            word = NULL;
            length = 0;
        }
        str++;
    }

    // Проверяем последнее слово в строке
    if (word && length > maxLength) {
        longest = word;
    }

    return longest;
}

// Функция сортировки слов по убыванию их длины и формирования выходной строки
void sortWordsByLength(wchar_t *input, wchar_t *output) {
    wchar_t *words[MAX_WORDS]; // Массив указателей на слова
    int lengths[MAX_WORDS]; // Длины слов
    int count = 0;
    wchar_t *p = input;

    // Разбираем строку на слова
    while (*p) {
        while (*p && !iswalpha(*p)) p++; // Пропускаем не буквы
        if (*p) {
            words[count] = p; // Запоминаем начало слова
            lengths[count] = 0;
            while (*p && iswalpha(*p)) {
                lengths[count]++;
                p++;
            }
            count++;
        }
    }

    // Сортируем слова по убыванию длины (пузырьковая сортировка)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (lengths[j] < lengths[j + 1]) {
                // Обмен указателей
                wchar_t *tempWord = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tempWord;
                
                // Обмен длин
                int tempLength = lengths[j];
                lengths[j] = lengths[j + 1];
                lengths[j + 1] = tempLength;
            }
        }
    }

    // Формируем выходную строку
    wchar_t *out_p = output;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < lengths[i]; j++) {
            *out_p++ = words[i][j];
        }
        *out_p++ = L' ';
    }
    
    if (out_p != output) out_p--; // Убираем последний пробел
    *out_p = L'\0'; // Завершаем строку
}

// Тестирование функций
int main() {
    setlocale(LC_ALL, ""); // Устанавливаем локаль для поддержки Unicode

    wchar_t input[MAX_LENGTH];
    wchar_t output[MAX_LENGTH];

    // Ввод строки пользователем
    wprintf(L"Введите строку: ");
    fgetws(input, MAX_LENGTH, stdin);

    // Удаляем возможный символ новой строки
    input[wcscspn(input, L"\n")] = L'\0';

    // Находим самое длинное слово
    wchar_t *longest = longestWord(input);
    if (longest) {
        wprintf(L"Самое длинное слово: ");
        while (*longest && iswalpha(*longest)) {
            putwchar(*longest++);
        }
        wprintf(L"\n");
    }

    // Сортируем слова по длине
    sortWordsByLength(input, output);
    wprintf(L"Отсортированные слова: %ls\n", output);

    return 0;
}
