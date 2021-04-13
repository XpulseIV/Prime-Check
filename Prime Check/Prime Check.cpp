//Welcome to the
//Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <iostream>
#include <cmath>
#include <string>
#include <thread>

#include "algorithm"
#include "DeleteChars.h"
#include "hardcoding.h"
#include "is_not_simple_prime.h"

auto long_prime_check(const unsigned long long check_number, const bool debug) -> bool
{
	long long i;

	auto prime = false;

	const long long until_number = ceil(sqrt(check_number)) + 1;

	auto* sieve = new bool[until_number];

	std::fill_n(sieve, until_number, 1);

	if (!hardcoded_values(check_number)) { return prime; }
	/// Do not do replace_if if checkNumber is divisible by a number in IsNotSimplePrime

	// The line below is what makes LongPrimeCheck faster
	std::replace_if(sieve + 46399, sieve + until_number, is_not_simple_prime, 2);

	for (i = 46337; i < until_number; i++)
	{
		if (sieve[i])
		{
			if (debug) { std::cout << "Prime: " << i << '\n'; }

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

			for (long long j = i * i; j < until_number; j += i)
			{
				sieve[j] = false;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}
	if (debug)
	{
		std::cout << "Primes are: " << std::endl;

		for (unsigned long long sieve_index = 1; sieve_index <= i; sieve_index++)
		{
			if (sieve[sieve_index])
			{
				std::cout << sieve_index << std::endl;
			}
		}
	}

	return prime;
}

auto prime_check(const int check_number, const bool debug) -> bool
{
	auto i = 0;

	auto prime = false;

	const int until_number = 1 + ceil(sqrt(check_number));

	auto* sieve = new bool[until_number];

	std::fill_n(sieve, until_number, 1);

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

			for (auto j = i * i; j < until_number; j += i)
			{
				sieve[j] = false;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}

	if (debug)
	{
		std::cout << "Primes are: " << std::endl;

		for (unsigned long long sieve_index = 1; sieve_index <= i; sieve_index++)
		{
			if (sieve[sieve_index])
			{
				std::cout << sieve_index << std::endl;
			}
		}
	}

	return prime;
}

/**
 * \brief 
 * \return 
 */
int main()
{
	bool prime;
	bool debug = false;
	unsigned long long check_number = 0;
	int base_int;

	std::string input;
	std::string base;

	// Outputting things for visuals
	std::cout << "===========================================================\n";
	std::cout << "Super Omega Prime Check Deluxe Of Doom From Hell And Beyond\n";
	std::cout << "Enter number: ";

	std::getline(std::cin, input);

	std::cout << "Enter the base of that number: ";

	std::getline(std::cin, base);

	const std::chrono::steady_clock::time_point start_time = std::chrono::high_resolution_clock::now();

	if (base.empty()) {
		base_int = 10;
	}
	else
	{
		base_int = std::stoi(base);
	}

	if (input.rfind("debug ", 0) == 0) // Debug allows you to see what is going, at the cost of speed
	{
		debug = true;
		input = input.substr(6);
	}

	// Removes any characters from string
	if (base_int == 10) {
		input = remove_chars(input);

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

	char* const number_in_char_array = &input[0];

	if (!base_int == 10 == 0) {
		check_number = std::stoull(number_in_char_array, nullptr, base_int);
	}

	// Actually checking if the number is a prime
	if (check_number > 2147483647)
	{
		std::cout << "Running long prime check, expect wait times up to 2 hours depending on number size\n";
		prime = long_prime_check(check_number, debug); /// LongPrimeCheck is faster, but requires a high number to function
	}
	else
	{
		prime = prime_check(check_number, debug);
	}

	if (prime) {
		std::cout << '\n' << check_number << " is a prime";
	}
	else {
		std::cout << '\n' << check_number << " is not a prime";
	}
	const auto end_time = std::chrono::high_resolution_clock::now();

	std::cout << "\n===========================================================\n";

	const long long time_took_in_us = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

	std::cout << time_took_in_us << std::endl;

	std::cout << "Press any key to close\n";
	std::cin.get();
	return 0;
}
