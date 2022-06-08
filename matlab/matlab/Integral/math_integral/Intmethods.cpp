#include "Intfunction.h"
#ifdef OLD
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

	case 3:
		// ������� �������� \\
		
		//bool flag; ����� ��������������� ������ ��� ������������ �������� ������
		double res2 = 0;
		
		if (a < b) {
			// � ��������� ��������
			for (double i = a + step; b - i > step; i += 2 * step)
				res += test_function(i, c);

			// � ������� ��������
			for (double i = a + 2 * step; b - i > step; i += 2 * step)
				res2 += test_function(i, c);
		}
		// �������������� ������ ������ (� ������ ������ ���������� ����� �������������)
		else {
			// � ��������� ��������
			for (double i = a + step; i - b > step; i += 2 * step)
				res += test_function(i, c);

			// � ������� ��������
			for (double i = a + 2 * step; i - b > step; i += 2 * step)
				res2 += test_function(i, c);
		}

		return (res * 4 + res2 * 2 + test_function(a, c) + test_function(b, c)) * step / 3;
		//------------------\\

	}
	

}
#endif

double Integral::error_Runge(Integral::Function& fun, int method, double tay) {
	Integral::Function fun_clone(fun);
	fun_clone.integr_methods(method, tay * 2);
	return abs(fun.get_result() - fun_clone.get_result()) / (pow(2, (method == 2) ? 4 : 2) - 1);
}

double** const Integral::Function::integr_methods(const int method, const double tay){
	switch (method)
	{
	case RECTANGLE: { return rectangle(tay);break; }
	case TRAPEZE: { return trapeze(tay); break; }
	case SIMPSON: { return simpson(tay); break; }
	default:break;
	}
}

double** const Integral::Function::rectangle(const double tay){
	clear_data();
	n = ceil(int_drop_trash((b - a) / tay)) - 1; // ���������� ����� ����� a � b + ���� a � b
	create_mass_dots();
	double sum = 0;

	// ������������ ������ ����� ������ ����������
	x = a + tay / 2;
	y = function_integr(x);
	write_coordin(0);
	sum += y;

	for (int i = 1; i < n; i++) {
		x += tay;
		y = function_integr(x);
		write_coordin(i);
		sum += y;
	}

	result = tay * sum;

	return dots;
}

double** const Integral::Function::trapeze(const double tay){
	clear_data();
	n = ceil(int_drop_trash((b - a) / tay)) + 1; // ���������� ����� ����� a � b + ���� a � b
	create_mass_dots();
	double sum = 0;

	// ������������ ����� �� ������� � a
	x = a;
	y = function_integr(x);
	write_coordin(0);
	sum += y/2;

	for (int i = 1; i < n - 1; i++) {
		x += tay;
		y = function_integr(x);
		write_coordin(i);
		sum += y;
	}

	// ������������� ���� �� ������� � b
	{
		const double tay_b = b - x;  // ������� ������� ��������� �� b
		x += tay_b;                  // ������� �� b
		y = function_integr(x);      // � ������� ����� �� b
		write_coordin(n - 1);
		sum += y/2;
	}

	result = tay * sum;

	return dots;
}

double** const Integral::Function::simpson(double tay){
	clear_data();
	tay /= 2;
	n = ceil(int_drop_trash((b - a) / tay)) + 1; // ����� ����� a � b + ���� a � b
	create_mass_dots();
	double sum = 0;

	// ������������ ����� �� ������� � a
	x = a;
	y = function_integr(x);
	write_coordin(0);
	sum += y;

	for (int i = 1; i < n - 1; i++) {
		x += tay;
		y = function_integr(x);
		write_coordin(i);
		sum += ((i % 2) ? 4 : 2) * y;
	}

	// ������������� ���� �� ������� � b
	{
		const double tay_b = b - x;  // ������� ������� ��������� �� b
		x += tay_b;                  // ������� �� b
		y = function_integr(x);      // � ������� ����� �� b
		write_coordin(n - 1);
		sum += y;
	}

	result = sum * tay / 3;
	return dots;
}