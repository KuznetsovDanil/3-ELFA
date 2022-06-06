#include "MyForm.h"
#include "math_diffur/function.h"
#define ANSWER
#define DIFFUR

System::Void Project1::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e){
	double x0, u0; // ���������� ����� ������� ������ ��������� �������� ��
	double a, b;   // ���������� �� ������� �������� ��
	double tay;    // ���, ������������ ���������� ����� 2-�� ��������� �������
	int type;      // ��� �������
	int method;    // ��������� �����

	x0 = 28; u0 = 35;
	a = 0.45; b = 28.504;
	tay = 0.03;
	type = 0;
	method = 0;
	Diffur::Function fun(type, a, b, x0, u0); // ������������� ��

	label2->Text = Convert::ToString(fun.get_c());

	double** dot;
#ifdef ANSWER
	dot = fun.answer_grafic(tay);         // ������ u(x) - �������� ��

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[1]->Points->AddXY(dot[0][i], dot[1][i]);
#endif	
#ifdef DIFFUR
	dot = fun.diff_methods(method, tay);  // ������ y(x) - ������������

	for (int i = 0; i < fun.get_n(); i++)
		chart->Series[0]->Points->AddXY(dot[0][i], dot[1][i]);
#endif	
	return System::Void();
}