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

class parser
{
public:
	parser();
	~parser();
	long double PARS(std::string, long double);
	long double PARS(std::string, long double, long double);

private:
	long double pars(char*);
};