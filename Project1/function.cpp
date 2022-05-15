#include "math/diff.h"

// ����������� u' � �� - f(x,u)
double test_function(double x, double y, int fun) {
	switch (fun) {
	case 1: return (-x * x - x * y + y) / x; break;
	case 2: break;// ��� ������������
	}
}


// �������� �������� �� - u(x)
double answer(double x, int fun, const double c) {
	switch (fun) {
	case 1: return c * pow(M_E, -x) * x - x; break;
	case 2: break; // ��� ������������
	}
}

// ��������� ��������� ��������� �� - c
const double answer_const(double x0, double y0, int fun) {
	switch (fun) {
	case 1: return (y0 + x0) / (pow(M_E, -x0) * x0); break;
	case 2: break;// ��� ������������
	}
}