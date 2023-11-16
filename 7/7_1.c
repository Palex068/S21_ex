/*
Убрать лишние пробелы из строки ввода String, заменить большие пробелы на маленькие
Примеры

1    2    3    4    5

Вывод

1 2 3 4 5
*/

#include <stdio.h>
#include <string.h>
int main() {
    char string[100];
    char new[100];
    fgets(string, 100, stdin);
    int j = 0;
    for (int i = 0; i < (int)strlen(string); i++) {
        if (string[i] == ' ') {
            if (string[i + 1] == ' ' || j == 0 || string[i + 1] == '\0') {
                continue;
            }
        }
        new[j] = string[i];
        j++;
    }
    new[j - 1] = '\0';
    printf("%s", new);
}