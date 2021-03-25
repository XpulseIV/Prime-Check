//Welcome to the
//Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <thread>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

#include "hardcoding.h"
#include "IsNotSimplePrime.h"
#include "DeleteChars.h"

bool LongPrimeCheck(const unsigned long long checkNumber, const bool debug) {
	long long i = 0;
	long long j = 0;

	auto prime = false;

	const long long untilNumber = 1 + ceil(sqrt(checkNumber));

	auto* sieve = new bool[untilNumber];

	std::fill_n(sieve, untilNumber, 1);

	if (!HardcodedValues(checkNumber)) { return prime; } /// Do not do replace_if if checkNumber is divisible by a number in IsNotSimplePrime

	// The line below is what makes LongPrimeCheck faster
	std::replace_if(sieve + 46399, sieve + untilNumber, IsNotSimplePrime, 2);

	for (i = 46337; i < untilNumber; i++) {
		if (sieve[i]) {
			if (debug) { std::cout << "Prime: " << i << '\n'; }

			if (checkNumber % i == 0) {
				if (checkNumber != i) {
					prime = false;
					break;
				}
				else {
					prime = true;
				}
			}
			else {
				prime = true;
			}

			for (j = i * i; j < untilNumber; j += i) {
				sieve[j] = false;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}
	if (debug)
	{
		std::cout << "Primes are: " << std::endl;

		for (unsigned long long sieveIndex = 1; sieveIndex <= untilNumber; sieveIndex++)
		{
			if (sieve[sieveIndex])
			{
				std::cout << sieveIndex << std::endl;
			}
		}
	}

	return prime;
}

bool PrimeCheck(const int checkNumber, const bool debug)
{
	int i = 0;
	int j = 0;

	auto prime = false;

	const int untilNumber = 1 + ceil(sqrt(checkNumber));

	auto* sieve = new bool[untilNumber];

	std::fill_n(sieve, untilNumber, true);

	for (i = 2; i < untilNumber; i++)
	{
		if (sieve[i])
		{
			if (debug)
			{
				std::cout << "Prime: " << i << '\n';
			}

			if (checkNumber % i == 0)
			{
				if (checkNumber != i)
				{
					prime = false;
					break;
				}
				else
				{
					prime = true;
				}
			}
			else
			{
				prime = true;
			}

			for (j = i * i; j < untilNumber; j += i)
			{
				sieve[j] = false;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}

	if (debug)
	{
		std::cout << "Primes are: " << std::endl;

		for (unsigned long long sieveIndex = 1; sieveIndex <= untilNumber; sieveIndex++)
		{
			if (sieve[sieveIndex])
			{
				std::cout << sieveIndex << std::endl;
			}
		}
	}

	return prime;
}

int main() {
	bool prime;
	bool debug = false;
	unsigned long long checkNumber;
	int baseInt;

	std::string input;
	std::string base;

	// Outputting things for visuals
	std::cout << "\n===========================================================\n";
	std::cout << "Super Omega Prime Check Deluxe Of Doom From Hell And Beyond\n";
	std::cout << "Enter number: ";

	std::getline(std::cin, input);

	std::cout << "Enter the base of that number: ";

	std::getline(std::cin, base);

	if (base.empty()) {
		baseInt = 10;
	}
	else
	{
		baseInt = std::stoi(base);
	}

	if (input.rfind("debug ", 0) == 0) // Debug allows you to see what is going, at the cost of speed
	{
		debug = true;
		input = input.substr(6);
	}

	// Removes any characters from string
	if (baseInt == 10) {
		input = RemoveChars(input);

		if (input.empty()) {
			/// Close the program if there are no numbers
			std::cout << "Error: no numbers found";
			std::cout << "\n===========================================================\n";
			return 1;
		}
	}
	else
	{
		for (int charc = 0; charc <= input.length(); charc++)
		{
			if (!isdigit(input[charc]))
			{
				if (std::islower(input[charc]))
				{
					input[charc] = std::toupper(input[charc]);
				}

				else
				{
					continue;
				}
			}
		}
	}

	char* numberInCharArray = &input[0];

	if ((!baseInt == 10) == 0) {
		checkNumber = std::stoull(numberInCharArray, NULL, baseInt);
	}
	else
	{
		// Getting numbers from input
		checkNumber = std::stoull(input);
	}

	// Actually checking if the number is a prime
	if (checkNumber > 2147483647)
	{
		std::cout << "Running long prime check, expect wait times up to 2 hours depending on number size\n";
		prime = LongPrimeCheck(checkNumber, debug); /// LongPrimeCheck is faster, but requires a high number to function
	}
	else
	{
		prime = PrimeCheck(checkNumber, debug);
	}

	if (prime) {
		std::cout << '\n' << checkNumber << " is a prime";
	}
	else {
		std::cout << '\n' << checkNumber << " is not a prime";
	}

	std::cout << "\n===========================================================\n";

	std::cout << "Press any key to close\n";
	std::cin.get();
	return 0;
}