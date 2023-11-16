
/*
проверить является ли строка палиндромом (строка должна заканчиваться \n)
входная строка может содержать буквы латинского алфавита и цифры, длина строки до 100 символов
ввод        	| вывод
------------------------
Mam mam         | YES
------------------------
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int is_pol(char string[], int len);

int main() {
    char string[MAX];
    fgets(string, MAX, stdin);
    int len = 0;
    for (int i = 0; i < MAX; i++) {
        if (string[i] == '\n') {
            break;
        }
        len++;
    }

    printf("%s", is_pol(string, len) ? "YES" : "NO");
}

int is_pol(char string[], int len) {
    for (int i = 0; i < len / 2; i++) {
        if (tolower(string[i]) != tolower(string[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}