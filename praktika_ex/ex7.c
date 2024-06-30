#include <stdio.h>
#include <windows.h>

// Функция для проверки, является ли число строго возрастающей последовательностью
int isIncreasing(int number) {
    int prev_digit = 10; // Поскольку цифры меньше 10, начинаем с 10

    while (number > 0) {
        int current_digit = number % 10;

        if (current_digit >= prev_digit)
            return 0;

        prev_digit = current_digit;
        number /= 10;
    }
    return 1;
}

// Функция для проверки, является ли число строго убывающей последовательностью
int isDecreasing(int number) {
    int prev_digit = -1; // Поскольку цифры больше -1, начинаем с -1

    while (number > 0) {
        int current_digit = number % 10;

        if (current_digit <= prev_digit)
            return 0;

        prev_digit = current_digit;
        number /= 10;
    }
    return 1;
}

int main() {

    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    int n;
    printf("Введите число n:\n");
    scanf("%d", &n);

    printf("Числа с необходимой последовательностью цифр:\n");
    for (int i = 1; i <= n; i++) {
        if (isIncreasing(i) || isDecreasing(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}