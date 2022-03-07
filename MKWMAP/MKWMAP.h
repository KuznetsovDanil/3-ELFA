#pragma once

#include"MyForm.h"
#include<math.h>

#define DMAX pow(1.7976931348623158,pow(10,308))

																												//Функция для оповещения о некорректно введённом символе
void MKWMAP::MyForm::MKWER() {
	System::Windows::Forms::MessageBox::Show("Введён некорректный символ, подсчёт может оказаться не верным или может произойти краш программы.", "Внимание!");
}
																												//Функция модуля
double MKabs(double z) {
	if (z > 0) return z;
	if (z < 0) return -z;
	if (z == 0) return 0;
}
																												//Функция расчёта интеграла
long double MKWMAP::MyForm::MKWIntg(System::Windows::Forms::TextBox^ t, double x, double a, double b, double s) {

	long double F = MKWMAP::MyForm::MKWFUNC(t, (a+b)/2);


	return 0;
}

																												//Функция чтения и подсчёта формулы интеграла
long double MKWMAP::MyForm::MKWFUNC(System::Windows::Forms::TextBox^ t, long double Qsi) {

	long double F = 0;

	const int c = 19;
	wchar_t ch[c] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ',', '+', '-', '*', '/', '^', '(', ')', 'x' };

	for (int i = 0; i < t->TextLength; i++)
		for(int j = 0; j < c; j++)
			if (System::Convert::ToString(t->Text)[j] == ch[j]) {
				//12.3+3.21*x/(2^(3))
				switch (j)
				{
				case 0: {
					F = F*10;
					break;
				}
				case 1: {
					F = F*10 + 1;
					break;
				}
				case 2: {
					F = F*10 + 2;
					break;
				}
				case 3: {
					F = F*10 + 3;
					break;
				}
				case 4: {
					F = F*10 + 4;
					break;
				}
				case 5: {
					F = F*10 + 5;
					break;
				}
				case 6: {
					F = F*10 + 6;
					break;
				}
				case 7: {
					F = F*10 + 7;
					break;
				}
				case 8: {
					F = F*10 + 8;
					break;
				}
				case 9: {
					F = F*10 + 9;
					break;
				}
				case 10: {
					F = F + MKWZP(t, i);
					break;
				}
				case 11: {
					F = F + MKWFUNC(t, Qsi, i);
					break;
				}
				case 12: {
					F = F - MKWFUNC(t, Qsi, i);
					break;
				}
				case 13: {
					F = F * MKWFUNC(t, Qsi, i);
					break;
				}
				case 14: {
					F = F / MKWFUNC(t, Qsi, i);
					break;
				}
				case 15: {
					F = MKWpow(t, Qsi, i);
					break;
				}
				case 16: {
					F = MKWSQB(t, Qsi, i, F);
					break;
				}
				case 17: {
					//error
					break;
				}
				case 18: {
					F = MKWQsi(t, F, Qsi, i);
					break;
				}
				default:
					MKWER();
					return F;
					break;
				}
				break;
			}
	return F;
}

																												//Функция для Qsi завершена
long double MKWMAP::MyForm::MKWQsi(System::Windows::Forms::TextBox^ t, long double F, long double Qsi, int& i) {

	if (i == 0) {
		return Qsi;
	}
	else if (i > 0) {
		if (System::Convert::ToString(t->Text)[i - 1] == '+') {
			return F + Qsi;
		}
		if (System::Convert::ToString(t->Text)[i - 1] == '-') {
			return F - Qsi;
		}
		if (System::Convert::ToString(t->Text)[i - 1] == '*') {
			return F * Qsi;
		}
		if (System::Convert::ToString(t->Text)[i - 1] == '/') {
			return F / Qsi;
		}
		if (System::Convert::ToString(t->Text)[i - 1] == '^') {
			return F = MKWpow(t, Qsi, i);
		}
	}
}

																												//Вторичная функция чтения и подсчёта формулы интеграла
