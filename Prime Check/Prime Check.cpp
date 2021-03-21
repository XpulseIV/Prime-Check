//Welcome to the
//Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <thread>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

#include "hardcoding.h"
#include "IsNotSimplePrime.h"
#include "someTestThings.h"
#include "DeleteChars.h"

bool LongPrimeCheck(const unsigned long long checkNumber, const bool debug) {
	long long i = 0;
	long long j = 0;

	auto prime = false;

	const long long untilNumber = 1 + ceil(sqrt(checkNumber));

	auto* sieve = new bool[untilNumber];

	std::fill_n(sieve, untilNumber, 1);

	if (!HardcodedValues(checkNumber)) { return prime; } /// Do not run replace_if if checkNumber is divisible by a number in IsNotSimplePrime

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
	return prime;
}

bool PrimeCheck(const long checkNumber, const bool debug)
{
	auto i = 0;
	auto j = 0;

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
	return prime;
}

int main() {
	bool prime = false;
	auto debug = false;

	std::string input;

	// Outputting things for visuals
	std::cout << '\n' <<"===========================================================" << '\n';
	std::cout << "Super Omega Prime Check Deluxe Of Doom From Hell And Beyond" << '\n';
	std::cout << "Enter number: ";

	std::getline(std::cin, input);

	if (input.rfind("debug ", 0) == 0) { debug = true; } // Debug allows you to see what is going, at the cost of speed

	// Removes any characters from string
	input = RemoveChars(input);
	
	if (input.empty()) {
		/// Close the program if there are no numbers
		std::cout << "Error: no numbers found";
		std::cout << '\n' << "===========================================================" << '\n';
		return 1;
	}

	// Getting numbers from input
	const auto checkNumber = std::stoull(input);

	// Actually checking if the number is a prime
	if (checkNumber > 2147483647)
	{
		std::cout << "Running long prime check, expect wait times up to 2 hours depending on number size" << '\n';
		prime = LongPrimeCheck(checkNumber, debug); /// LongPrimeCheck is faster, but requires a high number to function
	}
	else
	{
		prime = PrimeCheck(checkNumber, debug);
	}

	if (prime) {
		std::cout << std::endl << checkNumber << " is a prime";
	}
	else {
		std::cout << std::endl << checkNumber << " is not a prime";
	}
	
	std::cout << '\n' << "===========================================================" << '\n';
	return 0;
}