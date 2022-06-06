#include <corecrt_math_defines.h>
#include <cmath>
#include "Parser/parser.h"
#include "other.h"

namespace Integral {
	class Function {
	private:
		const int type;                // Подынтегральная функция
		const std::string fun;         // Подынтегральная функция, в виде строки
		const std::string integral;    // Интеграл раскрытый по формуле Ньютона-Лейбница
		const double a;                // Нижняя граница
		const double b;                // Верхняя граница
		const double answer;           // Интеграл подынтегральной функции
		double result;                 // Результат последней операции вычисления интеграла численным методом
		int n;                         // Количество точек (вычисляется при вычислении самих точек)
		double x, y;                   // Текущие координаты
		double** const dots;           // Массив из точек
		enum Methods                   // Список численных методов
		{RECTANGLE,TRAPEZE, SIMPSON};

		// Сеттеры \\

		void write_coordin(int i) { dots[0][i] = drop_trash(x); dots[1][i] = y; };  // Записывает i-ую точку в массив

		// Остальные методы \\

		double function_integr(const double x)const; // Возвращает значение подыинтегральной функции f(x)
		double answer_integr()const;                 // Вычислякет интеграл по формуле Ньютона-Лейбница

		void create_mass_dots()                      // Выделяет память под n элементов
		{dots[0] = new double[n]; dots[1] = new double[n];};

		////////////////////
		//Численные методы//
		////////////////////

		double** const rectangle(const double tay);
		double** const trapeze(const double tay);
		double** const simpson(const double tay);

	public:

		// Конструктор и деструктор \\

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

		// Геттеры \\

		double get_n()const { return n; };               // Возвращает количество точек
		double** get_mass_dots()const { return dots; };  // Возвращает указатель на массив точек
		double get_answer()const { return answer; };     // Возвращает значение интеграла по формуле Ньютона-Лейбница
		double get_result()const { return result; };     // Возвращает результат последнего численного вычисления интеграла

		// Остальные методы \\

		double** const answer_grafic(const double tay);                             // Вычисляет точки подынтегральной функции
		double** const integr_methods(const int method, const double tay);          // Вызывает выбранный численный метод
		friend double error_Runge(Integral::Function& fun, int method, double tay); // Расчет погрешности по правилу Рунге
		void clear_data()                                                           // Удаляет массив точек
		{delete[]dots[0]; delete[]dots[1]; dots[0] = dots[1] = nullptr; n = NULL;};
	};
}