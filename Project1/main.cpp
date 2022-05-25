#include "math/function.h"
#include <iostream>

//#define ANSWER
#define DIFFUR

int main() {
	double x0, u0; // ���������� ����� ������� ������ ��������� �������� ��
	double a, b;   // ���������� �� ������� �������� ��
	double tay;    // ���, ������������ ���������� ����� 2-�� ��������� �������
	int type;      // ��� �������
	int method;    // ��������� �����

	x0 = 5; u0 = 14;
	a = 3.06; b = 8.03;
	tay = 0.05;
	type = 0;
	method = 0;

	Function fun(type, a, b, x0, u0); // ������������� ��

	std::cout << fun.get_c();

	double** dot;
	
#ifdef ANSWER



	std::cout << "answer_grafic\n\n";
	dot = fun.answer_grafic(tay); // ������ u(x) - �������� ��

	for (int i = 0; i < fun.get_n(); i++)
		std::cout << dot[0][i] << "\n";

	std::cout << "\n\n\n\n";

	for (int i = 0; i < fun.get_n(); i++)
		std::cout << dot[1][i] << "\n";
#endif	
#ifdef DIFFUR
	std::cout << "diff_methods\n\n";
	dot = fun.diff_methods(method,tay);

	for (int i = 0; i < fun.get_n(); i++)
		std::cout << dot[0][i] << "\n";

	std::cout << "\n\n\n\n";

	for (int i = 0; i < fun.get_n(); i++)
		std::cout << dot[1][i] << "\n";
#endif
	system("pause");
	return 0;
}