# Разбор возможных задач на экзамен

## Содержание

+ [Динамические массивы](#динамические-массивы)


## Динамические массивы

### 5.1 Скалярное произведение

Написать программу, производящую скалярное умножение двух векторов n-мерного пространства. <br>
Через входной поток ввода stdin задается целое положительное число n, обозначающее размерность пространства, затем следуют 2 строки: n целочисленных координат первого вектора и n целочисленных координат второго, разделенные пробелом.<br>
Результат вычислений вывести на стандартный поток вывода stdout.<br>
В конце ответа не должно быть переноса на новую строку. Проверить на валидность введенные данные. В случае любой ошибки вывести "n/a"<br>

```c
#include <stdio.h>
#include <stdlib.h>

void freeArrayAB(int *A, int *B, int size);
void freeArray(int *A, int size);
int getNumbers(int *nums, int size);

int main() {
    int N;
    scanf("%d", &N);
    int *A, *B;
    A = malloc(sizeof(int) * N);
    B = malloc(sizeof(int) * N);
    if (A == NULL || B == NULL) {
        printf("n/a");
        return 0;
    }
    if (!getNumbers(A, N) && !getNumbers(B, N)) {
        printf("n/a");
        freeArrayAB(A, B, N);
        return 0;
    }
    int mul = 0;  // mul =summ
    for (int j = 0; j < N; j++) {
        mul += A[j] * B[j];
    }
    printf("%d", mul);

    freeArrayAB(A, B, N);
}

void freeArrayAB(int *A, int *B, int size) {
    freeArray(A, size);
    freeArray(B, size);
}

void freeArray(int *array, int size) {
    if (array == NULL) return;
    free(array);
}

int getNumbers(int *nums, int size) {  // getnumder==input
    for (int i = 0; i < size; i++) {
        char ch;
        int cnt = scanf("%d%c", &nums[i], &ch);
        if (cnt != 2 || (ch != ' ' && ch != '\n') || (ch == '\n' && (i + 1 < size)) ||
            (ch != '\n' && (i + 1 == size)))
            return 0;
    }
    return 1;
}
```

[Содержание](#содержание)

### 5.3 Вывод последовательности

Написать программуб производящую вывод элементов последовательности $X = (X_1, X_2, X_3, ... , X_n)$ в следующем порядке $X_1, X_n, X_2, X_{n - 1} ...$. <br>
Последовательность $X$ состоит из целых неотрицательных чисел и задается на стандартном потоке stdin, элементы последовательности разделены между собой пробелами, концом последовательности является число -1, которое не является ее элементом.<br>
В конце ответа не должно быть переноса на новую строку.<br>
Проверить на валидность введенные данные.<br>
В случае любой ошибки выводить "n/a".<br>

Input | Output
---|---
1 2 3 -1 | 1 3 2
1 2 3 4 5 6 -1 | 1 6 2 5 3 4
-1 | 

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i = 1, size = 1, step = 0, check = 0;
    int *arr;
    char end;
    arr = (int*)malloc(sizeof(int));
    if (scanf("%d%c", &arr[i - 1], &end) && (end == '\n' || end == ' ')) check = 1;
    printf("%d\n", check);
    while (check) {
        arr = (int*)realloc(arr, (i + 1) * sizeof(int));
        if (scanf("%d%c", &arr[i], &end) && (end == ' ' || end == '\n')) {
            check++;
        } else {
            check = 0; break;
        }
        if (arr[i] == -1 || check != size + 1) break;
        i++;
        size++;
    }
    printf("%d %d\n", check, size);
    if (check) {
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                printf(i == size - 1 ? "%d" : "%d ", arr[i - step]);
                step++;
            } else {
                printf(i == size - 1 ? "%d" : "%d ", arr[size - step]);
            }
        }
    } else {
        printf("n/a");
    }
    free(arr);
    return 0;
}
```

[Содержание](#содержание)

### 5.4 Устранение повторений

Input | Output
---|---
1 1 2 2 3 -1 | 1 2 3
1 2 1 3 1 4 | 1 2 3 4
-1 | 

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE_INCREMENT 1

int main(void) {
    int x, i = 0, count = 0, n = SIZE_INCREMENT;
    int *data = (int*) malloc(n * sizeof(int));
    while (x != -1) {
        if (scanf("%d", &x) == 1) {
            if (x != -1) {
                if (count >= n) {
                    n += SIZE_INCREMENT;
                    data = (int*) realloc(data, n * sizeof(int));
                }
                data[i] = x;
                i++;
                count++;
            }
        } else {
            printf("n/a");
            break;
        }
    }
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    for (int j = 0; j < n; j++) {
        for (int a = 0; a < 10; a++) {
            if (data[j] == arr[a]) {
                arr[a] = -1;
                printf("%d ", data[j]);
            }
        }
    }
    return 0;
}
```

[Содержание](#содержание)

### 5.5 Реверс последовательности

Написать программу, осуществляющую вывод на стандартный поток stdout через пробел в обратном порядке элементов последовательности, состоящей из целых неотрицательных чисел.<br>
Последовательность задается на стандартный поток ввода stdin, элементы последовательности разделены между собой пробелами, концом последовательности является число -1, которое обозначает конец последовательности и не является ее элементом.<br>
В конце ответа не должно быть переноса на новую строку.<br>
Проверить на валидность введенные данные.<br>
В случае любой ошибки выводить "n/a".<br>

Input | Output
---|---
1 2 3 4 5 -1 | 5 4 3 2 1
1 1 1 2 2 2 -1 | 2 2 2 1 1 1
-1 | 

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array, index = 0;
    array = (int *)malloc(index + 1 * sizeof(int));

    if (array != NULL) {
        while (1) {
            scanf("%d", &array[index]);
            if (array[index] == -1) {
                break;
            }
            index++;
            array = (int *)realloc(array, index + 1 * sizeof(int));
        }

        for (int i = index - 1; i >= 0; i--) {
            printf("%d%s", array[i], i == 0 ? "" : " ");
        }
        free(array);
    } else {
        printf("n/a");
    }

    return 0;
}
```

[Содержание](#содержание)


## Матрицы

### 6.1 Умножение квадратных матриц

Написать программу, производящую умножение двух квадратных матриц $A$ и $B$ размера $N$.

Input | Output
---|---
2<br/>1 2<br/>3 4<br/>5 6<br/>7 8 | 19 22<br/>43 50

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    char term;

    if (scanf("%d%c", &N, &term) != 2 || term != '\n') {
        printf("n/a");
        return 1;
    }

    int A[N][N];
    int B[N][N];
    int C[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                printf("n/a");
                return 1;
            }
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &B[i][j]) != 1) {
                printf("n/a");
                return 1;
            }
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) C[i][j] += A[i][k] * B[k][j];
        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < N - 1) {
                printf("%d ", C[i][j]);
            } else {
                printf("%d", C[i][j]);
                printf("\n");
            }
        }
    }
}
```

[Содержание](#содержание)

