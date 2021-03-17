#include <iostream>

std::string remChars(std::string checkString)
{
	// All letters in alphabet (Uppercase)
	checkString.erase(remove(checkString.begin(), checkString.end(), 'A'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'B'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'C'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'D'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'E'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'F'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'G'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'H'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'I'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'J'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'K'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'L'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'M'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'N'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'O'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'P'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'Q'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'R'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'S'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'T'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'U'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'V'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'W'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'X'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'Y'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'Z'), checkString.end());

	// All letters in alphabet (Lowercase)
	checkString.erase(remove(checkString.begin(), checkString.end(), 'a'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'b'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'c'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'd'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'e'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'f'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'g'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'h'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'i'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'j'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'k'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'l'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'm'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'n'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'o'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'p'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'q'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'r'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 's'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 't'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'u'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'v'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'w'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'x'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'y'), checkString.end());
	checkString.erase(remove(checkString.begin(), checkString.end(), 'z'), checkString.end());

	return checkString;
}