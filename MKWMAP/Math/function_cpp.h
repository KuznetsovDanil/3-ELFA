#pragma once
#define _USE_MATH_DEFINES
#include <math.h> // по хорошему надо использовать cmath но с ним _USE_MATH_DEFINES не робит

double test_function(double x, int num) {
	switch (num) {
	case 1: return (2 * x + 1) * pow(M_E, -x); break;
	case 2: break;// для тестировщика
	}
}

double answer(double a, double b, int num) {
	switch (num) {
	case 1: return -(2 * b + 3) * pow(M_E, -b) - (-(2 * a + 3) * pow(M_E, -a)); break;
	case 2: break; // для тестировщика
	}
}