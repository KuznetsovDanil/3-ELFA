#pragma once

double integral(double a, double b, int num, int n, int method) {

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
				res += test_function(i, num); /*  integral += fun(i)*step; ����� ����������� �� dx,
										��� � ��� ���� � ���� ������� ������� ��� */

		// �������������� ������ ������ (� ������ ������ ���������� ����� �������������)
		else
			for (double i = a - step / 2; i - b > 0.0000001; i += step)
				res += test_function(i, num); /*  integral += fun(i)*step; ����� ����������� �� dx,
										��� � ��� ���� � ���� ������� ������� ��� */

		return res * step; // �������� �� dx
		//----------------------------------------------------------------------\\

	case 2:

		// ������� �������� \\

		if (a < b)
			for (double i = a + step; b - i > step; i += step)
				res += test_function(i, num);

		// �������������� ������ ������ (� ������ ������ ���������� ����� �������������)
		else
			for (double i = a + step; i - b > step; i += step)
				res += test_function(i, num);

		return (2 * res + test_function(a, num) + test_function(b, num)) * step / 2;
		//------------------\\

	case 3:
		// ������� �������� \\
		
		//bool flag; ����� ��������������� ������ ��� ������������ �������� ������
		double res2 = 0;
		
		if (a < b) {
			// � ��������� ��������
			for (double i = a + step; b - i > step; i += 2 * step)
				res += test_function(i, num);

			// � ������� ��������
			for (double i = a + 2 * step; b - i > step; i += 2 * step)
				res2 += test_function(i, num);
		}
		// �������������� ������ ������ (� ������ ������ ���������� ����� �������������)
		else {
			// � ��������� ��������
			for (double i = a + step; i - b > step; i += 2 * step)
				res += test_function(i, num);

			// � ������� ��������
			for (double i = a + 2 * step; i - b > step; i += 2 * step)
				res2 += test_function(i, num);
		}

		return (res * 4 + res2 * 2 + test_function(a, num) + test_function(b, num)) * step / 3;
		//------------------\\

	}
	

}