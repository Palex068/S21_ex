/*
Заполнить матрицу спирально против часовой стрелки
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {
    int num;

    if (scanf("%d", &num) == 1 && num > 0) {
        int matrix[N][N];
        int counter = 1, i = 0, j = 0;

        while (counter != num * num + 1) {
            matrix[i][j] = counter;
            if (i + 1 >= j && i + j < num - 1) {
                i++;
            } else if (i > j && i + j >= num - 1) {
                j++;
            } else if (i <= j && i + j > num - 1) {
                i--;
            } else {
                j--;
            }
            counter++;
        }
        for (i = 0; i < num; i++) {
            for (j = 0; j < num; j++) {
                printf("%d%s", matrix[i][j], j == num - 1 ? "" : " ");
            }
            printf("%s", i == num - 1 ? "" : "\n");
        }
    } else {
        printf("n/a");
    }
}