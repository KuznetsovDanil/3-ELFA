#include "GraphIntegr.h"
#include "ParamsIntegr.h"
#include "math_integral/Intfunction.h"
#include <iostream>
#include <fstream>

namespace INTEGRAL_STRING {
	void MarshalString(System::String^ s, std::string& os) {
		using namespace System::Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(System::IntPtr((void*)chars));
	}
}
System::Void matlab::GraphIntegr::Расчёт(System::Object^ sender, System::EventArgs^ e, double a, double b, double tay, String^ function, String^ integral, int method, int type) {

	double** dot;

	std::string funcLine, integrLine;
	INTEGRAL_STRING::MarshalString(function, funcLine);
	INTEGRAL_STRING::MarshalString(integral, integrLine);

	if (type < 0) {
		Integral::Function fun(a, b, funcLine, integrLine);

		dot = fun.answer_grafic(tay);         // Строим подынтегральную функцию f(x)

		for (int i = 0; i < fun.get_n(); i++)
			chart1->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);

		dot = fun.integr_methods(method, tay);  // Строим апроксимацию и считаем интеграл численным методом

		for (int i = 0; i < fun.get_n(); i++)
			chart1->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);

		std::ofstream file;	//выводим точки в файл
		file.open("Dots.txt", std::ios::trunc);
		for (int i = 0; i < fun.get_n(); i++) {
			file << dot[0][i] << "	" << dot[1][i] << std::endl;
		}
		file.close();

		labRESULTR->Text = Convert::ToString(fun.get_answer()); // Результат расчета интеграла методом Ньютона-Лейбница
		labRESULT1->Text = Convert::ToString(fun.get_result()); // Результат последнего вычисления численным методом
		labRESULT2->Text = Convert::ToString(Integral::error_Runge(fun, method, tay)); // Погрешность рассчитаная по правилу Рунге
		labRESULT3->Text = Convert::ToString(abs(fun.get_answer() - fun.get_result())); // Истинное отклонение

	}
	else {
		Integral::Function fun(type, a, b);

		dot = fun.answer_grafic(tay);         // Строим подынтегральную функцию f(x)

		for (int i = 0; i < fun.get_n(); i++)
			chart1->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);

		dot = fun.integr_methods(method, tay);  // Строим апроксимацию и считаем интеграл численным методом

		for (int i = 0; i < fun.get_n(); i++)
			chart1->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);

		std::ofstream file;	//выводим точки в файл
		file.open("Dots.txt", std::ios::trunc);
		for (int i = 0; i < fun.get_n(); i++) {
			file << dot[0][i] << "	" << dot[1][i] << std::endl;
		}
		file.close();

		labRESULTR->Text = Convert::ToString(fun.get_answer()); // Результат расчета интеграла методом Ньютона-Лейбница
		labRESULT1->Text = Convert::ToString(fun.get_result()); // Результат последнего вычисления численным методом
		labRESULT2->Text = Convert::ToString(Integral::error_Runge(fun, method, tay)); // Погрешность рассчитаная по правилу Рунге
		labRESULT3->Text = Convert::ToString(abs(fun.get_answer() - fun.get_result())); // Истинное отклонение

	}
	//
	//dot = fun.answer_grafic(tay);         // Строим подынтегральную функцию f(x)
	//
	//for (int i = 0; i < fun.get_n(); i++)
	//	chart1->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);
	//
	//dot = fun.integr_methods(method, tay);  // Строим апроксимацию и считаем интеграл численным методом
	//
	//for (int i = 0; i < fun.get_n(); i++)
	//	chart1->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);
	//
	//std::ofstream file;	//выводим точки в файл
	//file.open("Dots.txt", std::ios::trunc);
	//for (int i = 0; i < fun.get_n(); i++) {
	//	file << dot[0][i] << "	" << dot[1][i] << std::endl;
	//}
	//file.close();
	//
	//labRESULTR->Text = Convert::ToString(fun.get_answer()); // Результат расчета интеграла методом Ньютона-Лейбница
	//labRESULT1->Text = Convert::ToString(fun.get_result()); // Результат последнего вычисления численным методом
	//labRESULT2->Text = Convert::ToString(Integral::error_Runge(fun, method, tay)); // Погрешность рассчитаная по правилу Рунге
	//labRESULT3->Text = Convert::ToString(abs(fun.get_answer() - fun.get_result())); // Истинное отклонение

	return System::Void();
}