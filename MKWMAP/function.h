#pragma once
#define _USE_MATH_DEFINES
#include <math.h> // по хорошему надо использовать cmath но с ним _USE_MATH_DEFINES не робит

double test_function(double x, int num) {
	switch (num) {
	case 1: return (2 * x + 1) * pow(M_E, -x); break;
	case 2: return sin(x) + cos(x); break;
	case 3: return pow(x, 4) - pow(x, 2) + 4; break;
	case 4: return pow((2 * pow(x, 3) + 1), 4) * pow(x, 2); break;
	case 5: return pow((1 + sin(x)), 3) * cos(x) * x; break;
	case 6: return (x + 3) / (pow(x, 2) - 5 * x + 6); break;
	case 7: return 3 / pow(x, 2); break;
	case 8: return pow(x, 2)*log(x); break;
	default: break;// для тестировщика
	}
}

double answer(double a, double b, int num) {
	switch (num) {
	case 1: return -(2 * b + 3) * pow(M_E, -b) - (-(2 * a + 3) * pow(M_E, -a)); break;
	case 2: return (-cos(b) + sin(b)) - (-cos(a) + sin(a)); break;
	case 3: return pow(b, 5) / 5 - pow(b, 3) / 3 + 4 * b - (pow(a, 5) / 5 - pow(a, 3) / 3 + 4 * a); break;
	case 4: return pow((2 * pow(b, 3) + 1), 5) - (pow((2 * pow(a, 3) + 1), 5)); break;
	case 5: return pow((1 + sin(b)), 4) / 4 - (pow((1 + sin(a)), 4) / 4); break;
	case 6: return -5 / (b - 2) + 6 / (b - 3) - (-5 / (a - 2) + 6 / (a - 3)); break;
	case 7: return -3 / b - (-3 / a); break;
	case 8: return pow(b,3)/3*log(b)-pow(b, 3)/9 - (pow(a, 3) / 3 * log(a) - pow(a, 3) / 9); break;
	default: break; // для тестировщика
	}
}