#include "MyForm.h"
//#include "math/diff.h"

double answer(double, int, const double); // �� ������ answer �� ������������ ����� diff.h, � test_function ������������ ?????

void Project1::MyForm::out_dot(double x, double y, std::ofstream& out_x, std::ofstream& out_y, bool key)
{
	chart->Series[key?0:1]->Points->AddXY(x, y);
	// ���� key true �� ��������� ������ �����������, ����� ��������� �������� ������
}

void Project1::MyForm::diff_methods(double x, double y, const int n, double tay, int method, int fun)
{
	int x0 = x;
	const double c = answer_const(x, y, fun);
	label2->Text = Convert::ToString(c);
	//cout << c;
	//system("pause");
	//std::ofstream out_x("file_x.txt");
	//std::ofstream out_y("file_y.txt");
	std::ofstream out_x;
	std::ofstream out_y;
	switch (method)
	{
	case 1:
		// ����� ������ (����� �������) \\

		for (int i = 0; i < n; i++) {
			out_dot(x, y, out_x, out_y, true);
			y += tay * test_function(x, y, fun);
			x += tay;
		}

	default://cout << "������";
		break;
	}
	// ���������� �������� �������
	x = x0;
	for (int i = 0; i < n; i++) {
		out_dot(x, answer(x, fun, c), out_x, out_y, false);
		x += tay;
	}
	out_x.close();
	out_y.close();
}


