#include <stdio.h>

int is_palindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; 
        }
        start++;
        end--;
    }
    return 1;
}

void reverse_word(char* word) {
    int start = 0;
    int end = 0;

    while (word[end] != '\0') {
        end++;
    }
    end--; 

    while (start < end) {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

void process_string(char* str) {
    int start = 0, end = 0, length = 0;

    while (str[length] != '\0') {
        length++;
    }

    char word[50]; 
    int word_len = 0;  

    while (start < length) {
        end = start;
        while (str[end] != ' ' && str[end] != '\0') {
            end++;
        }

        word_len = 0;
        for (int i = start; i < end; i++) {
            word[word_len++] = str[i];
        }
        word[word_len] = '\0';  

        if (!is_palindrome(str, start, end - 1)) {
            reverse_word(word);
            printf("%s ", word); 
        }

        start = end + 1;  
    }

    printf("\n");
}

int main() {
    char str[200];  

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
        i++;
    }

    printf("Результат: ");
    process_string(str);

    return 0;
}
