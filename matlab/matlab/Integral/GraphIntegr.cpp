#include "GraphIntegr.h"
#include "Params.h"
#include "Integral Math/integr_math.h"

System::Void matlab::GraphIntegr::Расчёт(System::Object^ sender, System::EventArgs^ e, double a, double b, double s, double num, double n)
{
	double x = a;
	double y;
		//Очистка графиков
		this->chart1->Series[0]->Points->Clear();

		//Построение графиков

		while (x <= b) {
			y = test_function(x, num);
			this->chart1->Series[0]->Points->AddXY(x, y);

			//График обычной функции

			y = test_function(x, num);
			this->chart1->Series[1]->Points->AddXY(x, y);

			x += s;
		}

		labRESULT1->Text = Convert::ToString(integral(a, b, num, n, 1));
		labRESULT2->Text = Convert::ToString(integral(a, b, num, n, 2));
		labRESULT3->Text = Convert::ToString(integral(a, b, num, n, 3));
		labRESULTR->Text = Convert::ToString(answer(a, b, num));
}
