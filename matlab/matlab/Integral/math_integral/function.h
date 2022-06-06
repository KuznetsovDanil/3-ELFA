#include <corecrt_math_defines.h>
#include <cmath>
#include "Parser/parser.h"
#include "other.h"

namespace Integral {
	class Function {
	private:
		const int type;                // ��������������� �������
		const std::string fun;         // ��������������� �������, � ���� ������
		const std::string integral;    // �������� ��������� �� ������� �������-��������
		const double a;                // ������ �������
		const double b;                // ������� �������
		const double answer;           // �������� ��������������� �������
		double result;                 // ��������� ��������� �������� ���������� ��������� ��������� �������
		int n;                         // ���������� ����� (����������� ��� ���������� ����� �����)
		double x, y;                   // ������� ����������
		double** const dots;           // ������ �� �����
		enum Methods                   // ������ ��������� �������
		{RECTANGLE,TRAPEZE, SIMPSON};

		// ������� \\

		void write_coordin(int i) { dots[0][i] = drop_trash(x); dots[1][i] = y; };  // ���������� i-�� ����� � ������

		// ��������� ������ \\

		double function_integr(const double x)const; // ���������� �������� ���������������� ������� f(x)
		double answer_integr()const;                 // ���������� �������� �� ������� �������-��������

		void create_mass_dots()                      // �������� ������ ��� n ���������
		{dots[0] = new double[n]; dots[1] = new double[n];};

		////////////////////
		//��������� ������//
		////////////////////

		double** const rectangle(const double tay);
		double** const trapeze(const double tay);
		double** const simpson(const double tay);

	public:

		// ����������� � ���������� \\

		Function(int type, double a, double b) :
			type(type), a(a), b(b), answer(answer_integr()), n(NULL), dots(new double* [2]) {
			result = 0;
			dots[0] = dots[1] = nullptr;
		};
		Function(int type, double a, double b, std::string fun, std::string integral) :
			type(type),fun(fun), integral(integral), a(a), b(b), answer(answer_integr()), n(NULL), dots(new double* [2]) {
			result = 0;
			dots[0] = dots[1] = nullptr;
		};
		Function(Function& f) :
			type(f.type), a(f.a), b(f.b), answer(answer_integr()), n(NULL), dots(new double* [2]) {
			dots[0] = dots[1] = nullptr;
		}
		~Function() { delete[]dots[0]; delete[]dots[1]; delete dots; };

		// ������� \\

		double get_n()const { return n; };               // ���������� ���������� �����
		double** get_mass_dots()const { return dots; };  // ���������� ��������� �� ������ �����
		double get_answer()const { return answer; };     // ���������� �������� ��������� �� ������� �������-��������
		double get_result()const { return result; };     // ���������� ��������� ���������� ���������� ���������� ���������

		// ��������� ������ \\

		double** const answer_grafic(const double tay);                             // ��������� ����� ��������������� �������
		double** const integr_methods(const int method, const double tay);          // �������� ��������� ��������� �����
		friend double error_Runge(Integral::Function& fun, int method, double tay); // ������ ����������� �� ������� �����
		void clear_data()                                                           // ������� ������ �����
		{delete[]dots[0]; delete[]dots[1]; dots[0] = dots[1] = nullptr; n = NULL;};
	};
}