#include <fstream>

class Function {
private:
	const int type;                // ���� ������� f(x,u)
	const double x0, u0;           // ����� ����� ������� ������ ��������� ������
	const double c;                // ��������� � ��������� ��
	const double x_start;          // ��������� ���������� x
	double x, y;                   // ������� ����������
	//const double y_start;          // ��� �������� ������� y_start = u(x_start) (��������� ����� ����� ��������� �� ��������� ��, � �� �� ������)

	const double answer_const(double x0, double y0, int type)const; // ����� ���������� ���������
	
public:
	// �����������
	Function(double x0, double u0, int type, double a) : type(type), x0(x0), u0(u0), c(answer_const(x0, u0, type)), x_start(a), x(x_start) /*,y_start(answer()), y(y_start)*/ {}

	// ������� \\

	const double get_c()const { return c; }; // ���������� ��������� c
	const double get_x()const { return x; }; // ���������� x
	const double get_y()const { return y; }; // ���������� y

	// ������� \\

	void set_x(double x_new) { x = x_new; };           // ������������� ����� x
	void set_y(double y_new) { y = y_new; };           // ������������� ����� y
	void null_coordin() { x = x_start; /*y = y_start;*/ }; // ���������� ������� ������������ � ���������

	// ��������� ������
	double function_diff()const;                                   // ���������� f(xn,yn)
	double answer()const;                                          // ���������� u(xn)
	void answer_grafic(const int n, double tay);                   // ������ ������ ��������� �� - u(x)
	void out_dot(std::ofstream& out_x, std::ofstream& out_y)const; // ����� ����� � ����

	/*
	(� ������ ����� out_dot ������ ���� private, 
	�.�.��������� ���������� 'y' ������������ ������ ������� ���������� ��������� ��, 
	�.�.��� �� ���������������� � �������� ��� ������� ������� ������)
	*/
};