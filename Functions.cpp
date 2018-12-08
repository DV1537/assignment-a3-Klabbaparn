#include "Functions.h"


bool hasValidChars(std::string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]) && s[i] != '.' && s[i] != '+' && s[i] != '-')
            return false;
    }
    return true;
}

int countOfChar(std::string s, char c)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == c)
            count++;
    return count;
}

