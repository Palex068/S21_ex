
/*
Найти и удалить последнее вхождение подстроки
То есть даются 2 строки:
This is mytext
my
Вывод должен был быть
This is text
ВНИМАНИЕ КОД ОТРАБАТЫВАЕТ ПЕРВОЕ ВХОЖДЕНИЕ!!!
*/

#include <stdio.h>
#include <string.h>
int main() {
    char str1[100];
    char str2[100];

    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0;
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;

    char *pos = strstr(str1, str2);
    if (pos != NULL) {
        memmove(pos, pos + strlen(str2), strlen(pos + strlen(str2)) + 1);
    }

    printf("%s", str1);
    return 0;
}