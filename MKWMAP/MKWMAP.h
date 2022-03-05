#pragma once

#include"MyForm.h"
#include<math.h>

#define DMAX pow(1.7976931348623158,pow(10,308))
																								//Функция модуля
double MKabs(double z) {
	if (z > 0) return z;
	if (z < 0) return z;
	if (z == 0) return 0;
}
																								//Функция расчёта интеграла
double MKWIntg(double x, double a, double b, double s) {
																								//Задние n отрезков
	double* X;
	int n = DMAX;
	X = new double[n];
	for (int i = 0; i < n; i++) {
		if (i != 0)	X[i] = a + MKabs(b - a) / i;
		else X[i] = a;
		if (i == n - 1) X[i] = b;
	}

	long double* Qsi;
	Qsi = new long double[n];
																								//Задание Кси и dx
	double* dX;
	dX = new double[n];
	for (int i = 1; i < n; i++) {
		dX[i] = X[i] - X[i - 1];

		Qsi[i] = (X[i] - X[i - 1]) / 2;
	}
	return 0;
}
																								//Функция чтения формулы интеграла
long double MKWMAP::MyForm::MKWFUNC(System::Windows::Forms::TextBox^ t, long double Qsi) {

	long double F = 0;

	const int c = 19;
	wchar_t ch[c] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ',', '+', '-', '*', '/', '^', '(', ')', 'x' };

	for (int i = 0; i < t->TextLength; i++)
		for(int j = 0; j < c; j++)
			if (System::Convert::ToChar(t->Text) == ch[j]) {
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
					//функция запятой
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
					F = pow(F, MKWFUNC(t, Qsi, i));
					break;
				}
				case 16: {
					//Функция скобок
					break;
				}
				case 17: {
					//error
					break;
				}
				case 18: {
					//qsi
					break;
				}
				default:
					//Введён нечитаемый символ
					break;
				}
				break;
			}
	return F;
}

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

	for (int i = 0; i < t->TextLength; i++)
		for (int j = 0; j < c; j++)
			if (System::Convert::ToChar(t->Text) == ch[j]) {
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
					//функция запятой
					break;
				}
				case 11: {
					//F = F + MKWFUNC(t, Qsi, i);
					i--;
					return F;
					break;
				}
				case 12: {
					//F = F - MKWFUNC(t, Qsi, i);
					i--;
					return F;
					break;
				}
				case 13: {
					//F = F * MKWFUNC(t, Qsi, i);
					i--;
					return F;
					break;
				}
				case 14: {
					//F = F / MKWFUNC(t, Qsi, i);
					i--;
					return F;
					break;
				}
				case 15: {
					//F = pow(F, MKWFUNC(t, Qsi, i));
					i--;
					return F;
					break;
				}
				case 16: {
					//Функция скобок
					break;
				}
				case 17: {
					//error
					break;
				}
				case 18: {
					//qsi
					break;
				}
				default:
					//Введён нечитаемый символ
					break;
				}
				break;
			}
	return F;
}

long double MKWMAP::MyForm::MKWpow(System::Windows::Forms::TextBox^ t, long double Qsi, int& i) {
	return Qsi;

}