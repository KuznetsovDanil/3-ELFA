#pragma once

#include <iostream> // ������� ��� �������� � ������� ����������
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h> // �� �������� ���� ������������ cmath �� � ��� _USE_MATH_DEFINES �� �����

using namespace std; // ������� ��� �������� � ������� ����������

double test_function(double, double, int);
void diff_methods(double, double, const int, double, int, int);
const double answer_const(double, double, int);