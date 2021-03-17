#include <iostream>
#include <vector>

std::string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::vector<char> v(s.begin(), s.end());

std::string remChars(std::string checkString) {
	for (int i = 0; i <= s.size(); i++) {
		checkString.erase(remove(checkString.begin(), checkString.end(), s[i]), checkString.end());

	}
	return checkString;
}