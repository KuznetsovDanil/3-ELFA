#include <fstream>

class Function {
private:
	const int type;         // ���� ������� f(x,u)
	const double x0, u0;    // ��������� ����������
	double x, y;            // ������� ����������
	const double c;         // ��������� � ��������� ��

	const double answer_const(double x0, double y0, int type)const; // ������� ���������� ���������
	
public:
	// �����������
	Function(const double x0, const double u0, const int type) : type(type), x0(x0), u0(u0), c(answer_const(x0, u0, type)) { null_coordin(); }

	// ������� \\

	const double get_c()const { return c; }; // ���������� ��������� c
	const double get_x()const { return x; }; // ���������� x
	const double get_y()const { return y; }; // ���������� y

	// ������� \\

	void set_x(double x_new) { x = x_new; }; // ������������� ����� x
	void set_y(double y_new) { y = y_new; }; // ������������� ����� y
	void null_coordin() { x = x0; y = u0; }; // ���������� ������� ������������ � ���������

	// ��������� ������
	double function_diff()const;                                                    // ���������� f(xn,yn)
	double answer()const;                                                           // ���������� u(xn)
	void answer_grafic(const int n, double tay);                                    // ������ ������ ��������� ��
	friend void out_dot(Function& fun, std::ofstream& out_x, std::ofstream& out_y); // ��� ������ ����� y(x)
	friend void out_dot(double, double, std::ofstream&, std::ofstream&);            // ��� ������ ����� u(x)
};