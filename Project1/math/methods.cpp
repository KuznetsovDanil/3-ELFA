#include "function.h"

double** const Function::euler_before(const double tay) {
    clear_data();
    n = ceil(drop_trash((b - a) / tay)) + 1; // Точки между a и b + сами a и b
    create_mass_dots();

    /* "Бежим" до левой границы, пока расстояние между x и a не станет меньше шага
                                        (после выполнения цикла очевидно, что x всегда будет СЛЕВА от a) */
    while ((a - x) - tay > 0) {
        x += tay;
        y += tay * function_diff();
    }

    // Корректировка шага на границе с a
    {
        const double tay_a = a - x;    // Считаем сколько нехватает до a
        x += tay_a;                    // прыгаем на a
        y += tay_a * function_diff();  // и считаем игрек на a
        write_coordin(0);
    }

    /* Высчитываем точки в направлении от a к b
                        (после выполнения цикла очевидно, что x всегда будет СЛЕВА от b,
                                            т.к. мы останавливаемся на (n-2)-й (предпоследней) точке, а она всегда СЛЕВА от b) */
    for (int i = 1; i < n - 1; i++) {
        x += tay;
        y += tay * function_diff();
        write_coordin(i);
    }

    // Корректировка шага на границе с b
    {
        const double tay_b = b - x;    // Считаем сколько нехватает до b
        x += tay_b;                    // прыгаем на b
        y += tay_b * function_diff();  // и считаем игрек на a
        write_coordin(n - 1);
    }

    null_coordin();
    return dots;
}

double** const Function::euler_after(const double tay) {
    clear_data();
    n = ceil(drop_trash((b - a) / tay)) + 1; // Точки между a и b + сами a и b
    create_mass_dots();

    /* "Бежим" до правой границы, пока расстояние между x и b не станет меньше шага
                                        (после выполнения цикла очевидно, что x всегда будет СПРАВА от b) */
    while ((x - b) - tay > 0) {
        x -= tay;
        y -= tay * function_diff();
    }

    // Корректировка шага на границе с b
    {
        const double tay_b = x - b;    // Считаем сколько нехватает до b
        x -= tay_b;                    // прыгаем на b
        y -= tay_b * function_diff();  // и считаем игрек на b
        write_coordin(n - 1);
    }

    /* Высчитываем точки в направлении от b к a (пишем их с конца массива)
                        (после выполнения цикла очевидно, что x всегда будет СПРАВА от a,
                                            т.к. мы останавливаемся на 1-й (второй) точке, а она всегда СПРАВА от a) */
    for (int i = (n - 1) - 1; i > 0; i--) {
        x -= tay;
        y -= tay * function_diff();
        write_coordin(i);
    }

    // Корректировка шага на границе с a
    {
        const double tay_a = x - a;    // Считаем сколько нехватает до a
        x -= tay_a;                    // прыгаем на a
        y -= tay_a * function_diff();  // и считаем игрек на a
        write_coordin(0);
    }

    null_coordin();
    return dots;
}
#include <iostream>
double** const Function::euler_inside(const double tay) {
    clear_data();
    const int n_a = ceil(drop_trash((x - a) / tay)) + 1; // Количество шагов от нижней границы до x0 + саму точку x0
    const int n_b = ceil(drop_trash((b - x) / tay));     // Количество шагов от верхней границы до x0 (+1 не делаем т.к. x0 учли в n_a)
    n = n_a + n_b;                           // Считаем общее количество точек
    create_mass_dots();
    write_coordin(n_a - 1);                  // Записываем координаты x0
    std::cout << n_a << "\t" << n_b << "\t" << n << "\n";
    /* Высчитываем точки в направлении от x0 к a
                        (после выполнения цикла очевидно, что x всегда будет СЛЕВА от b,
                                            т.к. мы останавливаемся на 1-й (второй) точке, а она всегда СПРАВА от a) */
    for (int i = (n_a - 1) - 1; i > 0; i--) {
        x -= tay;
        y -= tay * function_diff();
        write_coordin(i);
    }

    // Корректировка шага на границе с a
    {
        const double tay_a = x - a;    // Считаем сколько нехватает до a
        x -= tay_a;                    // прыгаем на a
        y -= tay_a * function_diff();  // и считаем игрек на a
        write_coordin(0);
    }

    null_coordin();  // Возвращаемся в точку x0

    /* Высчитываем точки в направлении от x0 к b
                    (после выполнения цикла очевидно, что x всегда будет СПРАВА от a,
                                        т.к. мы останавливаемся на (n-2)-й (предпоследней) точке, а она всегда СЛЕВА от b)*/
    for (int i = (n_a - 1) + 1; i < n-1; i++) {
        x += tay;
        y += tay * function_diff();
        write_coordin(i);
    }

    // Корректировка шага на границе с b
    {
        const double tay_b = b - x;    // Считаем сколько нехватает до b
        x += tay_b;                    // прыгаем на b
        y += tay_b * function_diff();  // и считаем игрек на b
        write_coordin(n - 1);
    }

    null_coordin();
    return dots;
}