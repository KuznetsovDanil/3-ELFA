#include "MainPage.h"

System::Void MKWMAP::MainPage::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyForm^ Integr = gcnew MyForm;
    Integr->Show();
}

System::Void MKWMAP::MainPage::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    DiffUr^ Dif = gcnew DiffUr;
    Dif->Show();
}
