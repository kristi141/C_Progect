#include <stdio.h>

void F3(char c[]) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] >= 'a' && c[i] <= 'z') {
            c[i] += 'A' - 'a'; 
        }
    }
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

    F3(str);

    printf("Результат: %s\n", str);

    return 0;
}
