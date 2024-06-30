#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Функция  для  умножения  двух  многочленов  и  возврата  результата
void multiply_polynomials(int* A, int n, int* B, int m, int* result) {
    for (int i = 0; i <= n + m; i++) {
        result[i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            result[i + j] += A[i] * B[j];
        }
    }
}

// Функция  для  нахождения  композиции  многочленов  P(Q(x))
void compose_polynomials(int* P, int n, int* Q, int m, int* result) {

    int* temp = (int*)calloc((m * n + 1), sizeof(int));
    int* powQ = (int*)calloc((m * n + 1), sizeof(int));

    powQ[0] = 1; // Q^0 = 1

    for (int i = 0; i <= n; i++) {
        int* current_term = (int*)calloc((m * n + 1), sizeof(int));

        for (int j = 0; j <= m * i; j++) {
            current_term[j] = P[i] * powQ[j];
        }

        for (int k = 0; k <= m * n; k++) {
            result[k] += current_term[k];
        }

        if (i < n) {
            multiply_polynomials(powQ, m * i, Q, m, temp);

            for (int k = 0; k <= m * (i + 1); k++) {
                powQ[k] = temp[k];
            }
        }
        free(current_term);
    }

    free(temp);
    free(powQ);
}

// Функция  для  вывода  многочлена
void print_polynomial(int* poly, int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("%d ", poly[i]);
    }
    printf("\n");
}

// Если  разные  степени  многочлена
int test_1() {
    int P[] = {1, 2, 3}; // Многочлен  P(x) = 1 + 2x + 3x^2
    int Q[] = {4, 5};    // Многочлен  Q(x) = 4 + 5x

    int n = 2; // Степень  многочлена  P(x)
    int m = 1; // Степень  многочлена  Q(x)

    int result_degree = n * m;
    int* result = (int*)calloc(result_degree + 1, sizeof(int));

    compose_polynomials(P, n, Q, m, result);

    printf("Коэффициенты  композиции  P_n(Q_m(x)): ");
    print_polynomial(result, result_degree);

    free(result);
}

// Если одинаковые степени многочлена
int test_2() {
    int P[] = {3, 2, 3}; // Многочлен  P(x) = 3 + 2x + 3x^2
    int Q[] = {1,3, 5};    // Многочлен  Q(x) = 1 + 3x + 5x^2

    int n = 2; // Степень  многочлена  P(x)
    int m = 2; // Степень  многочлена  Q(x)

    int result_degree = n * m;
    int* result = (int*)calloc(result_degree + 1, sizeof(int));

    compose_polynomials(P, n, Q, m, result);

    printf("Коэффициенты  композиции  P_n(Q_m(x)): ");
    print_polynomial(result, result_degree);

    free(result);
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    test_1();
    test_2();
}