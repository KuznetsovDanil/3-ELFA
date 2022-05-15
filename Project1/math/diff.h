#pragma once

#include <iostream> // удалить при переносе в оконное приложение
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h> // по хорошему надо использовать cmath но с ним _USE_MATH_DEFINES не робит

using namespace std; // удалить при переносе в оконное приложение

double test_function(double, double, int);
void diff_methods(double, double, const int, double, int, int);
const double answer_const(double, double, int);