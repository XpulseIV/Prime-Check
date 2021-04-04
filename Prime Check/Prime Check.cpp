/// Welcome to the
/// Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <thread>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>


#include "hardcoding.h"
#include "IsNotSimplePrime.h"
#include "DeleteChars.h"

bool LongPrimeCheck(const unsigned long long checkNumber, const bool debug) {
	long long i = 0;
	long long j = 0;

	auto prime = false;

	const long long untilNumber = 1 + ceil(sqrt(checkNumber));

	if (!HardcodedValues(checkNumber)) { return false; } // Do not do replace_if if checkNumber is divisible by a number in IsNotSimplePrime

	std::vector<bool> sieve(untilNumber);

	if ((untilNumber / 2) > 46400)
	{
		std::vector<bool> sieve1(untilNumber / 2); // Initialise a vector with zeros
		std::vector<bool> sieve2(untilNumber / 2); // Initialise a vector with zeros

		long long start = untilNumber / 2;

		std::thread t1(Replace, sieve1, 46399, start);
		std::thread t2(Replace, sieve2, start, untilNumber);

		t1.join();
		t2.join();

		sieve1.insert(sieve1.end(), sieve2.begin(), sieve2.end());

		sieve = sieve1;
	}
	else
	{
		sieve = Replace(sieve, 46399, untilNumber);
	}
	
	

	for (i = 46399; i < untilNumber; i++) {
		if (!sieve[i]) {
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
				sieve[j] = true;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}
	if (debug)
	{
		std::cout << "Primes are: " << std::endl;

		for (unsigned long long sieveIndex = 1; sieveIndex <= i; sieveIndex++)
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

	std::vector<bool> sieve(untilNumber);

	for (i = 2; i < untilNumber; i++)
	{
		if (!sieve[i])
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
				sieve[j] = true;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}

	}

	if (debug)
	{
		std::cout << "Primes are: " << std::endl;

		for (unsigned long long sieveIndex = 1; sieveIndex <= i; sieveIndex++)
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
	bool hex = false;
	unsigned long long checkNumber;

	std::string input;

	/// Outputting things for visuals
	std::cout << "\n===========================================================\n";
	std::cout << "Super Omega Prime Check Deluxe Of Doom From Hell And Beyond\n";
	std::cout << "Enter number: ";

	std::getline(std::cin, input);

	/// Modes
	if (input.rfind("debug ", 0) == 0) // Debug allows you to see what is going, at the cost of speed
		debug = true;
	if (input.find("hex ", 0) == 0)
	{
		hex = true;
		input = input.substr(4);
	}

	/// Remove any characters from string
	if (!hex) 
	{
		input = RemoveChars(input); 
		checkNumber = std::stoull(input);
	}
	else 
	{ 
		input = RemoveCharsHex(input);
		checkNumber = std::stoull(input, nullptr, 16); 
	}
	if (input.empty()) {
		// Close the program if there are no numbers
		std::cout << "Error: no numbers found";
		std::cout << "\n===========================================================\n";
		return 1;
	}

	/// Actually checking if the number is a prime
	if (checkNumber > 2147483647)
	{
		std::cout << "Running long prime check, expect wait times up to 2 hours depending on number size\n";
		prime = LongPrimeCheck(checkNumber, debug); // LongPrimeCheck is faster, but requires a high number to function
	}
	else
	{
		prime = PrimeCheck(checkNumber, debug);
	}


	if (prime) 
		std::cout << '\n' << input << " is a prime";
	else 
		std::cout << '\n' << input << " is not a prime";

	std::cout << "\n===========================================================\n";

	std::cout << "Press any key to close\n";
	std::cin.get();
	return 0;
}