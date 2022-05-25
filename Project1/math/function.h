#include <corecrt_math_defines.h>
#include <cmath>

class Function {
private:
	const int type;                // Сама функция-диффур f(x,u)
	const double a;                // Нижняя граница, от которой строится Интеграл ДУ и аппроксимация
	const double b;                // Нижняя граница, от которой строится Интеграл ДУ и аппроксимация
	int n;                         // Количество точек (вычисляется при вычислении точек)
	const double x0, u0;           // Точка, через которую обязан проходить график
	const double c;                // Константа в Интеграле ДУ
	double x, y;                   // Текущие координаты
	double** const dots;           // Массив из точек
	enum Methods { EULER };        // Список численных методов

	// Сеттеры \\

	void null_coordin() { x = x0; y = u0; };                        // Сбрасывает текущие координинаты в начальные
	void write_coordin(int i) { dots[0][i] = x; dots[1][i] = y; };  // Записывает i-ую точку в массив

	// Остальные методы \\

	double function_diff()const;                                     // Возвращает f(xn,yn)
	double answer()const;                                            // Возвращает u(xn)
	const double answer_const()const;                                // Метод вычисления константы

	void create_mass_dots()                                          // Выделяет память под n элементов
	{dots[0] = new double[n]; dots[1] = new double[n];};

	////////////////////
	//Численные методы//
	////////////////////

	// Метод Эйлера \\

	double** const euler_before(const double tay);
	double** const euler_after(const double tay);
	double** const euler_inside(const double tay);

public:

	// Конструктор и деструктор \\

	Function(int type, double a, double b, double x0, double u0) :
		type(type), a(a), b(b), n(NULL), x0(x0), u0(u0), c(answer_const()), dots(new double* [2]) {
		dots[0] = dots[1] = nullptr;
		null_coordin();
	};
	~Function() { delete[]dots[0]; delete[]dots[1]; delete dots; };

	// Геттеры \\

	double get_n()const { return n; };                               // Возвращает количество точек
	const double get_c()const { return c; };                         // Возвращает константу c
	double** get_mass_dots()const { return dots; };                  // Возвращает указатель на массив точек

	// Остальные методы \\

	double** const answer_grafic(const double tay);                  // Вычисляет точки Интеграла ДУ - u(x)
	double** const diff_methods(const int method, const double tay); // Вызывает выбранный численный метод

	void clear_data()                                                // Удаляет массив точек
	{delete[]dots[0]; delete[]dots[1]; dots[0] = dots[1] = nullptr; n = NULL;};
};