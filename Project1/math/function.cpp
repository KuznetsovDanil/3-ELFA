#include "function.h"

// ����������� u' � �� - f(x,u)
double Function::function_diff()const {
    switch (type) {
    case 0: return (-x*x-x*y+y)/x; break;
    case 1: break;// ...
    }
}


// �������� �� - u(x)
double Function::answer()const {
    switch (type) {
    case 0: return c * pow(M_E, -x) * x - x; break;
    case 1: break; // ...
    }
}

// ��������� ��������� �� - c
const double Function::answer_const()const {
    switch (type) {
    case 0: return (u0 + x0) / (pow(M_E, -x0) * x0); break;
    case 1: break; // ...
    }
}

// ���������� ����� ��������� �� - u(x)
double**const Function::answer_grafic(const double tay) {
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
    x = b; /*// ���� �� �� ����� �� ������� b, �� ������ �� ������� */
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
        // ����� ������ (����� �������) //
        //////////////////////////////////

        if (x < a)      return euler_before(tay);
        else if (x > b) return euler_after(tay);
        else            return euler_inside(tay);
        break;
    default: return nullptr;
    }

}