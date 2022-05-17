#include "MyForm.h"

System::Void Project1::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e){
	double x0, u0, a, b, tay;
	int method, type;
	x0 = 5;
	u0 = 34;
	a = 0.1;
	b = 10;
	tay = 0.5;
	method = 1;
	type = 1;

	Function fun(x0, u0, type, a);
	label2->Text = Convert::ToString(fun.get_c());

	const int n = ceil((b - a) / tay);

	fun.answer_grafic(n, tay);
	diff_methods(fun, n, tay, method);

	//backgroundWorker1->RunWorkerAsync();

	return System::Void();
}

//System::Void Project1::MyForm::backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e){
//	fun.answer_grafic(n, tay);
//	diff_methods(fun, n, tay, method);
//	return System::Void();
//}

// Вывод точки в файл и на график
//void Project1::MyForm::out_dot(Function& fun, std::ofstream& out_x, std::ofstream& out_y, bool key) {
//	out_x << fun.get_x() << "\n";
//	out_y << fun.get_y() << "\n";
//	chart->Series[key ? INTERGAL_DY : APPROCSIMATION]->Points->AddXY(fun.get_x(), fun.get_y());
//}