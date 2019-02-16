//
// Created by Mark on 2/13/2019.
//
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <sstream>
#include "strcalc.h"


int strcalc(string s)
{
    int answer = 0;
    string delimiterComma = ",";
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
            delimiterComma = multiLineDelimiter;
            s = s.substr(s.find(']') + 1, string::npos);
        }
        else
        {
            delimiterComma = s[2];
            s = s.substr(3,string::npos);
        }
    }
    std::stringstream inputStream(s);
    if (inputStream && !s.empty())
    {

        int test;
        int firstNumber = 0, secondNumber = 0, thirdNumber = 0;
        bool firstNumberSet = false, secondNumberSet = false, thirdNumberSet = false;
        while(inputStream >> test)
        {
            if (test > 1000)
            {
                test = 0;
                if(!firstNumberSet)
                {
                    firstNumber = test;
                    firstNumberSet = true;
                    inputStream.get();
                    continue;
                }
                if(firstNumberSet && !secondNumberSet)
                {
                    secondNumber = test;
                    secondNumberSet = true;
                    inputStream.get();
                    continue;
                }
                if(!thirdNumberSet)
                {
                    thirdNumber = test;
                    break;
                }

            }else{
                if(!firstNumberSet)
                {
                    firstNumber = test;
                    firstNumberSet = true;
                    inputStream.get();
                    continue;
                }
                if(firstNumberSet && !secondNumberSet)
                {
                    secondNumber = test;
                    secondNumberSet = true;
                    inputStream.get();
                    continue;
                }
                if(!thirdNumberSet)
                {
                    thirdNumber = test;
                    break;
                }
            }
        }
        answer = firstNumber + secondNumber + thirdNumber;
    }

    return answer;
}