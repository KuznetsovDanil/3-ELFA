#include "integr_math.h"
#include "function.h"

double integral(double a, double b, int c, int n, int method) {

	const double step = (b - a) / n;
	double res = 0;
	switch (method)
	{
	case 1:

		// Формула серединных прямоугольников (по сути интеграл по определению) \\
	
	/* Переменная i будет иметь роль произвольной точки "кси",
		подставляемой из отрезка приращения, которую мы всегда будем брать из
		середины отрезка приращения, т.к. данная точка произвольна */

		// Интегрирование слева навправо
		if (a < b)
			for (double i = a + step / 2; b - i > 0.0000001; i += step)
				res += test_function(i, c); /*  integral += fun(i)*step; Везде домножается на dx,
										оно у нас одно и тоже поэтому вынесем его */

										// Интегрирование справа налево (в данном случае приращение будет отрицательным)
		else
			for (double i = a - step / 2; i - b > 0.0000001; i += step)
				res += test_function(i, c); /*  integral += fun(i)*step; Везде домножается на dx,
										оно у нас одно и тоже поэтому вынесем его */

		return res * step; // Умножаем на dx
		//----------------------------------------------------------------------\\

	case 2:

		// Формула трапеции \\

		if (a < b)
		for (double i = a + step; b - i > step; i += step)
			res += test_function(i, c);

		// Интегрирование справа налево (в данном случае приращение будет отрицательным)
		else
		for (double i = a + step; i - b > step; i += step)
			res += test_function(i, c);

		return (2 * res + test_function(a, c) + test_function(b, c)) * step / 2;
		//------------------\\

	//case 3:
		// Формула Симпсона\\
		
		//------------------\\

	}
	

}