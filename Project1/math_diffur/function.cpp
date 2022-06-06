#include "function.h"

// Производная u' в ДУ - f(x,u)
double Diffur::Function::function_diff(const double x, const double y)const {
    switch (type) {
    case 0: return (-x*x-x*y+y)/x; break;
    case 1: break;// ...
    }
}


// Интеграл ДУ - u(x)
double Diffur::Function::answer()const {
    switch (type) {
    case 0: return c * pow(M_E, -x) * x - x; break;
    case 1: break; // ...
    }
}

// Константа Интеграла ДУ - c
const double Diffur::Function::answer_const()const {
    switch (type) {
    case 0: return (u0 + x0) / (pow(M_E, -x0) * x0); break;
    case 1: break; // ...
    }
}

// Вычисление точек интеграла ДУ - u(x)
double**const Diffur::Function::answer_grafic(const double tay) {
    n = ceil(drop_trash((b - a) / tay)) + 1; // Точки между a и b + сами a и b
    create_mass_dots();

    // Рассчитываем точку на границе a
    x = a;
    y = answer();
    write_coordin(0);

    // Рассчитываем точки между границами (после выполнения цикла x всегда будет слева от b)
    for (int i = 1; i < n-1; i++) {
        x += tay;
        y = answer();
        write_coordin(i);
    }

    // Рассчитываем точку на границе b 
    x = b; // Если мы не дошли до границы b, то встаем на границу 
    y = answer();
    write_coordin(n - 1);


    null_coordin();
    return dots;
}

double** const Diffur::Function::diff_methods(const int method, const double tay) {
        if (x < a)      return before(tay, method);
        else if (x > b) return after(tay, method);
        else            return inside(tay, method);
}