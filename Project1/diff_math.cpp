#include "math/diff.h"
void out_dot(double, double, ofstream&, ofstream&);

void diff_methods(double x, double y, const int n, double tay, int method, int fun) {
	const double c = answer_const(x, y, fun);
	cout << c;
	system("pause");
	ofstream out_x("file_x.txt");
	ofstream out_y("file_y.txt");

	switch (method)
	{
	case 1:
		// Метод Эйлера \\

		for (int i = 0; i < n; i++) {
			out_dot(x, y, out_x, out_y);
			y += tay * test_function(x, y, fun);
			x += tay;
		}
	}
	out_x.close();
	out_y.close();
}

void out_dot(double x, double y, ofstream& out_x, ofstream& out_y) {
	//out << "Точка #" << i << "\nx = " << x << "\ny = " << y << "\n";
	out_x << x << "\n";
	out_y << y << "\n";
}