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
    n = ceil(diff_drop_trash((b - a) / tay)) + 1; // ����� ����� a � b + ���� a � b
    create_mass_dots();

    /* "�����" �� ����� �������, ���� ���������� ����� x � a �� ������ ������ ����
                                        (����� ���������� ����� ��������, ��� x ������ ����� ����� �� a) */
    while ((a - x) - tay > 0) {
        x += tay;
        y += tay * next_y(tay, method);
    }

    // ������������� ���� �� ������� � a
    {
        const double tay_a = a - x;    // ������� ������� ��������� �� a
        x += tay_a;                    // ������� �� a
        y += tay_a * next_y(tay_a, method);  // � ������� ����� �� a
        write_coordin(0);
    }

    /* ����������� ����� � ����������� �� a � b
                        (����� ���������� ����� ��������, ��� x ������ ����� ����� �� b,
                                            �.�. �� ��������������� �� (n-2)-� (�������������) �����, � ��� ������ ����� �� b) */
    for (int i = 1; i < n - 1; i++) {
        x += tay;
        y += tay * next_y(tay, method);
        write_coordin(i);
    }

    // ������������� ���� �� ������� � b
    {
        const double tay_b = b - x;    // ������� ������� ��������� �� b
        x += tay_b;                    // ������� �� b
        y += tay_b * next_y(tay_b, method);  // � ������� ����� �� a
        write_coordin(n - 1);
    }

    null_coordin();
    return dots;
}

double** const Diffur::Function::after(const double tay, const int method) {
    clear_data();
    n = ceil(diff_drop_trash((b - a) / tay)) + 1; // ����� ����� a � b + ���� a � b
    create_mass_dots();

    /* "�����" �� ������ �������, ���� ���������� ����� x � b �� ������ ������ ����
                                        (����� ���������� ����� ��������, ��� x ������ ����� ������ �� b) */
    while ((x - b) - tay > 0) {
        x -= tay;
        y -= tay * next_y(tay, method);
    }

    // ������������� ���� �� ������� � b
    {
        const double tay_b = x - b;    // ������� ������� ��������� �� b
        x -= tay_b;                    // ������� �� b
        y -= tay_b * next_y(tay_b, method);  // � ������� ����� �� b
        write_coordin(n - 1);
    }

    /* ����������� ����� � ����������� �� b � a (����� �� � ����� �������)
                        (����� ���������� ����� ��������, ��� x ������ ����� ������ �� a,
                                            �.�. �� ��������������� �� 1-� (������) �����, � ��� ������ ������ �� a) */
    for (int i = (n - 1) - 1; i > 0; i--) {
        x -= tay;
        y -= tay * next_y(tay, method);
        write_coordin(i);
    }

    // ������������� ���� �� ������� � a
    {
        const double tay_a = x - a;    // ������� ������� ��������� �� a
        x -= tay_a;                    // ������� �� a
        y -= tay_a * next_y(tay_a, method);  // � ������� ����� �� a
        write_coordin(0);
    }

    null_coordin();
    return dots;
}

double** const Diffur::Function::inside(const double tay, const int method) {
    clear_data();
    const int n_a = ceil(diff_drop_trash((x - a) / tay)) + 1; // ���������� ����� �� ������ ������� �� x0 + ���� ����� x0
    const int n_b = ceil(diff_drop_trash((b - x) / tay));     // ���������� ����� �� ������� ������� �� x0 (+1 �� ������ �.�. x0 ���� � n_a)
    n = n_a + n_b;                           // ������� ����� ���������� �����
    create_mass_dots();
    write_coordin(n_a - 1);                  // ���������� ���������� x0

    /* ����������� ����� � ����������� �� x0 � a
                        (����� ���������� ����� ��������, ��� x ������ ����� ����� �� b,
                                            �.�. �� ��������������� �� 1-� (������) �����, � ��� ������ ������ �� a) */
    for (int i = (n_a - 1) - 1; i > 0; i--) {
        x -= tay;
        y -= tay * next_y(tay, method);
        write_coordin(i);
    }

    // ������������� ���� �� ������� � a
    {
        const double tay_a = x - a;    // ������� ������� ��������� �� a
        x -= tay_a;                    // ������� �� a
        y -= tay_a * next_y(tay_a, method);  // � ������� ����� �� a
        write_coordin(0);
    }

    null_coordin();  // ������������ � ����� x0

    /* ����������� ����� � ����������� �� x0 � b
                    (����� ���������� ����� ��������, ��� x ������ ����� ������ �� a,
                                        �.�. �� ��������������� �� (n-2)-� (�������������) �����, � ��� ������ ����� �� b)*/
    for (int i = (n_a - 1) + 1; i < n-1; i++) {
        x += tay;
        y += tay * next_y(tay, method);
        write_coordin(i);
    }

    // ������������� ���� �� ������� � b
    {
        const double tay_b = b - x;    // ������� ������� ��������� �� b
        x += tay_b;                    // ������� �� b
        y += tay_b * next_y(tay_b, method);  // � ������� ����� �� b
        write_coordin(n - 1);
    }

    null_coordin();
    return dots;
}