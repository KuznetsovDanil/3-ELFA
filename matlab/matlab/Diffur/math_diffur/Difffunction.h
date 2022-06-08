#include <corecrt_math_defines.h>
#include <cmath>
#include "Parser/Diffparser.h"
#include "Diffother.h"

namespace Diffur {

	using namespace DIFFUR_PARS;

	class Function {
	private:
		const int type;                // ���� �������-������ f(x,u)

		parser*const p;
		const std::string diffur;      // ���� �������-������ f(x,u) � ���� ������
		const std::string integral_du; // �������� ��
		const std::string const_du;    // ��������� ���������� �� ��������� ��

		const double a;                // ������ �������, �� ������� �������� �������� �� � �������������
		const double b;                // ������ �������, �� ������� �������� �������� �� � �������������
		int n;                         // ���������� ����� (����������� ��� ���������� �����)
		const double x0, u0;           // �����, ����� ������� ������ ��������� ������
		const double c;                // ��������� � ��������� ��
		double x, y;                   // ������� ����������
		double** const dots;           // ������ �� �����
		enum Methods                   // ������ ��������� �������
		{EULER, PREDICTOR_CORRECTOR, RUNGE_KUTT_3, RUNGE_KUTT_4};

		// ������� \\

		void null_coordin() { x = x0; y = u0; };                        // ���������� ������� ������������ � ���������
		void write_coordin(int i) { dots[0][i] = diff_drop_trash(x); dots[1][i] = y; };  // ���������� i-�� ����� � ������

		// ��������� ������ \\

		double function_diff(const double x, const double y)const;  // ���������� f(xn,yn)
		double answer()const;                                       // ���������� u(xn)
		const double answer_const()const;                           // ����� ���������� ���������

		void create_mass_dots()                                     // �������� ������ ��� n ���������
		{dots[0] = new double[n]; dots[1] = new double[n];};

		////////////////////
		//��������� ������//
		////////////////////

		double next_y(const double tay, const int method)const;    /* ������� ���������� y ��� ��������� �� ���,
																				  ���������� � ����������� �� ���������� ������ ���������� ������������� */
		double** const before(const double tay, const int method); // ����� �� ���������� ����������
		double** const after(const double tay, const int method);  // ����� ����� ���������� ����������
		double** const inside(const double tay, const int method); // ����� ������ ���������� ����������

	public:
		// ����������� � ���������� \\

		Function(int type, double a, double b, double x0, double u0) :
			type(type), p(nullptr), a(a), b(b), n(NULL), x0(x0), u0(u0), c(answer_const()), dots(new double* [2]) {
			dots[0] = dots[1] = nullptr;
			null_coordin();
		};
		Function(std::string diffur, std::string integral_du, std::string const_du, double a, double b, double x0, double u0) :
			type(EOF), p(new parser), diffur(diffur), integral_du(integral_du), const_du(const_du), a(a), b(b), n(NULL), x0(x0), u0(u0), c(answer_const()), dots(new double* [2]) {
			dots[0] = dots[1] = nullptr;
			null_coordin();
		};
		~Function() { delete[]dots[0]; delete[]dots[1]; delete dots; delete p; };

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
}