#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    int x, y;
} Point;

// Функция сравнения для сортировки по x-координате
int compare_x(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->x - p2->x);
}

// Функция сравнения для сортировки по y-координате
int compare_y(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->y - p2->y);
}

// Функция нахождения медианы по x-координате (вертикальная медиана)
int find_vertical_median(Point* points, int n) {
    qsort(points, n, sizeof(Point), compare_x);
    return points[n / 2].x;
}

// Функция нахождения медианы по y-координате (горизонтальная медиана)
int find_horizontal_median(Point* points, int n) {
    qsort(points, n, sizeof(Point), compare_y);
    return points[n / 2].y;
}

// Тестирование функции
int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    Point points[] = { {2, 4}, {3, 1}, {6, 5}, {5, 4},{10, 1}};
    int n = sizeof(points) / sizeof(points[0]);

    int vertical_median = find_vertical_median(points, n);
    int horizontal_median = find_horizontal_median(points, n);

    printf("Вертикальная медиана: x = %d\n", vertical_median);
    printf("Горизонтальная медиана: y = %d\n", horizontal_median);

    return 0;
}