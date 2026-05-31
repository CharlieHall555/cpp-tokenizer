#include "stringutil.h"
#include <string>
#include <list>
#include <set>
#include <sstream>
#include <iostream>
using namespace std;

namespace stringutil
{

    string strip(std::string input, char stripChar)
    {

        int startpos = 0;
        int endpos = input.length();

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] != stripChar){
                startpos = i;
                break;
            }
            
        }

        for (int j = input.length() - 1; j >= 0; j--)
        {
           if (input[j] != stripChar){
                endpos = j;
                break;
            }
        }

        return input.substr(startpos , (endpos-startpos+1));
    }

} // namespace stringutil

