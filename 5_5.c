/*The task -
    Неограниченный ввод целых чисел.Записать в обратном порядке введенные числа.The last symbol is newline.
*/

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