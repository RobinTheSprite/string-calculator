//
// Created by Mark on 2/13/2019.
//
#include <string>
#include <sstream>
#include "strcalc.h"

int strcalc(std::string s)
{
    int answer;
    std::stringstream singleNumberTest(s);
    if (s.empty())
    {
        answer = 0;
    }
    else if (singleNumberTest)
    {
        singleNumberTest >> answer;
    }

    return answer;
}