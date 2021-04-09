/// Welcome to the
/// Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <thread>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>
#include <algorithm>

#include "hardcoding.h"
#include "IsNotSimplePrime.h"
#include "DeleteChars.h"

bool prime[] = {false, false};

void SplitSieve(unsigned long long checkNumber, long long until, unsigned int i, int thread,bool debug)
{
	std::vector<unsigned int> sieve(until + 2);
	
	unsigned int index = 2;
	for(; i < until; i+= 2)
	{
		sieve[index] = i;
		index++;
	}

	std::replace_if(sieve.begin(), sieve.end(), IsNotSimplePrime, 0);
	
	for (i = 2; i < sieve.size(); i++) {
		if (sieve[i] != 0) {
			if (debug) { std::cout << "Prime: " << i << '\n'; }
			if (checkNumber % i == 0) {
				if (checkNumber != i) {
					prime[thread] = false;
					break;
				}
				else {
					prime[thread] = true;
				}
			}
			else {
				prime[thread] = true;
			}

			for (auto j = sieve[i] * sieve[i]; j < until; j += sieve[i]) {
				sieve[j] = 0;

				if (debug) { std::cout << "Composite: " << j << '\n'; } // A composite is the opposite of a prime
			}
		}
	}
}

bool LongPrimeCheck(const unsigned long long checkNumber, const bool debug) {

	const long long untilNumber = ceil(sqrt(checkNumber));

	if (!HardcodedValues(checkNumber)) { return false; } // Do not do anything else if checkNumber is divisible by a number in IsNotSimplePrime

	// Time  approximation
	const auto primes = round(untilNumber / log(untilNumber - 1)); // find approximate amount of primes
	std::cout << "Approximated number of primes: " << primes << "\n";
	
	const auto t1 = std::chrono::high_resolution_clock::now();
	
	std::vector<unsigned int> timeTest(1, 46399);
	std::replace_if(timeTest.begin(), timeTest.end(), IsNotSimplePrime, 1);
	
	const auto replaceTime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - t1);
	std::cout << "Approximate time for Replace: " << replaceTime.count() * primes << "s\n";

	// Multi-threading

	long long i = untilNumber / 2;
	i -= 46399;

	if (i>0)
	{
		std::thread thread1(SplitSieve, checkNumber, i, 46399, 0, debug);
		std::thread thread2(SplitSieve, checkNumber, untilNumber, i, 1, debug);

		thread1.join();
		thread2.join();

		if ((prime[0]) && (prime[1]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		SplitSieve(checkNumber, untilNumber, 46399, 0, debug);

		return prime[0];
	}
	
}

bool PrimeCheck(const unsigned int checkNumber, const bool debug)
{
	int i;

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
					prime[0] = false;
					break;
				}
				else
				{
					prime[0] = true;
				}
			}
			else
			{
				prime[0] = true;
			}

			for (int j = i * i; j < untilNumber; j += i)
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

	return prime[0];
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

	std::cout << "Press Enter to close\n";
	std::cin.get();
	return 0;
}