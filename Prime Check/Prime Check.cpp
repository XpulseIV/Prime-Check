//Welcome to the
//Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <thread>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

#include "hardcoding.h"
#include "IsNotSimplePrime.h"
#include "someTestThings.h"

bool LongPrimeCheck(const unsigned long long checkNumber, bool debug) {
	unsigned long long i = 0;
	unsigned long long j = 0;

	bool prime = false;

	const long long untilNumber = 1 + ceil(sqrt(checkNumber));

	std::vector<char> sieve;

	sieve.resize(untilNumber, 1);

	if (!hardcodingdeluxe(checkNumber)) {
		return prime;
	}
	
	std::replace_if(sieve.begin() + 46399, sieve.end(), IsNotSimplePrime, 2);

	for (i = 46337; i < untilNumber; i++) {
		if (sieve[i] == 1) {
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
				sieve[j] = 2;
				
				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}
	return prime;
}

bool PrimeCheck(int checkNumber, bool debug)
{
	int i = 0;
	int j = 0;

	bool prime = false;

	const int untilNumber = 1 + ceil(sqrt(checkNumber));

	std::vector<bool> sieve;

	sieve.resize(untilNumber, 1);

	for (i = 2; i < untilNumber; i++) {
		if (sieve[i]) {
			if (debug) {
				std::cout << "Prime: " << i << '\n';
			}

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

int main() {
	bool prime;
	bool debug = false;
	bool error1 = true;

	std::string input; 

	std::cout << "Enter number: ";
	std::getline(std::cin, input);

	if (input.rfind("debug ", 0) == 0) { // Debug allows you to see what is going, at the cost of speed
		debug = true;
		input = input.substr(5);
	}

	// Solving issues
	for (int i = 0; i < input.length(); i++) {
		if (isdigit(input[i])) {
			error1 = false;
		}
	}
	if (error1) { /// error1 means that you did not enter a valid number
		std::cout << "Error 1: Number not found";
		exit(EXIT_FAILURE);
	}

	// Getting numbers from input
	const unsigned long long checkNumber = std::stoull(input);

	test(checkNumber);

	// Actually checking if the number is a prime
	if (checkNumber > 2147483647)
	{
		std::cout << "Running long prime check, expect wait times up to 2 hours depending on number size" << '\n';
		prime = LongPrimeCheck(checkNumber, debug); /// long prime check is faster, but requires a high number to function
	}
	else {
		prime = PrimeCheck(checkNumber, debug);
	}

	if (prime) {
		std::cout << std::endl << checkNumber << " is a prime";
	}
	else {
		std::cout << std::endl << checkNumber << " is not a prime";
	}

	return 0;
}