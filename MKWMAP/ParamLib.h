#pragma once
#include "Params.h"

void MKWMAP::Params::Translate(System::Object^ sender, System::EventArgs^ e) {

	if (Check(textBoxA, textBoxB, Stepper, textBoxN)) return;

	MyForm::n = Params::n;
	MyForm::s = Params::s;
	MyForm::a = Params::a;
	MyForm::b = Params::b;
	MyForm::x = MyForm::a;
	MyForm::num = System::Convert::ToInt64(comboBox1->Text);

	MessageBox::Show("Парметры были успешно изменены!", "Внимание!");
}

//Функция проверки
bool MKWMAP::Params::Check(System::Windows::Forms::TextBox^ ta, System::Windows::Forms::TextBox^ tb, System::Windows::Forms::TextBox^ ts, System::Windows::Forms::TextBox^ tn) 	//Проверка на ввод всех данных
{
	if (ta->Text == L"" || tb->Text == L"" || ts->Text == L"") DeffParams();
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
		a = System::Convert::ToDouble(ta->Text) + s;
		b = System::Convert::ToDouble(tb->Text) - s;

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

//Функция проверка корректного ввода
bool MKWMAP::Params::MKWCHECK(System::Windows::Forms::TextBox^ t) {
	for (int i = 0; i < (t->TextLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("При вводе дробных чисел необходимо ставить запятую, а не точку.\0Могли ввести ошибочные символы.", "Внимание!");
			return true;
		}
	return false;
}

//Подстановка дефолтных значений
void MKWMAP::Params::DeffParams()
{
	MessageBox::Show("Вы не указали какой-то из параметров, поэтому будут использованы параметры по умолчанию.", "Внимание!");

	n = 1000;
	a = -10;
	b = 10;
	s = 0.1;
}

////Функция проверки коректного ввода интеграла
//bool MKWMAP::MyForm::MKWCHECK(System::Windows::Forms::TextBox^ t, bool l) {
//	const int c = 18;
//	wchar_t ch[c] = { L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'+', L'-', L'*', L'/', L'^', L'(', L')', L'x' };
//
//	bool flag = false;
//
//	for (int i = 0; i < (t->TextLength); i++) {
//		for (int j = 0; j < c; j++) {
//			if ((t->Text)[i] == ch[j]) {
//				flag = true;
//				break;
//			}
//		}
//		if (!flag) {
//			MessageBox::Show("При вводе интегралла можно использовать только символы: \nот 0 до 9 , * , / , ^ , + , - , ( , ) , x .", "Внимание!");
//			return true;
//		}
//		flag = false;
//	}
//	return false;
//}