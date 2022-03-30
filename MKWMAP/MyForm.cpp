#include "MKWFormLib.h"
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