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
    if (s.substr(0,2) == "//")
    {
        if (s.find_first_of('[') == 2)
        {
            string multiLineDelimiter;
            for (auto c : s.substr(3, string::npos))
            {
                if(c == ']')
                {
                    break;
                }
                multiLineDelimiter.push_back(c);
            }
            delimiter = multiLineDelimiter;
            s = s.substr(s.find(']') + 1, string::npos);
        }
        else
        {
            delimiter = s[2];
            s = s.substr(3,string::npos);
        }
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