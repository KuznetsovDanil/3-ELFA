#include "diffur.h"

void diff_methods(Function& fun, const int n, double tay, int method){
	std::ofstream out_x("file_x.txt");
	std::ofstream out_y("file_y.txt");
	switch (method)
	{
	case 1:
		// ����� ������ (����� �������) \\

		fun.set_y(tay * fun.function_diff()); // y = y(x_start)
		for (int i = 0; i < n; i++) {
			fun.out_dot(out_x, out_y, APPROCSIMATION);
			fun.set_y(fun.get_y() + tay * fun.function_diff());
			fun.set_x(fun.get_x() + tay);
		}
	}
	out_x.close();
	out_y.close();
	fun.null_coordin();
}