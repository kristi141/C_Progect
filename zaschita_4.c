#include <stdio.h>

int F4(char c[]) {
    int i, old, nw;
    for (i = 0, old = 0, nw = 0; c[i] != '\0'; i++) {
        if (c[i] == ' ') {
            old = 0; 
        } else {
            if (old == 0) {
                nw++;  
            }
            old = 1; 
        }
        if (c[i] == '\0') break; 
    }
    return nw;
}

int main() {
    char str[200];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    }

    int word_count = F4(str);

    printf("Количество слов в строке: %d\n", word_count);

    return 0;
}
