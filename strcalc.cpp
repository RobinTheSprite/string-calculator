//
// Created by Mark on 2/13/2019.
//
#include <string>
using std::string;
#include <sstream>
#include "strcalc.h"

int strcalc(string s)
{
    int answer = 0;
    string delimiter = ",";
    if (s.front() == '/' && *(begin(s) + 1) == '/')
    {
        delimiter = s[2];
        s = s.substr(3,string::npos);
    }
    std::stringstream singleNumberTest(s);
    if (singleNumberTest && !s.empty())
    {
        int test;
        singleNumberTest >> test;
        if (test <= 1000)
        {
            answer = test;
        }
    }

    return answer;
}