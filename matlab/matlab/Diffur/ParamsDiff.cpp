#include "ParamsDiff.h"
#include "GraphDiffur.h"

System::Void matlab::Params1::OK(System::Object^ sender, System::EventArgs^ e)
{
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
