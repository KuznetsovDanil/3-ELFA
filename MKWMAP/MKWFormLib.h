#pragma once

//���������� ������� ��������������

#include "MKWMAP.h"	//���������� � �������� ���������� ��������� � ����������� ����
#include "MyForm.h"
#include "ParamLib.h"

System::Void MKWMAP::MyForm::RASCHET_Click(System::Object^ sender, System::EventArgs^ e) {
	labRESULT1->Text = Convert::ToString(integral(a, b, num, n, 1));
	labRESULT2->Text = Convert::ToString(integral(a, b, num, n, 2));
	labRESULT3->Text = Convert::ToString(integral(a, b, num, n, 3));
	labRESULTR->Text = Convert::ToString(answer(a, b, num));
	MessageBox::Show("������ �������.", "��������!");
}

System::Void MKWMAP::MyForm::OUTGraph_Click(System::Object^ sender, System::EventArgs^ e) {

	ClearOut();																					//������� ������

	if (s == 0) DeffParams();

	//������� ��������
	this->chart->Series[0]->Points->Clear();

	//���������� ��������

	while (x <= b) {
		y = test_function(x, num);
		this->chart->Series[0]->Points->AddXY(x, y);

		//������ ������� �������

		y = test_function(x, num);
		this->chart->Series[1]->Points->AddXY(x, y);

		x += s;
	}

	x = a;
}

System::Void MKWMAP::MyForm::ClearOut(System::Object^ sender, System::EventArgs^ e) {
	ClearOut();
}

////������� ������� ������ ��� ��������� �������� � �����
//System::Void MKWMAP::MyForm::textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
//{
//	ClearOut();
//}

//����������� ��������� ��������
void MKWMAP::MyForm::DeffParams()
{
	MessageBox::Show("�� �� ������� �����-�� �� ����������, ������� ����� ������������ ��������� �� ���������.", "��������!");

	s = 0.1;
	a = -10 + s;
	b = 10 + s;
	x = a;
}

//������� ������� ������
void MKWMAP::MyForm::ClearOut()
{
	this->labRESULT1->Text = L"���������";
	this->labRESULT2->Text = L"���������";
	this->labRESULT3->Text = L"���������";
	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();
}

//������� �������� ���� ����������
void MKWMAP::MyForm::Open_Param_Window(System::Object^ sender, System::EventArgs^ e)
{
	Params^ form = gcnew Params;
	form->Show();
}