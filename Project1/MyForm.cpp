#include "MyForm.h"
#include "math_diffur/function.h"

#define ANSWER
#define DIFFUR
#define WITH_PARSER

System::Void Project1::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e){
	double x0, u0; // Координаты через которые должен проходить Интеграл ДУ
	double a, b;   // Промежуток на котором решается ДУ
	double tay;    // Шаг, определяющий расстояние между 2-мя соседними точками
	int type;      // Тип функции
	int method;    // Численный метод

	x0 = 1; u0 = 10;
	a = 0.45; b = 10.504;
	tay = 0.003;
	type = 0;
	method = 1;
#ifdef WITH_PARSER
	std::string diffur = "(-x*x-x*y+y)/x";
	std::string integral_du = "y*e^(-x)*x-x"; // вместо y - c
	std::string const_du = "(y+x)/(e^(-x)*x)"; // вместо y - u0; вместо x - x0
	Diffur::Function fun(diffur, integral_du, const_du, a, b, x0, u0);
#else
	Diffur::Function fun(type, a, b, x0, u0); // Инициализация ДУ
#endif
	label2->Text = Convert::ToString(fun.get_c());

	double** dot;
#ifdef ANSWER
	dot = fun.answer_grafic(tay);         // Строим u(x) - Интеграл ДУ

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);
#endif	
#ifdef DIFFUR
	dot = fun.diff_methods(method, 100*tay);  // Строим y(x) - апроксимацию

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);
#endif	
	return System::Void();
}