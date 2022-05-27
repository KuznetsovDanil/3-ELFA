#pragma once
#include <iostream>

class parser
{
public:
	parser();
	~parser();
	long double PARS(std::string, long double);

private:
	long double pars(char*);
};