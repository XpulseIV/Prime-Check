#include <iostream>

std::string RemoveChars(std::string checkString) {
	for (int i = 0; i < checkString.size(); i++) {
		if (!isdigit(checkString[i]))
		{
			checkString.erase(checkString.begin() + i);
			i--; /// Because we have just decrased the length by 1, i is actually the next character already, so we subtract 1 so w don't miss any characters
		}
	}
	return checkString;
}