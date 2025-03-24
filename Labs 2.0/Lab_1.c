#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>

#define MAX_LENGTH 100  
#define MAX_WORDS 20 

void findWordAndSort(wchar_t *originString, wchar_t *sortedString) {
    wchar_t *words[MAX_WORDS]; 
    wchar_t *longest = NULL; 
    wchar_t *p = originString;
    
    int lengths[MAX_WORDS]; 
    int count = 0;
    int maxLength = 0;

    while (*p) {
        while (*p && !iswalpha(*p)){
          p++;
        }  
        
        if (*p) {
            words[count] = p; 
            int length = 0;
            
            while (*p && iswalpha(*p)) {
                length++;
                p++;
            }
            
            lengths[count] = length;
            
            if (length > maxLength) {
                maxLength = length;
                longest = words[count];
            }
            
            count++;
        }
    }

    if (count == 0) { 
        *sortedString = L'\0';
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (lengths[j] < lengths[j + 1]) {
                wchar_t *tempWord = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tempWord;

                int tempLength = lengths[j];
                lengths[j] = lengths[j + 1];
                lengths[j + 1] = tempLength;
            }
        }
    }

    wchar_t *pToSorted = sortedString;
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < lengths[i]; j++) {
            *pToSorted++ = words[i][j];
        }
        
        *pToSorted++ = L' ';
    }
    
    *(pToSorted - 1) = L'\0'; 

    wprintf(L"Самое длинное слово: %.*ls\n", maxLength, longest);
}

int main() {
    setlocale(LC_ALL, ""); 

    wchar_t originString[MAX_LENGTH], sortedString[MAX_LENGTH];

    wprintf(L"Введите строку: ");
    fgetws(originString, MAX_LENGTH, stdin);
    originString[wcscspn(originString, L"\n")] = L'\0'; 

    findWordAndSort(originString, sortedString);

    wprintf(L"Отсортированные слова: %ls\n", sortedString);

    return 0;
}
