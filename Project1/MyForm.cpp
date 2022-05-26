#include "MyForm.h"
#include "math/function.h"
#define ANSWER
//#define DIFFUR

System::Void Project1::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e){
	double x0, u0; // Координаты через которые должен проходить Интеграл ДУ
	double a, b;   // Промежуток на котором решается ДУ
	double tay;    // Шаг, определяющий расстояние между 2-мя соседними точками
	int type;      // Тип функции
	int method;    // Численный метод

	x0 = 7; u0 = 7;
	a = 6.45; b = 87.003;
	tay = 0.05;
	type = 0;
	method = 0;
	Function fun(type, a, b, x0, u0); // Инициализация ДУ

	label2->Text = Convert::ToString(fun.get_c());

	double** dot;
#ifdef ANSWER
	dot = fun.answer_grafic(tay);         // Строим u(x) - Интеграл ДУ

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);
#endif	
#ifdef DIFFUR
	dot = fun.diff_methods(method, tay);  // Строим y(x) - апроксимацию

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);
#endif	
	return System::Void();
}