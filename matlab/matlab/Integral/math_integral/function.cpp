#include "function.h"

double Integral::Function::function_integr(double x)const {
	switch (type) {
    case 0: return (2 * x + 1) * pow(M_E, -x); break;
    case 1: return sin(x) + cos(x); break;
    case 2: return pow(x, 4) - pow(x, 2) + 4; break;
    case 3: return pow((2 * pow(x, 3) + 1), 4) * pow(x, 2); break;
    case 4: return pow((1 + sin(x)), 3) * cos(x) * x; break;
    case 5: return (x + 3) / (pow(x, 2) - 5 * x + 6); break;
    case 6: return 3 / pow(x, 2); break;
    case 7: return pow(x, 2) * log(x); break;
    case 8: {parser p; return p.PARS(fun, x); break; }
    default: break;
    }
}

double Integral::Function::answer_integr()const {
	switch (type) {
    case 0: return -(2 * b + 3) * pow(M_E, -b) - (-(2 * a + 3) * pow(M_E, -a)); break;
    case 1: return (-cos(b) + sin(b)) - (-cos(a) + sin(a)); break;
    case 2: return pow(b, 5) / 5 - pow(b, 3) / 3 + 4 * b - (pow(a, 5) / 5 - pow(a, 3) / 3 + 4 * a); break;
    case 3: return pow((2 * pow(b, 3) + 1), 5) - (pow((2 * pow(a, 3) + 1), 5)); break;
    case 4: return pow((1 + sin(b)), 4) / 4 - (pow((1 + sin(a)), 4) / 4); break;
    case 5: return -5 / (b - 2) + 6 / (b - 3) - (-5 / (a - 2) + 6 / (a - 3)); break;
    case 6: return -3 / b - (-3 / a); break;
    case 7: return pow(b, 3) / 3 * log(b) - pow(b, 3) / 9 - (pow(a, 3) / 3 * log(a) - pow(a, 3) / 9); break;
    case 8: {parser p; return p.PARS(integral, a, b); break; }
    default: break;
    }
}

double** const Integral::Function::answer_grafic(const double tay){
    clear_data();
    n = ceil(drop_trash((b - a) / tay)) + 1; // Точки между a и b + сами a и b
    create_mass_dots();

    // Рассчитываем точку на границе a
    x = a;
    y = function_integr(x);
    write_coordin(0);

    // Рассчитываем точки между границами (после выполнения цикла x всегда будет слева от b)
    for (int i = 1; i < n - 1; i++) {
        x += tay;
        y = function_integr(x);
        write_coordin(i);
    }

    // Корректировка шага на границе с b
    {
        const double tay_b = b - x;  // Считаем сколько нехватает до b
        x += tay_b;                  // прыгаем на b
        y = function_integr(x);      // и считаем игрек на b
        write_coordin(n - 1);
    }

    return dots;
}