long double MKWMAP::MyForm::MKWFUNC(System::Windows::Forms::TextBox^ t, long double Qsi, int& i) {
	//Старая версия
	//long double F = 0, s = 0;
	//const int c = 19;
	//wchar_t ch[c] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ',', '+', '-', '*', '/', '^', '(', ')', 'x' };
	//for (int i = 0; i < t->TextLength; i++)
	//	for (int j = 0; j < c; j++)
	//		if (System::Convert::ToChar(t->Text) == ch[j]) {
	//			switch (j)
	//			{
	//			case 0: {
	//				s = s * 10;
	//				break;
	//			}
	//			case 1: {
	//				s = s * 10 + 1;
	//				break;
	//			}
	//			case 2: {
	//				s = s * 10 + 2;
	//				break;
	//			}
	//			case 3: {
	//				s = s * 10 + 3;
	//				break;
	//			}
	//			case 4: {
	//				s = s * 10 + 4;
	//				break;
	//			}
	//			case 5: {
	//				s = s * 10 + 5;
	//				break;
	//			}
	//			case 6: {
	//				s = s * 10 + 6;
	//				break;
	//			}
	//			case 7: {
	//				s = s * 10 + 7;
	//				break;
	//			}
	//			case 8: {
	//				s = s * 10 + 8;
	//				break;
	//			}
	//			case 9: {
	//				s = s * 10 + 9;
	//				break;
	//			}
	//			case 10: {
	//				//функция запятой
	//				break;
	//			}
	//			case 11: {
	//				F = F + MKWFUNC(t, Qsi, i);
	//				s = 0;
	//				break;
	//			}
	//			case 12: {
	//				F = F - MKWFUNC(t, Qsi, i);
	//				s = 0;
	//				break;
	//			}
	//			case 13: {
	//				F = F * MKWFUNC(t, Qsi, i);
	//				break;
	//			}
	//			case 14: {
	//				F = F / MKWFUNC(t, Qsi, i);
	//				break;
	//			}
	//			case 15: {
	//				F = MKWpow(t, Qsi, i);
	//				break;
	//			}
	//			case 16: {
	//				//Функция скобок
	//				break;
	//			}
	//			case 17: {
	//				//error
	//				break;
	//			}
	//			case 18: {
	//				//qsi
	//				break;
	//			}
	//			default:
	//				//Введён нечитаемый символ
	//				break;
	//			}
	//			break;
	//		}
	//return F;

	long double F = 0;

	const int c = 19;
	wchar_t ch[c] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ',', '+', '-', '*', '/', '^', '(', ')', 'x' };

	for (i; i < t->TextLength; i++)
		for (int j = 0; j < c; j++)
			if (System::Convert::ToString(t->Text)[i] == ch[j]) {
				switch (j)
				{
				case 0: {
					F = F * 10;
					break;
				}
				case 1: {
					F = F * 10 + 1;
					break;
				}
				case 2: {
					F = F * 10 + 2;
					break;
				}
				case 3: {
					F = F * 10 + 3;
					break;
				}
				case 4: {
					F = F * 10 + 4;
					break;
				}
				case 5: {
					F = F * 10 + 5;
					break;
				}
				case 6: {
					F = F * 10 + 6;
					break;
				}
				case 7: {
					F = F * 10 + 7;
					break;
				}
				case 8: {
					F = F * 10 + 8;
					break;
				}
				case 9: {
					F = F * 10 + 9;
					break;
				}
				case 10: {
					F = F + MKWZP(t, i);
					break;
				}
				case 11: {
					i++;
					F = F + MKWFUNC(t, Qsi, i);
					return F;
					break;
				}
				case 12: {
					i++;
					F = F - MKWFUNC(t, Qsi, i);
					return F;
					break;
				}
				case 13: {
					i++;
					F = F * MKWFUNC(t, Qsi, i);
					return F;
					break;
				}
				case 14: {
					i++;
					F = F / MKWFUNC(t, Qsi, i);
					return F;
					break;
				}
				case 15: {
					F = MKWpow(t, Qsi, i);
					return F;
					break;
				}
				case 16: {
					F = MKWSQB(t, Qsi, i, F);
					break;
				}
				case 17: {
					//error
					break;
				}
				case 18: {
					F = MKWQsi(t, F, Qsi, i);
					break;
				}
				default:
					MKWER();
					return F;
					break;
				}
				break;
			}
	return F;
}

																												//Функция обработки степени
long double MKWMAP::MyForm::MKWpow(System::Windows::Forms::TextBox^ t, long double Qsi, int& i) {
	i++;
	return MKWFUNC(t, Qsi, i);
}

																												//Функция чтения чисел после запятой завершена
