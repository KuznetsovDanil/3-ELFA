#include "MyForm.h"
#include "math_integral/function.h"

#define ANSWER
#define INTEGR
#define WITH_PARSER

System::Void Project1::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e){
	double a, b;
	double tay;
	int type;
	int method;

	a = -10; b = 10;
	tay = 0.005;
	method = 1;
	double** dot;
#ifdef WITH_PARSER
	Integral::Function fun(a, b, "sin(x)+cos(x)", "(-cos(y)+sin(y))-(-cos(x)+sin(x))");
#else
	type = 1;
	Integral::Function fun(type, a, b);
#endif

#ifdef ANSWER
	dot = fun.answer_grafic(tay);         // ������ ��������������� ������� f(x)

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);
#endif
#ifdef INTEGR
	dot = fun.integr_methods(method, 500*tay);  // ������ ������������ � ������� �������� ��������� �������

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);
	
#endif
	label2->Text = Convert::ToString(fun.get_answer()); // ��������� ������� ��������� ������� �������-��������
	label4->Text = Convert::ToString(fun.get_result()); // ��������� ���������� ���������� ��������� �������
	label6->Text = Convert::ToString(Integral::error_Runge(fun, method, 500 * tay)); // ����������� ����������� �� ������� �����
	label8->Text = Convert::ToString(abs(fun.get_answer()-fun.get_result())); // �������� ����������
	return System::Void();
}