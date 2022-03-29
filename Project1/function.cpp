#include "function.h"

double test_function(double x, int c) {
	switch (c) {
	case 1: return (2 * x + 1) * pow(M_E, -x); break;
	case 2: break;// для тестировщика
	}
}

double answer(double a, double b, int c) {
	switch (c) {
	case 1: return -(2 * b + 3) * pow(M_E, -b) - (-(2 * a + 3) * pow(M_E, -a)); break;
	case 2: break; // для тестировщика
	}
}