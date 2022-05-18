#include "Params.h"
#include "GraphIntegr.h"

System::Void matlab::Params::OK(System::Object^ sender, System::EventArgs^ e)
{
	double a, b, s, n;
	if (Check(textBoxA, textBoxB, Stepper, textBoxN, s, n, a, b)) return;
	GraphIntegr^ FormInteger = gcnew GraphIntegr;
	FormInteger->Show();
	FormInteger->Расчёт(sender, e, a, b, s, System::Convert::ToInt64(comboBox1->Text), n);
}

//Функция проверка корректного ввода
bool matlab::Params::MKWCHECK(System::Windows::Forms::TextBox^ t) {
	for (int i = 0; i < (t->TextLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("При вводе дробных чисел необходимо ставить запятую, а не точку.\0Могли ввести ошибочные символы.", "Внимание!");
			return true;
		}
	return false;
}

//Функция проверки
bool matlab::Params::Check(	System::Windows::Forms::TextBox^ ta,
							System::Windows::Forms::TextBox^ tb,
							System::Windows::Forms::TextBox^ ts,
							System::Windows::Forms::TextBox^ tn,
							double& s, double& n, double& a, double& b) 	//Проверка на ввод всех данных
{
	if (ta->Text == L"" || tb->Text == L"" || ts->Text == L"")
		MessageBox::Show("Вы не указали какой-то из параметров.", "Внимание!");
	else {
		//Проверка на правильность ввода
		if (MKWCHECK(ta)) {
			return true;
		}
		if (MKWCHECK(tb)) {
			return true;
		}
		if (MKWCHECK(ts)) {
			return true;
		}
		if (MKWCHECK(tn)) {
			return true;
		}
		//Принятие переменных
		n = System::Convert::ToDouble(tn->Text);
		s = System::Convert::ToDouble(ts->Text);
		a = System::Convert::ToDouble(ta->Text);
		b = System::Convert::ToDouble(tb->Text);

		//Проверка корректости значений
		if (b < a) {
			MessageBox::Show("Вы ввели некоректные значения параметров а и b.", "Внимание!");
			return true;
		}
		if (s <= 0) {
			MessageBox::Show("Вы ввели некоректное значение шага графика, оно должно быть больше 0.", "Внимание!");
			return true;
		}
	}
	return false;
}