#pragma once
//#include <iostream>
#include <map>
#include <stack>
#include <functional>
#include <utility>
#include <stdlib.h>
#include <string>
#include <corecrt_math_defines.h>
#include <cmath>
namespace INTEGRAL_PARS {
	class parser
	{
	public:
		parser();
		~parser();
		double PARS(std::string, double);
		double PARS(std::string, double, double);

	private:
		double pars(char*);
	};
}