#include "math_diffur/function.h"
#include <iostream>

#define ANSWER
#define DIFFUR

int main() {
	double x0, u0; // Координаты через которые должен проходить Интеграл ДУ
	double a, b;   // Промежуток на котором решается ДУ
	double tay;    // Шаг, определяющий расстояние между 2-мя соседними точками
	int type;      // Тип функции
	int method;    // Численный метод

	x0 = 9.45; u0 = 5.456;
	a = 1; b = 17.007;
	tay = 0.003;
	type = 0;
	method = 0;

	Diffur::Function fun(type, a, b, x0, u0); // Инициализация ДУ

	std::cout << fun.get_c();

	double** dot;
	dot = fun.get_mass_dots();

#ifdef ANSWER
	std::cout << "answer_grafic\n\n";
	fun.answer_grafic(tay); // Строим u(x) - Интеграл ДУ

	for (int i = 0; i < fun.get_n(); i++)
		std::cout << dot[0][i] << "\n";
	std::cout << "\n\n";
	for (int i = 0; i < fun.get_n(); i++)
		std::cout << dot[1][i] << "\n";

	std::cout << "\n\n\n\n";

#endif	
#ifdef DIFFUR
	std::cout << "diff_methods\n\n";
	fun.diff_methods(method,tay);

	for (int i = 0; i < fun.get_n(); i++)
		std::cout << dot[0][i] << "\n";
	std::cout << "\n\n";
	for (int i = 0; i < fun.get_n(); i++)
		std::cout << dot[1][i] << "\n";
	std::cout << "\n\n\n\n";
#endif
	system("pause");
	return 0;
}