long double MKWMAP::MyForm::MKWZP(System::Windows::Forms::TextBox^ t, int& i) {

	long double F = 0;
	int q = 1;

	const int c = 19;
	wchar_t ch[c] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ',', '+', '-', '*', '/', '^', '(', ')', 'x'/*, 's', 'i', 'n', 'c', 'o', 'l', 'o', 'g'*/ };

	for (int i = 0; i < t->TextLength; i++)
		for (int j = 0; j < c; j++)
			if (System::Convert::ToString(t->Text)[i] == ch[j]) {
				//12.3+3.21*x/(2^(3))
				switch (j)
				{
				case 0: {;
					q++;
					break;
				}
				case 1: {
					F = F + 1 * pow(10, -q);
					q++;
					break;
				}
				case 2: {
					F = F + 2 * pow(10, -q);
					q++;
					break;
				}
				case 3: {
					F = F + 3 * pow(10, -q);
					q++;
					break;
				}
				case 4: {
					F = F + 4 * pow(10, -q);
					q++;
					break;
				}
				case 5: {
					F = F + 5 * pow(10, -q);
					q++;
					break;
				}
				case 6: {
					F = F + 6 * pow(10, -q);
					q++;
					break;
				}
				case 7: {
					F = F + 7 * pow(10, -q);
					q++;
					break;
				}
				case 8: {
					F = F + 8 * pow(10, -q);
					q++;
					break;
				}
				case 9: {
					F = F + 9 * pow(10, -q);
					q++;
					break;
				}
				default:
					return F;
					break;
				}
				break;
			}
	return F;
}

																												//Функция обработки скобок завершена
long double MKWMAP::MyForm::MKWSQB(System::Windows::Forms::TextBox^ t, long double Qsi, int& i, long double FUNC) {
	int cmd;
	if (System::Convert::ToString(t->Text)[i - 1] == '+') cmd = 1;
	else if (System::Convert::ToString(t->Text)[i - 1] == '-') cmd = 2;
	else if (System::Convert::ToString(t->Text)[i - 1] == '*') cmd = 3;
	else if (System::Convert::ToString(t->Text)[i - 1] == '/') cmd = 4;
	else if (System::Convert::ToString(t->Text)[i - 1] == '^') cmd = 5;

	i++;

	long double F = 0;

	const int c = 19;
	wchar_t ch[c] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ',', '+', '-', '*', '/', '^', '(', ')', 'x' };

	for (i; i < t->TextLength; i++)
		for (int j = 0; j < c; j++)
			if (System::Convert::ToString(t->Text)[i] == ch[j]) {
				switch (j)
				{
				case 0: {
					F = F * 10;
					break;
				}
				case 1: {
					F = F * 10 + 1;
					break;
				}
				case 2: {
					F = F * 10 + 2;
					break;
				}
				case 3: {
					F = F * 10 + 3;
					break;
				}
				case 4: {
					F = F * 10 + 4;
					break;
				}
				case 5: {
					F = F * 10 + 5;
					break;
				}
				case 6: {
					F = F * 10 + 6;
					break;
				}
				case 7: {
					F = F * 10 + 7;
					break;
				}
				case 8: {
					F = F * 10 + 8;
					break;
				}
				case 9: {
					F = F * 10 + 9;
					break;
				}
				case 10: {
					F = F + MKWZP(t, i);
					break;
				}
				case 11: {
					i++;
					F = F + MKWFUNC(t, Qsi, i);
					return F;
					break;
				}
				case 12: {
					i++;
					F = F - MKWFUNC(t, Qsi, i);
					return F;
					break;
				}
				case 13: {
					i++;
					F = F * MKWFUNC(t, Qsi, i);
					return F;
					break;
				}
				case 14: {
					i++;
					F = F / MKWFUNC(t, Qsi, i);
					return F;
					break;
				}
				case 15: {
					F = MKWpow(t, Qsi, i);
					return F;
					break;
				}
				case 16: {
					F = MKWSQB(t, Qsi, i, F);
					break;
				}
				case 17: {
					switch (cmd)
					{
					case 1: {
						return FUNC + F;
						break;
					}
					case 2: {
						return FUNC - F;
						break;
					}
					case 3: {
						return FUNC * F;
						break;
					}
					case 4: {
						return FUNC / F;
						break;
					}
					case 5: {
						return pow(FUNC, F);
						break;
					}
					default:
						break;
					}
					break;
				}
				case 18: {
					F = MKWQsi(t, F, Qsi, i);
					break;
				}
				default:
					MKWER();
					return F;
					break;
				}
				break;
			}
	return F;
}