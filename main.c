#include <stdio.h>
#include <malloc.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector vector_create(size_t capacity){
    if (malloc(sizeof(int) * capacity) == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector){malloc(sizeof(int) * capacity), 0, capacity};
}

int vector_output(vector v){
    for (int i = 0; i < v.size; ++i) {
        printf("%d ", v.data[i]);
    }
}

void vector_reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
    } else {

        int *newData = realloc(v->data, newCapacity * sizeof(int));

        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        } else {
            if (newCapacity <= v->size)
                v->size = newCapacity;

            v->data = newData;
            v->capacity = newCapacity;
        }
    }
}

void vector_pushBack(vector *v, int x){
    if(v->capacity == 0)
        vector_reserve(v, 1);
    else if (v->size == v->capacity)
        vector_reserve(v, v->capacity * 2);

    v->data[v->size++] = x;
}

int min(int a, int b) {
    return a < b ? a : b;
}

#define nRows 4 // размеры решетки (Ввести вручную)
#define nCols 5

void best_trajectory(int x, int y) {
    int cost[nRows][nCols] = {
            {10, 13, 15, 17, 22},
            {99, 9, 11, 15, 19},
            {6, 7, 9, 12, 13},
            {4, 5, 8, 9, 11},
            // Ввести вручную
    };

    int step_price[nRows][nCols];
    // заполняем первую строку и первый столбец
    step_price[nRows - 1][0] = cost[nRows - 1][0]; // Ввести вручную
    for (int i = nRows - 2; i >= 0; i--) {
        step_price[i][0] = step_price[i+1][0] + cost[i][0];
    }
    for (int j = 1; j < nCols; j++) {
        step_price[nRows - 1][j] = step_price[nRows - 1][j-1] + cost[nRows -
                                                                     1][j];
    }
    // заполняем массив step_price
    for (int i = nRows - 2; i >= 0; i--) {
        for (int j = 1; j < nCols; j++) {
            step_price[i][j] = cost[i][j] + min(step_price[i+1][j],
                                                step_price[i][j-1]);
        }
    }


    vector trajectory = vector_create(nRows + nCols - 2);

    int cols = 0, rows = nRows - 1;

    while (cols != x && rows != nRows - 1 - y) {
        if(step_price[cols + 1][rows] > step_price[cols][rows - 1]){
            vector_pushBack(&trajectory, 1);
            rows--;
        } else {
            vector_pushBack(&trajectory, 0);
            cols++;
        }
    }

    while (cols != x){
        vector_pushBack(&trajectory, 0);
        cols++;
    }

    while (rows != nRows - 1 - y){
        vector_pushBack(&trajectory, 1);
        rows--;
    }

    printf("\nMin cost to reach point (%d, %d) is: %d\n", x, y, step_price[nRows-1- y][x]);

    printf("\nThe best trajectory \n");

    vector_output(trajectory);
}


int main() {
    int x, y;
    printf("Enter the coordinates x and y: \n");
    scanf("%d %d", &x, &y);

    best_trajectory(x, y);

    return 0;
}

