#include <iostream>

std::string Remove_Chars(std::string check_string)
{
    for (unsigned long long i = 0; i < check_string.size(); i++)
    {
        if (!isdigit(check_string[i]))
        {
            check_string.erase(check_string.begin() + i);
            i--; /// Because we have just decrased the length by 1, i is actually the next character already, so we subtract 1 so w don't miss any characters
        }
    }
    return check_string;
}
