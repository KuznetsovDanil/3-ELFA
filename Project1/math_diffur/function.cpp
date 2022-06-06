#include "function.h"

// ����������� u' � �� - f(x,u)
double Diffur::Function::function_diff(const double x, const double y)const {
    switch (type) {
    case 0: return (-x*x-x*y+y)/x; break;
    case 1: break;// ...
    }
}


// �������� �� - u(x)
double Diffur::Function::answer()const {
    switch (type) {
    case 0: return c * pow(M_E, -x) * x - x; break;
    case 1: break; // ...
    }
}

// ��������� ��������� �� - c
const double Diffur::Function::answer_const()const {
    switch (type) {
    case 0: return (u0 + x0) / (pow(M_E, -x0) * x0); break;
    case 1: break; // ...
    }
}

// ���������� ����� ��������� �� - u(x)
double**const Diffur::Function::answer_grafic(const double tay) {
    n = ceil(drop_trash((b - a) / tay)) + 1; // ����� ����� a � b + ���� a � b
    create_mass_dots();

    // ������������ ����� �� ������� a
    x = a;
    y = answer();
    write_coordin(0);

    // ������������ ����� ����� ��������� (����� ���������� ����� x ������ ����� ����� �� b)
    for (int i = 1; i < n-1; i++) {
        x += tay;
        y = answer();
        write_coordin(i);
    }

    // ������������ ����� �� ������� b 
    x = b; // ���� �� �� ����� �� ������� b, �� ������ �� ������� 
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