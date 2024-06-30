#include <stdio.h>
#include <windows.h>

// Функция  для  проверки,  является  ли  подпоследовательность  арифметической  прогрессией
int arithmetic_progression(int* a, int start, int end) {
    if (end - start < 2)
        return 0;

    int diff = a[start + 1] - a[start];
    for (int i = start + 2; i <= end; i++) {
        if (a[i] - a[i - 1] != diff)
            return 0;
    }

    return 1;
}

// Функция  для  проверки,  является  ли  подпоследовательность  геометрической  прогрессией
int geometric_progression(int* a, int start, int end) {
    if (end - start < 2)
        return 0;
    if (a[start] == 0)
        return 0;

    double ratio = (double)a[start + 1] / a[start];
    for (int i = start + 2; i <= end; i++) {
        if (a[i - 1] == 0 || (double)a[i] / a[i - 1] != ratio)
            return 0;
    }

    return 1;
}

// Функция  для  нахождения  максимальной  длины  подпоследовательности
int find_longest_progression(int* a, int n) {
    int max_length = 2; // Минимальная  длина  прогрессии - 2

    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            if (arithmetic_progression(a, i, j) || geometric_progression(a, i, j)) {
                if (j - i + 1 > max_length) {
                    max_length = j - i + 1;
                }
            }
        }
    }

    return max_length;
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    int n;
    printf("Введите размер массива P(n):\n");
    scanf("%d", &n);
    int P[n];

    printf("Введите элементы массива P(n):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    int longest = find_longest_progression(P, n);

    printf("Длина самой большой прогрессии: %d\n", longest);

    return 0;

}