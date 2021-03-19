//Welcome to the
//Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <thread>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

#include "hardcoding.h"
#include "is_not_simple_prime.h"
#include "someTestThings.h"
#include "DeleteChars.h"
bool long_prime_check(const unsigned long long checkNumber, const bool debug) {
	long long i = 0;
	long long j = 0;

	auto prime = false;

	const long long until_number = 1 + ceil(sqrt(checkNumber));

	auto* sieve = new bool[until_number];

	std::fill_n(sieve, until_number, 1);

	if (!hardcoded_values(checkNumber)) { return prime; } /// Do not do replace_if if checkNumber is divisible by a number in IsNotSimplePrime

	// The line below is what makes LongPrimeCheck faster
	std::replace_if(sieve + 46399, sieve + until_number, is_not_simple_prime, 2);

	for (i = 46337; i < until_number; i++) {
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

			for (j = i * i; j < until_number; j += i) {
				sieve[j] = false;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}
	return prime;
}

bool prime_check(const int check_number, const bool debug)
{
	auto i = 0;
	auto j = 0;

	auto prime = false;

	const int until_number = 1 + ceil(sqrt(check_number));

	auto* sieve = new bool[until_number];

	std::fill_n(sieve, until_number, true);

	for (i = 2; i < until_number; i++)
	{
		if (sieve[i])
		{
			if (debug)
			{
				std::cout << "Prime: " << i << '\n';
			}

			if (check_number % i == 0)
			{
				if (check_number != i)
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

			for (j = i * i; j < until_number; j += i)
			{
				sieve[j] = false;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}
	return prime;
}

int main() {
	bool prime;
	auto debug = false;

	std::string input;

	// Outputting things for visuals
	std::cout << "Super Omega Prime Check Deluxe Of Doom From Hell And Beyond" << '\n';
	std::cout << "Enter number: ";

	std::getline(std::cin, input);

	if (input.rfind("debug ", 0) == 0) { debug = true; } // Debug allows you to see what is going, at the cost of speed

	// Removes any characters from string
	input = remove_chars(input);
	if (input.empty()) {
		std::cout << "No numbers found";
		exit(EXIT_FAILURE);
	}

	// Getting numbers from input
	const auto check_number = std::stoull(input);

	test(check_number);

	// Actually checking if the number is a prime
	if (check_number > 2147483647)
	{
		std::cout << "Running long prime check, expect wait times up to 2 hours depending on number size" << '\n';
		prime = long_prime_check(check_number, debug); /// LongPrimeCheck is faster, but requires a high number to function
	}
	else {
		prime = prime_check(check_number, debug);
	}

	if (prime) {
		std::cout << std::endl << check_number << " is a prime";
	}
	else {
		std::cout << std::endl << check_number << " is not a prime";
	}

	return 0;
}