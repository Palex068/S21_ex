/*
Транспонировать матрицу
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {
    int n, m;

    if (scanf("%d %d", &n, &m) == 2 && n > 0 && m > 0) {
        int matrix[N][N];
        int counter = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = counter++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d%s", matrix[i][j], j == m - 1 ? "" : " ");
            }
            printf("%s", i == n - 1 ? "\n\n" : "\n");
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                printf("%d%s", matrix[n - i - 1][j], i == n - 1 ? "" : " ");
            }
            printf("%s", j == m - 1 ? "" : "\n");
        }
    } else {
        printf("n/a");
    }
}