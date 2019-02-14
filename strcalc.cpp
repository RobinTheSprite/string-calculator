//
// Created by Mark on 2/13/2019.
//
#include <string>
#include <sstream>
#include "strcalc.h"

int strcalc(std::string s)
{
    int answer = 0;
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