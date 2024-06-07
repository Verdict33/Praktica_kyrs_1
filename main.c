#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct matrix3D {
    int ***values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
    int nDepth; // глубина
} matrix3D;

matrix3D getMemMatrix3D(int nRows, int nCols, int nDepth) {
    int ***values = (int ***) malloc(sizeof(int **) * nDepth);
    for (int i = 0; i < nDepth; i++) {
        values[i] = (int **) malloc(sizeof(int *) * nRows);
        for (int j = 0; j < nRows; j++) {
            values[i][j] = (int *) malloc(sizeof(int) * nCols);
        }
    }
    return (matrix3D) {values, nRows, nCols, nDepth};
}

void freeMemMatrix3D(matrix3D *m) {
    for (int i = 0; i < m->nDepth; i++) {
        for (int j = 0; j < m->nRows; j++) {
            free(m->values[i][j]);
        }
        free(m->values[i]);
    }
    free(m->values);
    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
    m->nDepth = 0;
}

void inputMatrix3D(matrix3D *m) {
    for (int i = 0; i < m->nDepth; i++) {
        for (int j = 0; j < m->nRows; j++) {
            for (int k = 0; k < m->nCols; k++) {
                scanf("%d", &(m->values[i][j][k]));
            }
        }
    }
}

int count_unique_numbers(matrix3D m) {
    int unique_count = 0;
    int num_found[1000] = {0}; // 1000 поставлена с запасом

    for (int i = 0; i < m.nDepth; i++) {
        for (int j = 0; j < m.nRows; j++) {
            for (int k = 0; k < m.nCols; k++) {

                int number = m.values[i][j][k];

                if (!num_found[number]) {
                    unique_count++;
                    num_found[number] = 1;
                }
            }
        }
    }

    return unique_count;
}

void test() {
    //Тест все числа уникальны
    matrix3D m1 = getMemMatrix3D(3, 3, 3);
    int values1[3][3][3] = {
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
            {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}
    };

    // Заполнение матрицы
    for (int i = 0; i < m1.nDepth; i++) {
        for (int j = 0; j < m1.nRows; j++) {
            for (int k = 0; k < m1.nCols; k++) {
                m1.values[i][j][k] = values1[i][j][k];
            }
        }
    }

    int unique_count1 = count_unique_numbers(m1);
    assert(unique_count1 == 27);

    freeMemMatrix3D(&m1);

    // Тест не все числа уникальны
    matrix3D m2 = getMemMatrix3D(3, 3, 3);
    int values2[3][3][3] = {
            {{1, 1, 3}, {4, 5, 6}, {7, 8, 9}},
            {{10, 11, 12}, {13, 14, 15}, {16, 15, 18}},
            {{19, 20, 21}, {22, 20, 24}, {25, 26, 27}}
    };

    // Заполнение матрицы
    for (int i = 0; i < m2.nDepth; i++) {
        for (int j = 0; j < m2.nRows; j++) {
            for (int k = 0; k < m2.nCols; k++) {
                m2.values[i][j][k] = values2[i][j][k];
            }
        }
    }

    int unique_count2 = count_unique_numbers(m2);
    assert(unique_count2 == 24);

    freeMemMatrix3D(&m2);

    // Тест все числа одинаковые
    matrix3D m3 = getMemMatrix3D(3, 3, 3);
    int values3[3][3][3] = {
            {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
            {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
            {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}
    };

    // Заполнение матрицы
    for (int i = 0; i < m3.nDepth; i++) {
        for (int j = 0; j < m3.nRows; j++) {
            for (int k = 0; k < m3.nCols; k++) {
                m3.values[i][j][k] = values3[i][j][k];
            }
        }
    }

    int unique_count3 = count_unique_numbers(m3);
    assert(unique_count3 == 1);

    freeMemMatrix3D(&m3);


}
int main() {

    test();

    int nRows, nCols, nDepth;

    printf("Enter number of rows: ");
    scanf("%d", &nRows);
    printf("Enter number of columns: ");
    scanf("%d", &nCols);
    printf("Enter number of depths: ");
    scanf("%d", &nDepth);

    matrix3D m = getMemMatrix3D(nRows, nCols, nDepth);

    printf("Enter the elements of the matrix:\n");
    inputMatrix3D(&m);

    int unique_count = count_unique_numbers(m);
    printf("Number of unique numbers: %d\n", unique_count);

    freeMemMatrix3D(&m);

    return 0;
}
