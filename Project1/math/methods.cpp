#include "function.h"

double** const Function::euler_before(const double tay) {
    clear_data();
    n = ceil(drop_trash((b - a) / tay)) + 1; // ����� ����� a � b + ���� a � b
    create_mass_dots();

    /* "�����" �� ����� �������, ���� ���������� ����� x � a �� ������ ������ ����
                                        (����� ���������� ����� ��������, ��� x ������ ����� ����� �� a) */
    while ((a - x) - tay > 0) {
        x += tay;
        y += tay * function_diff();
    }

    // ������������� ���� �� ������� � a
    {
        const double tay_a = a - x;    // ������� ������� ��������� �� a
        x += tay_a;                    // ������� �� a
        y += tay_a * function_diff();  // � ������� ����� �� a
        write_coordin(0);
    }

    /* ����������� ����� � ����������� �� a � b
                        (����� ���������� ����� ��������, ��� x ������ ����� ����� �� b,
                                            �.�. �� ��������������� �� (n-2)-� (�������������) �����, � ��� ������ ����� �� b) */
    for (int i = 1; i < n - 1; i++) {
        x += tay;
        y += tay * function_diff();
        write_coordin(i);
    }

    // ������������� ���� �� ������� � b
    {
        const double tay_b = b - x;    // ������� ������� ��������� �� b
        x += tay_b;                    // ������� �� b
        y += tay_b * function_diff();  // � ������� ����� �� a
        write_coordin(n - 1);
    }

    null_coordin();
    return dots;
}

double** const Function::euler_after(const double tay) {
    clear_data();
    n = ceil(drop_trash((b - a) / tay)) + 1; // ����� ����� a � b + ���� a � b
    create_mass_dots();

    /* "�����" �� ������ �������, ���� ���������� ����� x � b �� ������ ������ ����
                                        (����� ���������� ����� ��������, ��� x ������ ����� ������ �� b) */
    while ((x - b) - tay > 0) {
        x -= tay;
        y -= tay * function_diff();
    }

    // ������������� ���� �� ������� � b
    {
        const double tay_b = x - b;    // ������� ������� ��������� �� b
        x -= tay_b;                    // ������� �� b
        y -= tay_b * function_diff();  // � ������� ����� �� b
        write_coordin(n - 1);
    }

    /* ����������� ����� � ����������� �� b � a (����� �� � ����� �������)
                        (����� ���������� ����� ��������, ��� x ������ ����� ������ �� a,
                                            �.�. �� ��������������� �� 1-� (������) �����, � ��� ������ ������ �� a) */
    for (int i = (n - 1) - 1; i > 0; i--) {
        x -= tay;
        y -= tay * function_diff();
        write_coordin(i);
    }

    // ������������� ���� �� ������� � a
    {
        const double tay_a = x - a;    // ������� ������� ��������� �� a
        x -= tay_a;                    // ������� �� a
        y -= tay_a * function_diff();  // � ������� ����� �� a
        write_coordin(0);
    }

    null_coordin();
    return dots;
}
#include <iostream>
double** const Function::euler_inside(const double tay) {
    clear_data();
    const int n_a = ceil(drop_trash((x - a) / tay)) + 1; // ���������� ����� �� ������ ������� �� x0 + ���� ����� x0
    const int n_b = ceil(drop_trash((b - x) / tay));     // ���������� ����� �� ������� ������� �� x0 (+1 �� ������ �.�. x0 ���� � n_a)
    n = n_a + n_b;                           // ������� ����� ���������� �����
    create_mass_dots();
    write_coordin(n_a - 1);                  // ���������� ���������� x0
    std::cout << n_a << "\t" << n_b << "\t" << n << "\n";
    /* ����������� ����� � ����������� �� x0 � a
                        (����� ���������� ����� ��������, ��� x ������ ����� ����� �� b,
                                            �.�. �� ��������������� �� 1-� (������) �����, � ��� ������ ������ �� a) */
    for (int i = (n_a - 1) - 1; i > 0; i--) {
        x -= tay;
        y -= tay * function_diff();
        write_coordin(i);
    }

    // ������������� ���� �� ������� � a
    {
        const double tay_a = x - a;    // ������� ������� ��������� �� a
        x -= tay_a;                    // ������� �� a
        y -= tay_a * function_diff();  // � ������� ����� �� a
        write_coordin(0);
    }

    null_coordin();  // ������������ � ����� x0

    /* ����������� ����� � ����������� �� x0 � b
                    (����� ���������� ����� ��������, ��� x ������ ����� ������ �� a,
                                        �.�. �� ��������������� �� (n-2)-� (�������������) �����, � ��� ������ ����� �� b)*/
    for (int i = (n_a - 1) + 1; i < n-1; i++) {
        x += tay;
        y += tay * function_diff();
        write_coordin(i);
    }

    // ������������� ���� �� ������� � b
    {
        const double tay_b = b - x;    // ������� ������� ��������� �� b
        x += tay_b;                    // ������� �� b
        y += tay_b * function_diff();  // � ������� ����� �� b
        write_coordin(n - 1);
    }

    null_coordin();
    return dots;
}