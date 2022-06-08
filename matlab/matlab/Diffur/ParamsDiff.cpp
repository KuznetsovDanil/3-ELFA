#include "ParamsDiff.h"
#include "GraphDiffur.h"

System::Void matlab::Params1::OK(System::Object^ sender, System::EventArgs^ e)
{
	if (comboBox4->SelectedIndex == -1) { MessageBox::Show("�� �� ������� �����.", "��������!"); return; }

	if(Check(textBoxA, textBoxB, textBoxX0, textBoxY0, textBoxS)) return;

	GraphDiffur^ Diffur = gcnew GraphDiffur;
	Diffur->Show();
	Diffur->������(sender, e,
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


//������� �������� ����������� �����
bool matlab::Params1::MKWCHECK(System::Windows::Forms::TextBox^ t) {
	for (int i = 0; i < (t->TextLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("��� ����� ������� ����� ���������� ������� �������, � �� �����.\0����� ������ ��������� �������.", "��������!");
			return true;
		}
	return false;
}
bool matlab::Params1::MKWCHECK(System::Windows::Forms::ComboBox^ t) {
	for (int i = 0; i < (t->SelectionLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("��� ����� ������� ����� ���������� ������� �������, � �� �����.\0����� ������ ��������� �������.", "��������!");
			return true;
		}
	return false;
}

//������� ��������
bool matlab::Params1::Check(
	System::Windows::Forms::TextBox^ ta,
	System::Windows::Forms::TextBox^ tb,
	System::Windows::Forms::TextBox^ tx0,
	System::Windows::Forms::TextBox^ ty0,
	System::Windows::Forms::TextBox^ ts) 	//�������� �� ���� ���� ������
{
	if (ta->Text == L"" || tb->Text == L"" || ts->Text == L"")
		MessageBox::Show("�� �� ������� �����-�� �� ����������.", "��������!");
	else {
		//�������� �� ������������ �����
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

		//�������� ����������� ��������
		if (b < a) {
			MessageBox::Show("�� ����� ����������� �������� ���������� � � b.", "��������!");
			return true;
		}
		if (s <= 0) {
			MessageBox::Show("�� ����� ����������� �������� ���� �������, ��� ������ ���� ������ 0.", "��������!");
			return true;
		}
	}
	return false;
}