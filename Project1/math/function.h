#include <fstream>

class Function {
private:
	const int type;         // Сама функция f(x,u)
	const double x0, u0;    // Начальные координаты
	double x, y;            // Текущие координаты
	const double c;         // Константа в Интеграле ДУ

	const double answer_const(double x0, double y0, int type)const; // Функция вычисления константы
	
public:
	// Конструктор
	Function(const double x0, const double u0, const int type) : type(type), x0(x0), u0(u0), c(answer_const(x0, u0, type)) { null_coordin(); }

	// Геттеры \\

	const double get_c()const { return c; }; // Возвращает константу c
	const double get_x()const { return x; }; // Возвращает x
	const double get_y()const { return y; }; // Возвращает y

	// Сеттеры \\

	void set_x(double x_new) { x = x_new; }; // Устанавливает новый x
	void set_y(double y_new) { y = y_new; }; // Устанавливает новый y
	void null_coordin() { x = x0; y = u0; }; // Сбрасывает текущие координинаты в начальные

	// Остальные методы
	double function_diff()const;                                                    // Возвращает f(xn,yn)
	double answer()const;                                                           // Возвращает u(xn)
	void answer_grafic(const int n, double tay);                                    // Строит график Интеграла ДУ
	friend void out_dot(Function& fun, std::ofstream& out_x, std::ofstream& out_y); // Для вывода точки y(x)
	friend void out_dot(double, double, std::ofstream&, std::ofstream&);            // Для вывода точки u(x)
};