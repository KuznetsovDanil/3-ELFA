#include "function.h"

// Производная u' в ДУ - f(x,u)
double Function::function_diff()const {
    switch (type) {
    case 0: return (-x*x-x*y+y)/x; break;
    case 1: break;// ...
    }
}


// Интеграл ДУ - u(x)
double Function::answer()const {
    switch (type) {
    case 0: return c * pow(M_E, -x) * x - x; break;
    case 1: break; // ...
    }
}

// Константа Интеграла ДУ - c
const double Function::answer_const()const {
    switch (type) {
    case 0: return (u0 + x0) / (pow(M_E, -x0) * x0); break;
    case 1: break; // ...
    }
}

// Вычисление точек интеграла ДУ - u(x)
double**const Function::answer_grafic(const double tay) {
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
    x = b; /*// Если мы не дошли до границы b, то встаем на границу */
    y = answer();
    write_coordin(n - 1);


    null_coordin();
    return dots;
}

double** const Function::diff_methods(const int method, const double tay) {
    switch (method)
    {
    case EULER:
        //////////////////////////////////
        // Метод Эйлера (метод ломаных) //
        //////////////////////////////////

        if (x < a)      return euler_before(tay);
        else if (x > b) return euler_after(tay);
        else            return euler_inside(tay);
        break;
    default: return nullptr;
    }

}