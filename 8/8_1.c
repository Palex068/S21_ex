/*
Создать структуру student, с переменными имя и оценка, количество студентов указывается вводом.

Ввод

3
Andrey
15
Sergey
20
Anton
10

Вывести всех студентов через запятую у кого балл выше среднего

Anton, Sergey
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct st_struct {
        char name[256];
        int rate;
    };

    struct st_struct *students;

    int n;

    if (scanf("%d", &n) == 1 && n > 0) {
        students = malloc(sizeof(struct st_struct) * n);

        for (int i = 0; i < n; i++) {
            scanf("%256s %d", students[i].name, &students[i].rate);
        }

        int avg = 0;
        for (int i = 0; i < n; i++) {
            avg += students[i].rate;
        }
        avg /= n;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (students[i].rate > avg) {
                printf("%s%s", counter++ ? "," : "", students[i].name);
            }
        }
        free(students);
    } else {
        printf("n/a");
    }
}