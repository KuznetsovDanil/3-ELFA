#include <fstream>

class Function {
private:
	const int type;                // Сама функция f(x,u)
	const double x0, u0;           // Точка через которую обязан проходить график
	const double c;                // Константа в Интеграле ДУ
	const double x_start;          // Начальная координата x
	double x, y;                   // Текущие координаты
	//const double y_start;          // Для простоты сделаем y_start = u(x_start) (начальная точка будет высчитана по Интегралу ДУ, а не по методу)

	const double answer_const(double x0, double y0, int type)const; // Метод вычисления константы
	
public:
	// Конструктор
	Function(double x0, double u0, int type, double a) : type(type), x0(x0), u0(u0), c(answer_const(x0, u0, type)), x_start(a), x(x_start) /*,y_start(answer()), y(y_start)*/ {}

	// Геттеры \\

	const double get_c()const { return c; }; // Возвращает константу c
	const double get_x()const { return x; }; // Возвращает x
	const double get_y()const { return y; }; // Возвращает y

	// Сеттеры \\

	void set_x(double x_new) { x = x_new; };           // Устанавливает новый x
	void set_y(double y_new) { y = y_new; };           // Устанавливает новый y
	void null_coordin() { x = x_start; /*y = y_start;*/ }; // Сбрасывает текущие координинаты в начальные

	// Остальные методы
	double function_diff()const;                                   // Возвращает f(xn,yn)
	double answer()const;                                          // Возвращает u(xn)
	void answer_grafic(const int n, double tay);                   // Строит график Интеграла ДУ - u(x)
	void out_dot(std::ofstream& out_x, std::ofstream& out_y)const; // Вывод точки в файл

	/*
	(в идеале метод out_dot должен быть private, 
	т.к.начальная координата 'y' определяется внутри методов нахождения Интеграла ДУ, 
	т.е.она не инициализирована и вызывать эту функцию вручную НЕЛЬЗЯ)
	*/
};