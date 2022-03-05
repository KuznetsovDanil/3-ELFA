#include "MKWMAP.h"	//Библиотека с функцией вычесления интеграла и библиотекой окна
#include <Windows.h>																			
#include <string>

#include <iostream>

using namespace MKWMAP; // Название проекта

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

System::Void MKWMAP::MyForm::RASCHET_Click(System::Object^ sender, System::EventArgs^ e) {
}

System::Void MKWMAP::MyForm::OUTGraph_Click(System::Object^ sender, System::EventArgs^ e) {

	ClearOut();																					//Очистка экрана
																								//Проверка на ввод функции интегрирования
	if (textBoxGetInt->Text == L"") {
		MessageBox::Show("Вы не ввели функцию интегрирования", "Внимание!");
		return;
	}
																								//Проверка на ввод всех данных
	if (textBoxA->Text == L"" || textBoxB->Text == L"" || Stepper->Text == L"") DeffParams();
	else {
																								//Проверка на правильность ввода
		if (MKWCHECK(textBoxA)) {
			return;
		}
		if (MKWCHECK(textBoxB)) {
			return;
		}
		if (MKWCHECK(textBoxGetInt, 1)) {
			return;
		}
		if (MKWCHECK(Stepper)) {
			return;
		}
																								//Принятие переменных
		a = System::Convert::ToDouble(textBoxA->Text);
		b = System::Convert::ToDouble(textBoxB->Text);
		x = a;
		s = System::Convert::ToDouble(Stepper->Text);
	}
																								//Очистка графиков
	this->chart->Series[0]->Points->Clear();

																								//Построение графиков

	while (x <= b) {
		y = x;
		this->chart->Series[0]->Points->AddXY(x, y);

		//График обычной функции
		
		y = Math::Cos(x);
		this->chart->Series[1]->Points->AddXY(x, y);

		this->progressBar1->Increment(abs((long long int)(a-b))/s);
		x += s;
	}

	this->progressBar1->Increment(-100);
}
																								//Функции очистки экрана при изменении значений в полях
System::Void MKWMAP::MyForm::textBoxA_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	ClearOut();
}

System::Void MKWMAP::MyForm::textBoxB_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	ClearOut();
}

System::Void MKWMAP::MyForm::Stepper_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	ClearOut();
}

System::Void MKWMAP::MyForm::textBoxGetInt_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	ClearOut();
}
																								//Подстановка дефолтных значений
void MKWMAP::MyForm::DeffParams()
{
	MessageBox::Show("Вы не указали какой-то из параметров, поэтому будут использованы параметры по умолчанию.", "Внимание!");

	a = -10;
	b = 10;
	x = a;
	s = 0.1;
}
																								//Функция очистки экрана
void MKWMAP::MyForm::ClearOut()
{
	this->labRESULT->Text = L"No result";
	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();
}
																								//Функция проверка корректного ввода
bool MKWMAP::MyForm::MKWCHECK(System::Windows::Forms::TextBox^ t) {
	for (int i = 0; i < (t->TextLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("При вводе дробных чисел необходимо ставить запятую, а не точку.\0Могли ввести ошибочные символы.", "Внимание!");
			return true;
		}
	return false;
}
																								//Функция проверки коректного ввода интеграла
bool MKWMAP::MyForm::MKWCHECK(System::Windows::Forms::TextBox^ t, bool l) {
	const int c = 18;
	wchar_t ch[c] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'+', L'-', L'*', L'/', L'^', L'(', L')', L'x'};

	bool flag = false;

	for (int i = 0; i < (t->TextLength); i++) {
		for (int j = 0; j < c; j++) {
			if ((t->Text)[i] == ch[j]) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			MessageBox::Show("При вводе интегралла можно использовать только символы: \nот 0 до 9 , * , / , ^ , + , - , ( , ) , x .", "Внимание!");
			return true;
		}
		flag = false;
	}
	return false;
}