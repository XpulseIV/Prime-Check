#include <iostream>
#include <algorithm>

std::string RemoveChars(std::string checkString) {
	for (int i = 0; i < checkString.size(); i++) {
		if (!isdigit(checkString[i]))
		{
			checkString.erase(checkString.begin() + i);
			i--;
		}
	}
	return checkString;
}