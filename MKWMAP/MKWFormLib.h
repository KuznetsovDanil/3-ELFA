#pragma once

//Библиотека функций взаимодействия

#include "MKWMAP.h"	//Библиотека с функцией вычесления интеграла и библиотекой окна
#include "MyForm.h"
#include "ParamLib.h"

System::Void MKWMAP::MyForm::RASCHET_Click(System::Object^ sender, System::EventArgs^ e) {
	labRESULT1->Text = Convert::ToString(integral(a, b, num, n, 1));
	labRESULT2->Text = Convert::ToString(integral(a, b, num, n, 2));
	labRESULT3->Text = Convert::ToString(integral(a, b, num, n, 3));
	labRESULTR->Text = Convert::ToString(answer(a, b, num));
	MessageBox::Show("Расчёт окончен.", "Внимание!");
}

System::Void MKWMAP::MyForm::OUTGraph_Click(System::Object^ sender, System::EventArgs^ e) {

	ClearOut();																					//Очистка экрана

	if (s == 0) DeffParams();

	//Очистка графиков
	this->chart->Series[0]->Points->Clear();

	//Построение графиков

	while (x <= b) {
		y = test_function(x, num);
		this->chart->Series[0]->Points->AddXY(x, y);

		//График обычной функции

		y = test_function(x, num);
		this->chart->Series[1]->Points->AddXY(x, y);

		x += s;
	}

	x = a;
}

System::Void MKWMAP::MyForm::ClearOut(System::Object^ sender, System::EventArgs^ e) {
	ClearOut();
}

////Функция очистки экрана при изменении значений в полях
//System::Void MKWMAP::MyForm::textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
//{
//	ClearOut();
//}

//Подстановка дефолтных значений
void MKWMAP::MyForm::DeffParams()
{
	MessageBox::Show("Вы не указали какой-то из параметров, поэтому будут использованы параметры по умолчанию.", "Внимание!");

	s = 0.1;
	a = -10 + s;
	b = 10 + s;
	x = a;
}

//Функция очистки экрана
void MKWMAP::MyForm::ClearOut()
{
	this->labRESULT1->Text = L"Результат";
	this->labRESULT2->Text = L"Результат";
	this->labRESULT3->Text = L"Результат";
	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();
}

//Функция открытия окна параметров
void MKWMAP::MyForm::Open_Param_Window(System::Object^ sender, System::EventArgs^ e)
{
	Params^ form = gcnew Params;
	form->Show();
}