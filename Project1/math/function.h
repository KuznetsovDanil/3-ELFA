#include <corecrt_math_defines.h>
#include <cmath>

class Function {
private:
	const int type;                // ���� �������-������ f(x,u)
	const double a;                // ������ �������, �� ������� �������� �������� �� � �������������
	const double b;                // ������ �������, �� ������� �������� �������� �� � �������������
	int n;                         // ���������� ����� (����������� ��� ���������� �����)
	const double x0, u0;           // �����, ����� ������� ������ ��������� ������
	const double c;                // ��������� � ��������� ��
	double x, y;                   // ������� ����������
	double** const dots;           // ������ �� �����
	enum Methods { EULER };        // ������ ��������� �������

	// ������� \\

	void null_coordin() { x = x0; y = u0; };                        // ���������� ������� ������������ � ���������
	void write_coordin(int i) { dots[0][i] = x; dots[1][i] = y; };  // ���������� i-�� ����� � ������

	// ��������� ������ \\

	double function_diff()const;                                     // ���������� f(xn,yn)
	double answer()const;                                            // ���������� u(xn)
	const double answer_const()const;                                // ����� ���������� ���������

	void create_mass_dots()                                          // �������� ������ ��� n ���������
	{dots[0] = new double[n]; dots[1] = new double[n];};

	////////////////////
	//��������� ������//
	////////////////////

	// ����� ������ \\

	double** const euler_before(const double tay);
	double** const euler_after(const double tay);
	double** const euler_inside(const double tay);

public:

	// ����������� � ���������� \\

	Function(int type, double a, double b, double x0, double u0) :
		type(type), a(a), b(b), n(NULL), x0(x0), u0(u0), c(answer_const()), dots(new double* [2]) {
		dots[0] = dots[1] = nullptr;
		null_coordin();
	};
	~Function() { delete[]dots[0]; delete[]dots[1]; delete dots; };

	// ������� \\

	double get_n()const { return n; };                               // ���������� ���������� �����
	const double get_c()const { return c; };                         // ���������� ��������� c
	double** get_mass_dots()const { return dots; };                  // ���������� ��������� �� ������ �����

	// ��������� ������ \\

	double** const answer_grafic(const double tay);                  // ��������� ����� ��������� �� - u(x)
	double** const diff_methods(const int method, const double tay); // �������� ��������� ��������� �����

	void clear_data()                                                // ������� ������ �����
	{delete[]dots[0]; delete[]dots[1]; dots[0] = dots[1] = nullptr; n = NULL;};
};