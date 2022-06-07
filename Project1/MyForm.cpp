#include "MyForm.h"
#include "math_diffur/function.h"

#define ANSWER
#define DIFFUR
#define WITH_PARSER

System::Void Project1::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e){
	double x0, u0; // ���������� ����� ������� ������ ��������� �������� ��
	double a, b;   // ���������� �� ������� �������� ��
	double tay;    // ���, ������������ ���������� ����� 2-�� ��������� �������
	int type;      // ��� �������
	int method;    // ��������� �����

	x0 = 1; u0 = 10;
	a = 0.45; b = 10.504;
	tay = 0.003;
	type = 0;
	method = 1;
#ifdef WITH_PARSER
	std::string diffur = "(-x*x-x*y+y)/x";
	std::string integral_du = "y*e^(-x)*x-x"; // ������ y - c
	std::string const_du = "(y+x)/(e^(-x)*x)"; // ������ y - u0; ������ x - x0
	Diffur::Function fun(diffur, integral_du, const_du, a, b, x0, u0);
#else
	Diffur::Function fun(type, a, b, x0, u0); // ������������� ��
#endif
	label2->Text = Convert::ToString(fun.get_c());

	double** dot;
#ifdef ANSWER
	dot = fun.answer_grafic(tay);         // ������ u(x) - �������� ��

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);
#endif	
#ifdef DIFFUR
	dot = fun.diff_methods(method, 100*tay);  // ������ y(x) - ������������

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);
#endif	
	return System::Void();
}