#include "Difffunction.h"

double Diffur::Function::next_y(const double tay, const int method)const {
    switch (method)
    {
    case EULER:
    {
        return function_diff(x, y);
        break;
    }
    case PREDICTOR_CORRECTOR:
    {
        return function_diff(x + tay / 2, y + tay / 2 * function_diff(x, y));
        break;
    }
    case RUNGE_KUTT_3:
    {
        const double k1 = function_diff(x, y);
        const double k2 = function_diff(x + tay / 2, y + tay / 2 * k1);
        const double k3 = function_diff(x + tay, y - tay * k1 + 2 * tay * k2);
        return (k1 + 4 * k2 + k3) / 6;
        break;
    }
    case RUNGE_KUTT_4:
    {
        const double k1 = function_diff(x, y);
        const double k2 = function_diff(x + tay / 2, y + tay / 2 * k1);
        const double k3 = function_diff(x + tay / 2, y + tay / 2 * k2);
        const double k4 = function_diff(x + tay, y + tay * k3);
        return (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        break;
    }
    default: break;
    }
}

double** const Diffur::Function::before(const double tay, const int method) {
    clear_data();
    n = ceil(diff_drop_trash((b - a) / tay)) + 1; // Точки между a и b + сами a и b
    create_mass_dots();

    /* "Бежим" до левой границы, пока расстояние между x и a не станет меньше шага
                                        (после выполнения цикла очевидно, что x всегда будет СЛЕВА от a) */
    while ((a - x) - tay > 0) {
        x += tay;
        y += tay * next_y(tay, method);
    }

    // Корректировка шага на границе с a
    {
        const double tay_a = a - x;    // Считаем сколько нехватает до a
        x += tay_a;                    // прыгаем на a
        y += tay_a * next_y(tay_a, method);  // и считаем игрек на a
        write_coordin(0);
    }

    /* Высчитываем точки в направлении от a к b
                        (после выполнения цикла очевидно, что x всегда будет СЛЕВА от b,
                                            т.к. мы останавливаемся на (n-2)-й (предпоследней) точке, а она всегда СЛЕВА от b) */
    for (int i = 1; i < n - 1; i++) {
        x += tay;
        y += tay * next_y(tay, method);
        write_coordin(i);
    }

    // Корректировка шага на границе с b
    {
        const double tay_b = b - x;    // Считаем сколько нехватает до b
        x += tay_b;                    // прыгаем на b
        y += tay_b * next_y(tay_b, method);  // и считаем игрек на a
        write_coordin(n - 1);
    }

    null_coordin();
    return dots;
}

double** const Diffur::Function::after(const double tay, const int method) {
    clear_data();
    n = ceil(diff_drop_trash((b - a) / tay)) + 1; // Точки между a и b + сами a и b
    create_mass_dots();

    /* "Бежим" до правой границы, пока расстояние между x и b не станет меньше шага
                                        (после выполнения цикла очевидно, что x всегда будет СПРАВА от b) */
    while ((x - b) - tay > 0) {
        x -= tay;
        y -= tay * next_y(tay, method);
    }

    // Корректировка шага на границе с b
    {
        const double tay_b = x - b;    // Считаем сколько нехватает до b
        x -= tay_b;                    // прыгаем на b
        y -= tay_b * next_y(tay_b, method);  // и считаем игрек на b
        write_coordin(n - 1);
    }

    /* Высчитываем точки в направлении от b к a (пишем их с конца массива)
                        (после выполнения цикла очевидно, что x всегда будет СПРАВА от a,
                                            т.к. мы останавливаемся на 1-й (второй) точке, а она всегда СПРАВА от a) */
    for (int i = (n - 1) - 1; i > 0; i--) {
        x -= tay;
        y -= tay * next_y(tay, method);
        write_coordin(i);
    }

    // Корректировка шага на границе с a
    {
        const double tay_a = x - a;    // Считаем сколько нехватает до a
        x -= tay_a;                    // прыгаем на a
        y -= tay_a * next_y(tay_a, method);  // и считаем игрек на a
        write_coordin(0);
    }

    null_coordin();
    return dots;
}

double** const Diffur::Function::inside(const double tay, const int method) {
    clear_data();
    const int n_a = ceil(diff_drop_trash((x - a) / tay)) + 1; // Количество шагов от нижней границы до x0 + саму точку x0
    const int n_b = ceil(diff_drop_trash((b - x) / tay));     // Количество шагов от верхней границы до x0 (+1 не делаем т.к. x0 учли в n_a)
    n = n_a + n_b;                           // Считаем общее количество точек
    create_mass_dots();
    write_coordin(n_a - 1);                  // Записываем координаты x0

    /* Высчитываем точки в направлении от x0 к a
                        (после выполнения цикла очевидно, что x всегда будет СЛЕВА от b,
                                            т.к. мы останавливаемся на 1-й (второй) точке, а она всегда СПРАВА от a) */
    for (int i = (n_a - 1) - 1; i > 0; i--) {
        x -= tay;
        y -= tay * next_y(tay, method);
        write_coordin(i);
    }

    // Корректировка шага на границе с a
    {
        const double tay_a = x - a;    // Считаем сколько нехватает до a
        x -= tay_a;                    // прыгаем на a
        y -= tay_a * next_y(tay_a, method);  // и считаем игрек на a
        write_coordin(0);
    }

    null_coordin();  // Возвращаемся в точку x0

    /* Высчитываем точки в направлении от x0 к b
                    (после выполнения цикла очевидно, что x всегда будет СПРАВА от a,
                                        т.к. мы останавливаемся на (n-2)-й (предпоследней) точке, а она всегда СЛЕВА от b)*/
    for (int i = (n_a - 1) + 1; i < n-1; i++) {
        x += tay;
        y += tay * next_y(tay, method);
        write_coordin(i);
    }

    // Корректировка шага на границе с b
    {
        const double tay_b = b - x;    // Считаем сколько нехватает до b
        x += tay_b;                    // прыгаем на b
        y += tay_b * next_y(tay_b, method);  // и считаем игрек на b
        write_coordin(n - 1);
    }

    null_coordin();
    return dots;
}