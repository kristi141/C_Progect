#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Функция для нахождения самого первого (по алфавиту) слова в строке
const char* FindFirstWord(const char* str, int* WordLength) {
    const char* FirstWordStart = NULL;
    int FirstWordLen = 0;

    while (*str) {
        if (!isalpha((unsigned char)*str)) {
            str++;
            continue;
        }

        const char* CurrentWordStart = str;
        int CurrentWordLen = 0;
        while (isalpha((unsigned char)*str)) {
            str++;
            CurrentWordLen++;
        }

        if (!FirstWordStart || (strncmp(CurrentWordStart, FirstWordStart, (CurrentWordLen < FirstWordLen) ? CurrentWordLen : FirstWordLen) < 0) ||
            (strncmp(CurrentWordStart, FirstWordStart, (CurrentWordLen < FirstWordLen) ? CurrentWordLen : FirstWordLen) == 0 && CurrentWordLen < FirstWordLen)) {
            FirstWordStart = CurrentWordStart;
            FirstWordLen = CurrentWordLen;
        }
    }

    *WordLength = FirstWordLen;
    return FirstWordStart;
}

// Функция для сортировки слов в строке в алфавитном порядке
void SortWords(const char* InputStr, char* OutputStr) {
    char* StrCopy = (char*)malloc(strlen(InputStr) + 1);
    strcpy(StrCopy, InputStr);
    char* CurrentOutputPtr = OutputStr;

    while (1) {
        int WordLength;
        const char* FirstWordStart = FindFirstWord(StrCopy, &WordLength);
        if (!FirstWordStart) break;

        strncpy(CurrentOutputPtr, FirstWordStart, WordLength);
        CurrentOutputPtr += WordLength;
        *CurrentOutputPtr++ = ' ';

        char* TempPtr = StrCopy;
        while (*TempPtr) {
            if (TempPtr == FirstWordStart) {
                for (int i = 0; i < WordLength; ++i) *TempPtr++ = ' ';
                break;
            }
            TempPtr++;
        }
    }

    if (CurrentOutputPtr > OutputStr) *(CurrentOutputPtr - 1) = '\0';
    else *CurrentOutputPtr = '\0';
    free(StrCopy);
}

int main() {
     
    char InputString[MAX_LENGTH];
    char* OutputString;

    printf("Enter a string of words: ");
    fgets(InputString, MAX_LENGTH, stdin);

    // Remove trailing newline character if present
    size_t len = strlen(InputString);
    if (len > 0 && InputString[len - 1] == '\n') {
        InputString[len - 1] = '\0';
    }

    OutputString = (char*)malloc(strlen(InputString) + 1);

    SortWords(InputString, OutputString);

    printf("Original string: %s\n", InputString);
    printf("Sorted string: %s\n", OutputString);

    free(OutputString);
    return 0;
}