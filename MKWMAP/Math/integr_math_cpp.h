#pragma once

double integral(double a, double b, int num, int n, int method) {

	const double step = (b - a) / n;
	double res = 0;
	switch (method)
	{
	case 1:

		// ‘ормула серединных пр€моугольников (по сути интеграл по определению) \\
	
		/* ѕеременна€ i будет иметь роль произвольной точки "кси",
		подставл€емой из отрезка приращени€, которую мы всегда будем брать из
		середины отрезка приращени€, т.к. данна€ точка произвольна */

		// »нтегрирование слева навправо
		if (a < b)
			for (double i = a + step / 2; b - i > 0.0000001; i += step)
				res += test_function(i, num); /*  integral += fun(i)*step; ¬езде домножаетс€ на dx,
										оно у нас одно и тоже поэтому вынесем его */

		// »нтегрирование справа налево (в данном случае приращение будет отрицательным)
		else
			for (double i = a - step / 2; i - b > 0.0000001; i += step)
				res += test_function(i, num); /*  integral += fun(i)*step; ¬езде домножаетс€ на dx,
										оно у нас одно и тоже поэтому вынесем его */

		return res * step; // ”множаем на dx
		//----------------------------------------------------------------------\\

	case 2:

		// ‘ормула трапеции \\

		if (a < b)
			for (double i = a + step; b - i > step; i += step)
				res += test_function(i, num);

		// »нтегрирование справа налево (в данном случае приращение будет отрицательным)
		else
			for (double i = a + step; i - b > step; i += step)
				res += test_function(i, num);

		return (2 * res + test_function(a, num) + test_function(b, num)) * step / 2;
		//------------------\\

	case 3:
		// ‘ормула —импсона \\
		
		//bool flag; можно воспользоватьс€ флагом дл€ отслеживани€ четности номера
		double res2 = 0;
		
		if (a < b) {
			// — нечетными номерами
			for (double i = a + step; b - i > step; i += 2 * step)
				res += test_function(i, num);

			// — четными номерами
			for (double i = a + 2 * step; b - i > step; i += 2 * step)
				res2 += test_function(i, num);
		}
		// »нтегрирование справа налево (в данном случае приращение будет отрицательным)
		else {
			// — нечетными номерами
			for (double i = a + step; i - b > step; i += 2 * step)
				res += test_function(i, num);

			// — четными номерами
			for (double i = a + 2 * step; i - b > step; i += 2 * step)
				res2 += test_function(i, num);
		}

		return (res * 4 + res2 * 2 + test_function(a, num) + test_function(b, num)) * step / 3;
		//------------------\\

	}
	

}