#include "integr_math.h"
#include "function.h"

double integral(double a, double b, int c, int n, int method) {

	const double step = (b - a) / n;
	double res = 0;
	switch (method)
	{
	case 1:

		// ������� ���������� ��������������� (�� ���� �������� �� �����������) \\
	
	/* ���������� i ����� ����� ���� ������������ ����� "���",
		������������� �� ������� ����������, ������� �� ������ ����� ����� ��
		�������� ������� ����������, �.�. ������ ����� ����������� */

		// �������������� ����� ��������
		if (a < b)
			for (double i = a + step / 2; b - i > 0.0000001; i += step)
				res += test_function(i, c); /*  integral += fun(i)*step; ����� ����������� �� dx,
										��� � ��� ���� � ���� ������� ������� ��� */

										// �������������� ������ ������ (� ������ ������ ���������� ����� �������������)
		else
			for (double i = a - step / 2; i - b > 0.0000001; i += step)
				res += test_function(i, c); /*  integral += fun(i)*step; ����� ����������� �� dx,
										��� � ��� ���� � ���� ������� ������� ��� */

		return res * step; // �������� �� dx
		//----------------------------------------------------------------------\\

	case 2:

		// ������� �������� \\

		if (a < b)
		for (double i = a + step; b - i > step; i += step)
			res += test_function(i, c);

		// �������������� ������ ������ (� ������ ������ ���������� ����� �������������)
		else
		for (double i = a + step; i - b > step; i += step)
			res += test_function(i, c);

		return (2 * res + test_function(a, c) + test_function(b, c)) * step / 2;
		//------------------\\

	//case 3:
		// ������� ��������\\
		
		//------------------\\

	}
	

}