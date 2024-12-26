#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void removeSubstring(char* str, int start, int length) {
    if (str == NULL  start < 0  length <= 0  strlen(str) < start  strlen(str) < start + length)
    {
        return;
    }
    size_t strLen = strlen(str);
    memmove(str + start, str + start + length, strLen - start - length + 1);
}

int main() {
    char str[50];
    fgets(str, 50, stdin);
    // fflush(stdin); // очищаем поток ввода
    //puts(str);
     bool foundBrackets = true;

     while(foundBrackets)
     {
        int k = 0;
        int best_bracket = -1, last_open_bracket = 0, best_open = -1, best_close = -1;
        foundBrackets = false;
        
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '{') {
                k++;
                last_open_bracket = i;
            }
            else if (str[i] == '}') {
                if (k > 0) {
                    if (k > best_bracket) {
                        best_bracket = k;
                        best_open = last_open_bracket;
                        best_close = i;
                        foundBrackets = true;
                    }
                    k--;
                }
            }
         }
        if (best_open != -1 && best_close != -1) {
            printf("Символы внутри скобок: ");
            for (int i = best_open + 1; i < best_close; i++) {
                 printf("%c", str[i]);
            }
            printf("\n");
             int lengthToRemove = best_close - best_open + 1;
            removeSubstring(str, best_open, lengthToRemove);
             printf("Строка без скобок: %s\n", str);
        }  else {
           if(!foundBrackets)
           {
            printf("Скобки не найдены или некорректно расположены\n");
           }
           
        }
     }

    return 0;
}