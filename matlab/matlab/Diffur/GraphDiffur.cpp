#include "GraphDiffur.h"
#include "math_diffur/Difffunction.h"
#include <fstream>

namespace DIFFURE_STRING {
	void MarshalString(System::String^ s, std::string& os) {
		using namespace System::Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(System::IntPtr((void*)chars));
	}
}
System::Void matlab::GraphDiffur::Расчёт(
	System::Object^ sender, System::EventArgs^ e,
	double a, double b, double x0, double u0, double tay,
	String^ _diffur, String^ _integral_du, String^ _const_du,
	int type, int method) {

//	double x0, u0; // Координаты через которые должен проходить Интеграл ДУ
//	double a, b;   // Промежуток на котором решается ДУ
//	double tay;    // Шаг, определяющий расстояние между 2-мя соседними точками
//	int type;      // Тип функции
//	int method;    // Численный метод
//
//	x0 = 1; u0 = 10;
//	a = 0.45; b = 10.504;
//	tay = 0.003;
//	type = 0;
//	method = 1;

std::string diffur;
std::string integral_du; // вместо y - c
std::string const_du; // вместо y - u0; вместо x - x0

DIFFURE_STRING::MarshalString(_diffur, diffur);
DIFFURE_STRING::MarshalString(_integral_du, integral_du);
DIFFURE_STRING::MarshalString(_const_du, const_du);

	if (type < 0) {
		Diffur::Function fun(diffur, integral_du, const_du, a, b, x0, u0);


		Result->Text = Convert::ToString(fun.get_c());

		double** dot;
		dot = fun.answer_grafic(0.1 * tay);         // Строим u(x) - Интеграл ДУ

		for (int i = 0; i < fun.get_n(); i++)
			chart1->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);

		dot = fun.diff_methods(method, tay);  // Строим y(x) - апроксимацию

		for (int i = 0; i < fun.get_n(); i++)
			chart1->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);

		std::ofstream file;	//выводим точки в файл
		file.open("Dots.txt", std::ios::trunc);
		for (int i = 0; i < fun.get_n(); i++) {
			file << dot[0][i] << "	" << dot[1][i] << std::endl;
		}
	}
	else {
		Diffur::Function fun(type, a, b, x0, u0); // Инициализация ДУ


		Result->Text = Convert::ToString(fun.get_c());

		double** dot;
		dot = fun.answer_grafic(0.1 * tay);         // Строим u(x) - Интеграл ДУ

		for (int i = 0; i < fun.get_n(); i++)
			chart1->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);

		dot = fun.diff_methods(method, tay);  // Строим y(x) - апроксимацию

		for (int i = 0; i < fun.get_n(); i++)
			chart1->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);

		std::ofstream file;	//выводим точки в файл
		file.open("Dots.txt", std::ios::trunc);
		for (int i = 0; i < fun.get_n(); i++) {
			file << dot[0][i] << "	" << dot[1][i] << std::endl;
		}
	}
	return System::Void();
}