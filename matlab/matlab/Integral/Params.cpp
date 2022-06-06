#include "Params.h"
#include "GraphIntegr.h"

System::Void matlab::Params::OK(System::Object^ sender, System::EventArgs^ e)
{
	double a, b, s;
	int method;
	if (Check(textBoxA, textBoxB, Stepper, methodBox, s, method, a, b)) return;
	GraphIntegr^ FormInteger = gcnew GraphIntegr;
	FormInteger->Show();
	FormInteger->������(sender, e, a, b, s, System::Convert::ToString(comboBox1->Text), System::Convert::ToString(comboBox2->Text), System::Convert::ToInt64(methodBox->Text));
}

//������� �������� ����������� �����
bool matlab::Params::MKWCHECK(System::Windows::Forms::TextBox^ t) {
	for (int i = 0; i < (t->TextLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("��� ����� ������� ����� ���������� ������� �������, � �� �����.\0����� ������ ��������� �������.", "��������!");
			return true;
		}
	return false;
}
bool matlab::Params::MKWCHECK(System::Windows::Forms::ComboBox^ t) {
	for (int i = 0; i < (t->SelectionLength); i++)
		if ((t->Text)[i] == L'.' || (t->Text)[i] == L'*' || (t->Text)[i] == L'/') {
			MessageBox::Show("��� ����� ������� ����� ���������� ������� �������, � �� �����.\0����� ������ ��������� �������.", "��������!");
			return true;
		}
	return false;
}

//������� ��������
bool matlab::Params::Check(	System::Windows::Forms::TextBox^ ta,
							System::Windows::Forms::TextBox^ tb,
							System::Windows::Forms::TextBox^ ts,
							System::Windows::Forms::ComboBox^ tm,
							double& s, int& method , double& a, double& b) 	//�������� �� ���� ���� ������
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
		if (MKWCHECK(tm)) {
			return true;
		}
		//�������� ����������
		method = System::Convert::ToInt64(tm->Text);
		s = System::Convert::ToDouble(ts->Text);
		a = System::Convert::ToDouble(ta->Text);
		b = System::Convert::ToDouble(tb->Text);

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