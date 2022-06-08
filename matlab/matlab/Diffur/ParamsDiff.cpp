#include "ParamsDiff.h"
#include "GraphDiffur.h"

System::Void matlab::Params1::OK(System::Object^ sender, System::EventArgs^ e)
{
	if (comboBox4->SelectedIndex == -1) { MessageBox::Show("Вы не выбрали метод.", "Внимание!"); return; }

	if(Check(textBoxA, textBoxB, textBoxX0, textBoxY0, textBoxS)) return;

	GraphDiffur^ Diffur = gcnew GraphDiffur;
	Diffur->Show();
	Diffur->Расчёт(sender, e,
		Convert::ToDouble(textBoxA->Text),
		Convert::ToDouble(textBoxB->Text),
		Convert::ToDouble(textBoxX0->Text),
		Convert::ToDouble(textBoxY0->Text),
		Convert::ToDouble(textBoxS->Text),
		Convert::ToString(comboBox1->Text),
		Convert::ToString(comboBox2->Text),
		Convert::ToString(comboBox3->Text),
		Convert::ToInt64(comboBox1->SelectedIndex),
		Convert::ToInt64(comboBox4->SelectedIndex));
	return System::Void();
}


//Функция проверка корректного ввода
bool matlab::Params1::MKWCHECK(System::Windows::Forms::TextBox^ t) {
	for (int i = 0; i < (t->TextLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("При вводе дробных чисел необходимо ставить запятую, а не точку.\0Могли ввести ошибочные символы.", "Внимание!");
			return true;
		}
	return false;
}
bool matlab::Params1::MKWCHECK(System::Windows::Forms::ComboBox^ t) {
	for (int i = 0; i < (t->SelectionLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("При вводе дробных чисел необходимо ставить запятую, а не точку.\0Могли ввести ошибочные символы.", "Внимание!");
			return true;
		}
	return false;
}

//Функция проверки
bool matlab::Params1::Check(
	System::Windows::Forms::TextBox^ ta,
	System::Windows::Forms::TextBox^ tb,
	System::Windows::Forms::TextBox^ tx0,
	System::Windows::Forms::TextBox^ ty0,
	System::Windows::Forms::TextBox^ ts) 	//Проверка на ввод всех данных
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
		if (MKWCHECK(tx0)) {
			return true;
		}
		if (MKWCHECK(ty0)) {
			return true;
		}

		double a = Convert::ToDouble(ta->Text), b = Convert::ToDouble(tb->Text), s = Convert::ToDouble(ts->Text);

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