#include <stdio.h>
#include <ctype.h>
#include <windows.h>

// Функция для проверки, нужен ли пробел после символа
int is_space_required_after(char c) {
    return c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?' || c == ')' || c == ']' || c == '}';
}

// Функция для проверки, нужен ли пробел перед символом
int is_space_required_before(char c) {
    return c == '(' || c == '[' || c == '{';
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    char text[] = "Ваш, \tтекст.Для[проверки]..\n.Концепциц?нет(или!да)";
    int i = 0;
    char prev_char = 0;

    while (text[i]) {
        if (is_space_required_after(prev_char) && isspace(text[i])) {
            // Пропускаем лишние пробелы после знаков пунктуации
            i++;
            continue;
        } else if (is_space_required_before(text[i]) && prev_char != '\n' && prev_char != '\t' && !isspace(prev_char)) {
            // Вставляем пробел перед знаком, если его нет
            printf(" ");
        } else if (is_space_required_after(prev_char))
            // Вставляем пробел после знака, если его нет
            printf(" ");

        // Печать текущего символа
        printf("%c", text[i]);

        // Обновление предыдущего символа
        prev_char = text[i];
        i++;
    }

    return 0;
}