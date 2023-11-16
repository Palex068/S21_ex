
/*
Найти и удалить последнее вхождение подстроки
То есть даются 2 строки:
This is mytext
my
Вывод должен был быть
This is text
пока нет
*/

#include <stdio.h>
#include <string.h>
    int
    main() {
    char str1[100];
    char str2[100];

    char new[100];
    fgets(str1, 100, stdin);
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