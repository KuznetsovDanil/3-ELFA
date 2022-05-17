#include "function.h"
//#define _USE_MATH_DEFINES
// #include <math.h>
#include <corecrt_math_defines.h>
#include <cmath>

void Function::out_dot(std::ofstream& out_x, std::ofstream& out_y)const {
	out_x << x << "\n";
	out_y << y << "\n";
}


// Производная u' в ДУ - f(x,u)
double Function::function_diff()const {
	switch (type) {
	case 1: return (-x*x-x*y+y)/x; break;
	case 2: break;// для тестировщика
	}
}


// Интеграл ДУ - u(x)
double Function::answer()const {
	switch (type) {
	case 1: return c * pow(M_E, -x) * x - x; break;
	case 2: break; // для тестировщика
	}
}

// Константа Интеграла ДУ - c
const double Function::answer_const(double x0, double y0, int type)const {
	switch (type) {
	case 1: return (y0 + x0) / (pow(M_E, -x0) * x0); break;
	case 2: break;// для тестировщика
	}
}

// Построение графика интеграла ДУ - u(x)
void Function::answer_grafic(const int n, double tay) {
	std::ofstream out_x("file_x_truth.txt");
	std::ofstream out_y("file_y_truth.txt");
	for (int i = 0; i < n; i++) {
		set_y(answer());
		out_dot(out_x, out_y);
		x += tay;
	}
	out_x.close();
	out_y.close();
	null_coordin();
}