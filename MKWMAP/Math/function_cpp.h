#pragma once
#define _USE_MATH_DEFINES
#include <math.h> // �� �������� ���� ������������ cmath �� � ��� _USE_MATH_DEFINES �� �����

double test_function(double x, int num) {
	switch (num) {
	case 1: return (2 * x + 1) * pow(M_E, -x); break;
	case 2: break;// ��� ������������
	}
}

double answer(double a, double b, int num) {
	switch (num) {
	case 1: return -(2 * b + 3) * pow(M_E, -b) - (-(2 * a + 3) * pow(M_E, -a)); break;
	case 2: break; // ��� ������������
	}
}