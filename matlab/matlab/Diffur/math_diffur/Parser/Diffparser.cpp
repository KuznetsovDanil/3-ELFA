#include "Diffparser.h"

using namespace DIFFUR_PARS;

parser::parser()
{
}

double parser::PARS(std::string inLine, double x, double  y)
{
    std::string outLine;
    const int Length = inLine.length();
    char* Line = new char[Length];
    std::string func, argv;
    for (int i = 0; i < Length; i++) { Line[i] = inLine[i]; }
    for (int i = 0; i < Length;) {
        if (*Line == 's' ||
            *Line == 'c' ||
            *Line == 't') {

                {
                    while (*Line != '(') {
                        func += *Line;
                        ++Line; i++;
                    }
                    ++Line; i++;
                    while (*Line != ')') {
                        if (*Line == 'x'){
                            argv += std::to_string(x);
                        }
                        else if (*Line == 'y') {
                            argv += std::to_string(y);
                        }
                        else if (*Line == 'a') {
                            argv += std::to_string(x);
                        }
                        else if (*Line == 'b') {
                            argv += std::to_string(y);
                        }
                        else if (*Line == 'с') {
                            argv += std::to_string(y);
                        }
                        else {
                            argv += *Line;
                        }
                        ++Line; i++;
                    }
                    ++Line; i++;
                }

                char* CHargv = new char[argv.length() + 1];
                CHargv[argv.length()] = '\0';

                for (int j = 0; j < argv.length(); j++) { CHargv[j] = argv[j]; }

                if (func == "sin")          outLine += std::to_string(sin(pars(CHargv)));
                else if (func == "cos")     outLine += std::to_string(cos(pars(CHargv)));
                else if (func == "tg")      outLine += std::to_string(tan(pars(CHargv)));
                else if (func == "ctg")     outLine += std::to_string(pow(tan(pars(CHargv)),-1));
                else {
                    System::Windows::Forms::MessageBox::Show("Вы вы указали не верную функцию.", "Внимание!");
                }

                delete[] CHargv;
        }
        else if (*Line == 'l') {
            while (*Line != '(') {
                func += *Line;
                ++Line; i++;
            }
            ++Line; i++;

            if (func == "log") {

                while (*Line != ')') {
                    if (*Line == 'x') {
                        argv += std::to_string(x);
                    }
                    else if (*Line == 'y') {
                        argv += std::to_string(y);
                    }
                    else if (*Line == 'a') {
                        argv += std::to_string(x);
                    }
                    else if (*Line == 'b') {
                        argv += std::to_string(y);
                    }
                    else if (*Line == 'с') {
                        argv += std::to_string(y);
                    }
                    else {
                        argv += *Line;
                    }
                    ++Line; i++;
                }
                ++Line; i++;

                char* CHargv = new char[argv.length() + 1];
                CHargv[argv.length()] = '\0';

                for (int j = 0; j < argv.length(); j++) { CHargv[j] = argv[j]; }

                std::string argv2;

                
                while (*Line != '(') {
                    func += *Line;
                    ++Line; i++;
                }
                ++Line; i++;
                while (*Line != ')') {
                    if (*Line == 'x') {
                        argv2 += std::to_string(x);
                    }
                    else if (*Line == 'y') {
                        argv2 += std::to_string(y);
                    }
                    else if (*Line == 'a') {
                        argv2 += std::to_string(x);
                    }
                    else if (*Line == 'b') {
                        argv2 += std::to_string(y);
                    }
                    else if (*Line == 'с') {
                        argv += std::to_string(y);
                    }
                    else {
                        argv2 += *Line;
                    }
                    ++Line; i++;
                }
                ++Line; i++;
                

                char* CHargv2 = new char[argv2.length() + 1];
                CHargv2[argv2.length()] = '\0';

                for (int j = 0; j < argv2.length(); j++) { CHargv2[j] = argv2[j]; }

                outLine += std::to_string(log(pars(CHargv2)) / log(pars(CHargv)));


                delete[] CHargv2;
                delete[] CHargv;
            }
            else if (func == "ln") {

                {
                    while (*Line != ')') {
                        if (*Line == 'x') {
                            argv += std::to_string(x);
                        }
                        else if (*Line == 'y') {
                            argv += std::to_string(y);
                        }
                        else if (*Line == 'a') {
                            argv += std::to_string(x);
                        }
                        else if (*Line == 'b') {
                            argv += std::to_string(y);
                        }
                        else if (*Line == 'с') {
                            argv += std::to_string(y);
                        }
                        else {
                            argv += *Line;
                        }
                        ++Line; i++;
                    }
                    ++Line; i++;
                }

                char* CHargv = new char[argv.length() + 1];
                CHargv[argv.length()] = '\0';

                for (int j = 0; j < argv.length(); j++) { CHargv[j] = argv[j]; }

                outLine += std::to_string(log(pars(CHargv)));

                delete[] CHargv;
}
            else {/**/ }

        }
        else if (*Line == 'x') { while (*Line == 'x') { outLine += std::to_string(x); ++Line; i++; } }
        else if (*Line == 'y') { while (*Line == 'y') { outLine += std::to_string(y); ++Line; i++; } }
        else if (*Line == 'a') { while (*Line == 'a') { outLine += std::to_string(x); ++Line; i++; } }
        else if (*Line == 'b') { while (*Line == 'b') { outLine += std::to_string(y); ++Line; i++; } }
        else if (*Line == 'с') { while (*Line == 'с') { outLine += std::to_string(y); ++Line; i++; } }
        else if (*Line == 'e') {
            while (*Line == 'e') { outLine += std::to_string(M_E); ++Line; i++; }
        }
        else if (*Line == 'p') { while (*Line != 'i') { ++Line; i++; } outLine += std::to_string(M_PI); ++Line; i++; }
        else {
            outLine += *Line;
            ++Line; i++;
        }
        func = "";
        argv = "";
    }

    char* out = new char[outLine.length() + 1];
    for (int i = 0; i < outLine.length(); i++) { out[i] = outLine[i]; }
    out[outLine.length()] = '\0';

    return pars(out);
}

