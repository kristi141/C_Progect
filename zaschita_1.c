#include <stdio.h>

void F1(char c[]) {
    int i, j;

    for (i = 0; c[i] != '\0'; i++);

    for (j = 0, i--; i > j; i--, j++) {
        char s = c[i];
        c[i] = c[j];
        c[j] = s;
    }
}

int main() {
    char str[100];  
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);  

    int len = 0;
    while (str[len] != '\0') {
        if (str[len] == '\n') {
            str[len] = '\0';
        }
        len++;
    }

    F1(str);

    printf("Перевёрнутая строка: %s\n", str);

    return 0;
}
