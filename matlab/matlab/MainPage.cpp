#include "MainPage.h"
#include "Integral/ParamsIntegr.h"
#include "Diffur/ParamsDiff.h"

System::Void matlab::MainPage::Интеграллы(System::Object^ sender, System::EventArgs^ e)
{
	Params^ FormParams = gcnew Params;
	FormParams->Show();
	return System::Void();
}

System::Void matlab::MainPage::Диффуры(System::Object^, System::EventArgs^)
{
	Params1^ FormParams = gcnew Params1;
	FormParams->Show();
	return System::Void();
}