double parser::PARS(std::string inLine, double x)
{
    std::string outLine;
    const int Length = inLine.length();
    char* Line = new char[Length];
	std::string func, argv;
	for (int i = 0; i < Length; i++) {Line[i] = inLine[i];}
    for (int i = 0; i < Length;) {
        if (*Line == 's' ||
            *Line == 'c' ||
            *Line == 't') {

            {
                while (*Line != '(') {
                        func += *Line;
                        ++Line; i++;
                }
                ++Line; i++;
                while (*Line != ')') {
                    if (*Line == 'x') {
                        argv += std::to_string(x);
                    }
                    else{
                        argv += *Line;
                    }
                    ++Line; i++;
                }
                ++Line; i++;
            }

            char* CHargv = new char[argv.length() + 1];
            CHargv[argv.length()] = '\0';

            for (int j = 0; j < argv.length(); j++) { CHargv[j] = argv[j]; }

            if          (func == "sin")     outLine += std::to_string(sin(pars(CHargv)));
            else if     (func == "cos")     outLine += std::to_string(cos(pars(CHargv)));
            else if     (func == "tg")      outLine += std::to_string(tan(pars(CHargv)));
            else if     (func == "ctg")     outLine += std::to_string(atan(pars(CHargv)));
            else                            {
                System::Windows::Forms::MessageBox::Show("Вы вы указали не верную функцию.", "Внимание!");
            }

            delete[] CHargv;
        }
        else if (*Line == 'l') {
            while (*Line != '(') {
                func += *Line;
                ++Line; i++;
            }
            ++Line; i++;

            if (func == "log") {

                std::string argv2;

                {
                    while (*Line != '(') {
                        func += *Line;
                        ++Line; i++;
                    }
                    ++Line; i++;
                    while (*Line != ')') {
                        if (*Line == 'x') {
                            argv2 += std::to_string(x);
                        }
                        else {
                            argv2 += *Line;
                        }
                        ++Line; i++;
                    }
                    ++Line; i++;
                }

                char* CHargv2 = new char[argv2.length() + 1];
                CHargv2[argv2.length()] = '\0';

                for (int j = 0; j < argv2.length(); j++) { CHargv2[j] = argv2[j]; }

                {
                    while (*Line != '(') {
                        func += *Line;
                        ++Line; i++;
                    }
                    ++Line; i++;
                    while (*Line != ')') {
                        if (*Line == 'x') {
                            argv += std::to_string(x);
                        }
                        else {
                            argv += *Line;
                        }
                        ++Line; i++;
                    }
                    ++Line; i++;
                }

                char* CHargv = new char[argv.length() + 1];
                CHargv[argv.length()] = '\0';

                for (int j = 0; j < argv.length(); j++) { CHargv[j] = argv[j]; }

                outLine += std::to_string(log(pars(CHargv2)) / log(pars(CHargv)));


                delete[] CHargv2;
                delete[] CHargv;
            }
            else if (func == "ln") {

                {
                    while (*Line != ')') {
                        if (*Line == 'x') {
                            argv += std::to_string(x);
                        }
                        else {
                            argv += *Line;
                        }
                        ++Line; i++;
                    }
                }

                char* CHargv = new char[argv.length() + 1];
                CHargv[argv.length()] = '\0';

                for (int j = 0; j < argv.length(); j++) { CHargv[j] = argv[j]; }
                outLine += std::to_string(log(pars(CHargv)));
                delete[] CHargv;
            }
            else                            {
                System::Windows::Forms::MessageBox::Show("Вы вы указали не верную функцию.", "Внимание!");
            }

        }
        else if         (*Line == 'x')      { while (*Line == 'x') { outLine += std::to_string(x); ++Line; i++; } }
        else if (*Line == 'e') {
            while (*Line == 'e') { outLine += std::to_string(M_E); ++Line; i++; }
        }
        else if         (*Line == 'p')      { while (*Line != 'i') { ++Line; i++; } outLine += std::to_string(M_PI); ++Line; i++; }
        else{
            outLine += *Line;
            ++Line; i++;
        }
        func = "";
        argv = "";
    }

    char* out = new char[outLine.length() + 1];
    for (int i = 0; i < outLine.length(); i++) { out[i] = outLine[i]; }
    out[outLine.length()] = '\0';

    return pars(out);
}

