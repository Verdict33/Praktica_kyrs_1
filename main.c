#include <stdio.h>

int main() {
    int array[3][3][3] = {
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            {{10, 10, 12}, {13, 14, 15}, {16, 17, 18}},
            {{19, 20, 20}, {22, 23, 24}, {25, 26, 27}}
    };

    int unique_count = 0;
    int num_found[27] = {0}; // Массив для отслеживания найденных чисел

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {

                int number = array[i][j][k];

                // Если число пока не было встречено
                if (!num_found[number - 1]) {
                    unique_count++;
                    num_found[number - 1] = 1; // Отмечаем, что число было встречено
                }
            }
        }
    }

    printf("Number of unique numbers: %d\n", unique_count);

    return 0;
}