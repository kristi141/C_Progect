#include <stdio.h>
#include <stdlib.h>   
#include <math.h>     

int **createSpecialArray(const int V[], size_t N, int W)
{
    int **result = malloc(N * sizeof(int *));
    if (!result) return NULL;

    for (size_t i = 0; i < N; ++i) {
        // Подсчитываем количество «близких» элементов 
        size_t count = 0;
        for (size_t j = 0; j < N; ++j)
            if (abs(V[j] - V[i]) <= W)
                ++count;

       //  Выделяем память под (count + 2) целых 
        result[i] = malloc((count + 2) * sizeof(int));
        if (!result[i]) {                        
            for (size_t k = 0; k < i; ++k) free(result[k]);
            free(result);
            return NULL;
        }

        //  Заполняем линейный подмассив
        result[i][0] = V[i];
        result[i][1] = (int)count;
        size_t pos = 2;
        for (size_t j = 0; j < N; ++j)
            if (abs(V[j] - V[i]) <= W)
                result[i][pos++] = V[j];
    }
    return result;
}

int main(void)
{
    const int V[] = {1, 5, 3, 8, 2, 7};
    const size_t N = sizeof(V) / sizeof(V[0]);
    int W = 2;

    int **arr = createSpecialArray(V, N, W);
    if (!arr) {
        perror("malloc");
        return 1;
    }

    //  Вывод результата 
    for (size_t i = 0; i < N; ++i) {
        printf("Базовое значение: %d, Количество близких: %d, Элементы: ",
               arr[i][0], arr[i][1]);
        for (int j = 0; j < arr[i][1]; ++j)
            printf("%d ", arr[i][2 + j]);
        putchar('\n');
    }

    //  Освобождаем всю выделенную память 
    for (size_t i = 0; i < N; ++i) free(arr[i]);
    free(arr);
    return 0;
}
