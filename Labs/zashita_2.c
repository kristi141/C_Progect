#include <stdio.h>

int F2(char s) {
    if (s >= '0' && s <= '9') {
        return s - '0'; 
    } else {
        return -1; 
    }
}

int main() {
    char input;
    printf("Введите символ: ");
    scanf(" %c", &input); 

    int result = F2(input);

    if (result != -1) {
        printf("Числовое значение символа '%c': %d\n", input, result);
    } else {
        printf("Символ '%c' не является цифрой.\n", input);
    }

    return 0;
}
