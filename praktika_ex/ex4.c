#include <stdio.h>
#include <windows.h>

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    // Объявление и ввод переменных
    int n;
    printf("Введите размер массива N:\n");
    scanf("%d", &n);
    double X[n], sum = 0;

    // Заполнение начального массива
    printf("Введите элементы массива N:\n");
    for(int i = 0; i < n; i++) {
        scanf("%lf", &X[i]);
    }

    // Вычисление среднего значения и замена элементов
    for(int i = 0; i < n; i++) {
        sum += X[i]; // Добавление текущего элемента к сумме
        X[i] = sum / (i + 1); // Вычисление среднего и замена элемента
    }

    // Вывод измененного массива
    printf("Измененный массив N:\n");
    for(int i = 0; i < n; i++) {
        printf("%.2f ", X[i]);
    }
    printf("\n");

    return 0;
}