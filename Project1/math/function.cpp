#include "function.h"
#define _USE_MATH_DEFINES
#include <math.h> // по хорошему надо использовать cmath но с ним _USE_MATH_DEFINES не робит

void out_dot(Function& fun, std::ofstream& out_x, std::ofstream& out_y) {
	out_x << fun.x << "\n";
	out_y << fun.y << "\n";
}

void out_dot(double x, double y, std::ofstream& out_x, std::ofstream& out_y){
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

void Function::answer_grafic(const int n, double tay) {
	std::ofstream out_x("file_x_i.txt");
	std::ofstream out_y("file_y_i.txt");
	for (int i = 0; i < n; i++) {
		out_dot(x, answer(), out_x, out_y);
		x += tay;
	}
	out_x.close();
	out_y.close();
	null_coordin();
}