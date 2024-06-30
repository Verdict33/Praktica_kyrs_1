#include <stdio.h>

int round_up_time () {
    // объявляются и вводятся переменные
    int h, m, s;
    printf("Input hour minutes second:\n");
    scanf("%d %d %d", &h, &m, &s);

    // Округление до минут
    if(s >= 30){
        if(m < 59)
            m++;
        else{
            m = 0;
            h++;
        }
    }

    // Проверка, что часы не перешли на следующий день
    if(h >= 24)
        h = 0;

    // Вывод на экран часы и минуты
    printf("%d hour %d minutes\n", h, m);

    // Округление до часов
    if(m >= 30)
        if(h < 23)
            h++;
        else
            h = 0;

    // Вывод на экран часов
    printf("%d hour", h);
}