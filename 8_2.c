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

Вывести всех студентов осортировав их по балам

Anton, Sergey
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    struct stud {
        char name[256];
        int mark;
    };

    int n;

    // Проверяем ввод
    if (scanf("%d", &n) == 1 && n > 0) {
        // Создаем массив
        struct stud *students;

        students = malloc(n * sizeof(struct stud));
        // Заполняем массив структур данными
        for (int i = 0; i < n; i++) {
            scanf("%256s %d", students[i].name, &students[i].mark);
        }

        // Сортируем массив структур
        int tmp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (students[i].mark > students[j].mark) {
                    tmp = students[i].mark;
                    students[i].mark = students[j].mark;
                    students[j].mark = tmp;
                }
            }
        }

        // Выводим отсортированный массив структур
        for (int i = 0; i < n; i++) {
            printf("%s %d%s", students[i].name, students[i].mark, i == n - 1 ? "" : "\n");
        }
    }
}