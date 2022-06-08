#include "GraphIntegr.h"
#include "Params.h"

#ifdef OLD

#include "Integral Math/integr_math.h"

System::Void matlab::GraphIntegr::������(System::Object^ sender, System::EventArgs^ e, double a, double b, double s, double num, double n)
{
	double x = a;
	double y;
		//������� ��������
		this->chart1->Series[0]->Points->Clear();

		//���������� ��������

		while (x <= b) {
			y = test_function(x, num);
			this->chart1->Series[0]->Points->AddXY(x, y);

			//������ ������� �������

			y = test_function(x, num);
			this->chart1->Series[1]->Points->AddXY(x, y);

			x += s;
		}

		labRESULT1->Text = Convert::ToString(integral(a, b, num, n, 1));
		labRESULT2->Text = Convert::ToString(integral(a, b, num, n, 2));
		labRESULT3->Text = Convert::ToString(integral(a, b, num, n, 3));
		labRESULTR->Text = Convert::ToString(answer(a, b, num));

		return System::Void();
}
#endif

#include "math_integral/function.h"
#include <iostream>
#include <fstream>

#define ANSWER
#define INTEGR
#define WITH_PARSER

void MarshalString(System::String^ s, std::string& os) {
	using namespace System::Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

System::Void matlab::GraphIntegr::������(System::Object^ sender, System::EventArgs^ e, double a, double b, double tay, String ^ function, String ^ integral, int method, int type) {
	//double a, b;
	//double tay;
	//int type;
	//int method;

	//a = -10; b = 10;
	//tay = 0.005;
	//method = 1;
	double** dot;

	std::string funcLine, integrLine;
	MarshalString(function, funcLine);
	MarshalString(integral, integrLine);

//	
//	
////	type = 8;
//	Integral::Function fun(a, b, funcLine, integrLine);
//	
////	type = 1;
////	Integral::Function fun(type, a, b);
//
//
//
//	dot = fun.answer_grafic(tay);         // ������ ��������������� ������� f(x)
//
//	for (int i = 0; i < fun.get_n(); i++)
//		this->chart1->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);
//
//
//	dot = fun.integr_methods(method, tay);  // ������ ������������ � ������� �������� ��������� �������
//	std::ofstream file;
//	file.open("C:/Univer/������/��/������/Elfs/Dots.txt", std::ios::trunc);
//	for (int i = 0; i < fun.get_n(); i++) {
//		file << dot[0][i] << "	" << dot[1][i] << std::endl;
//		this->chart1->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);
//	}
//	file.close();
//
//
//	labRESULTR->Text = Convert::ToString(fun.get_answer()); // ��������� ������� ��������� ������� �������-��������
//	labRESULT1->Text = Convert::ToString(fun.get_result()); // ��������� ���������� ���������� ��������� �������
//	labRESULT2->Text = Convert::ToString(Integral::error_Runge(fun, method, 500 * tay)); // ����������� ����������� �� ������� �����
//	labRESULT3->Text = Convert::ToString(abs(fun.get_answer() - fun.get_result())); // �������� ����������
//
//	return System::Void();
	//
	//
	//
//	double** dot;

#ifdef WITH_PARSER
	Integral::Function fun(a, b, funcLine, integrLine);
#else
	Integral::Function fun(type, a, b);
#endif
	
#ifdef ANSWER
	dot = fun.answer_grafic(tay);         // ������ ��������������� ������� f(x)

	for (int i = 0; i < fun.get_n(); i++)
		chart1->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);
#endif
#ifdef INTEGR
	dot = fun.integr_methods(method, tay);  // ������ ������������ � ������� �������� ��������� �������

	for (int i = 0; i < fun.get_n(); i++)
		chart1->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);

	std::ofstream file;	//������� ����� � ����
	file.open("C:/Univer/������/��/������/Elfs/Dots.txt", std::ios::trunc);
	for (int i = 0; i < fun.get_n(); i++) {
		file << dot[0][i] << "	" << dot[1][i] << std::endl;
	}
	file.close();

#endif
	


	labRESULTR->Text = Convert::ToString(fun.get_answer()); // ��������� ������� ��������� ������� �������-��������
	labRESULT1->Text = Convert::ToString(fun.get_result()); // ��������� ���������� ���������� ��������� �������
	labRESULT2->Text = Convert::ToString(Integral::error_Runge(fun, method, tay)); // ����������� ����������� �� ������� �����
	labRESULT3->Text = Convert::ToString(abs(fun.get_answer() - fun.get_result())); // �������� ����������

	return System::Void();
}