parser::~parser()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////
//\\//\\//\\//\\//\\//\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
///////////////////////////////////////////////////////////////////////////////////////////////

double parser::pars(char* argv) {

    std::stack<double> s;  std::stack< std::pair<int, char> > ops;

    auto p = [&s, &ops](std::function<double(double, double)>& f)
    {
        double  r = s.top();
        s.pop();
        r = f(s.top(), r);
        s.pop();
        s.push(r);
        ops.pop();
    };

    std::map< char, std::pair< int, std::function<double(double, double)> > > m =
    {   {'+',{1,[](double a, double b) {return a + b; }}},
        {'-',{1,[](double a, double b) {return a - b; }}},
        {'*',{2,[](double a, double b) {return a * b; }}},
        {'/',{2,[](double a, double b) {return a / b; }}},

        {'^',{3,[](double a, double b) {return pow(a, b); }}}
    };

    const int order = 3; int level = 0;
    for (char* sp = argv;; ++sp) {
        while (*sp == '(') { level += order; ++sp; }

        s.push(strtod(sp, &sp));

        while (*sp == ')') { level -= order; ++sp; }

        if (!*sp) { while (!ops.empty()) p(m[ops.top().second].second); break; }

        const int op = m[*sp].first + level;
        while (!ops.empty() && ops.top().first >= op) p(m[ops.top().second].second);

        ops.push(std::make_pair(op, *sp));
    }

    return s.top();
}
///////////////////////////////////////////////////////////////////////////////////////////////
//\\//\\//\\//\\//\\//\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
///////////////////////////////////////////////////////////////////////////////////////////////