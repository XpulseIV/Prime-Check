//Welcome to the
//Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <cmath>
#include <iostream>
#include <string>
#include <thread>
#include <boost/multiprecision/gmp.hpp>

#include "algorithm"
#include "DeleteChars.h"
#include "hardcoding.h"
#include "is_not_simple_prime.h"

bool Long_Prime_Check(const unsigned long long check_number, const bool debug)
{
    long long i;

    auto prime = false;

    const long long untilNumber = ceil(sqrt(check_number)) + 1;

    auto* sieve = new bool[untilNumber];

    std::fill_n(sieve, untilNumber, 1);

    if (!Hardcoded_Values(check_number)) return prime;
    /// Do not do replace_if if checkNumber is divisible by a number in IsNotSimplePrime

    // The line below is what makes LongPrimeCheck faster
    std::replace_if(sieve + 46399, sieve + untilNumber, Is_Not_Simple_Prime, 2);

    for (i = 46337; i < untilNumber; i++)
    {
        if (sieve[i])
        {
            if (debug) std::cout << "Prime: " << i << '\n';

            if (check_number % i == 0)
            {
                if (check_number != i)
                {
                    prime = false;
                    break;
                }
                prime = true;
            }
            else prime = true;

            for (long long j = i * i; j < untilNumber; j += i)
            {
                sieve[j] = false;

                if (debug) std::cout << "Composite: " << j << '\n';
                // A composite is the opposite of a prime
            }
        }
    }
    if (debug)
    {
        std::cout << "Primes are: " << std::endl;

        for (unsigned long long sieveIndex = 1; sieveIndex <= i; sieveIndex++) if (sieve[sieveIndex]) std::cout << sieveIndex << std::endl;
    }

    return prime;
}

bool Prime_Check(const int check_number, const bool debug)
{
    int i;

    bool prime = false;

    const int untilNumber = 1 + ceil(sqrt(check_number));

    auto* sieve = new bool[untilNumber];

    std::fill_n(sieve, untilNumber, 1);

    for (i = 2; i < untilNumber; i++)
    {
        if (sieve[i])
        {
            if (debug) std::cout << "Prime: " << i << '\n';

            if (check_number % i == 0)
            {
                if (check_number != i)
                {
                    prime = false;
                    break;
                }
                prime = true;
            }
            else prime = true;

            for (int j = i * i; j < untilNumber; j += i)
            {
                sieve[j] = false;

                if (debug) std::cout << "Composite: " << j << '\n';
                // A composite is the opposite of a prime
            }
        }
    }

    if (debug)
    {
        std::cout << "Primes are: " << std::endl;

        for (int sieveIndex = 1; sieveIndex <= i; sieveIndex++) if (sieve[sieveIndex]) std::cout << sieveIndex << std::endl;
    }

    return prime;
}

int main()
{
    bool prime;
    bool debug = false;
    unsigned long long checkNumber = 0;
    int baseInt;

    std::string input;
    std::string base;

    // Outputting things for visuals
    std::cout << "===========================================================\n";
    std::cout << "Super Omega Prime Check Deluxe Of Doom From Hell And Beyond\n";
    std::cout << "Enter number: ";

    std::getline(std::cin, input);

    std::cout << "Enter the base of that number: ";

    std::getline(std::cin, base);

    if (base.empty()) baseInt = 10;
    else baseInt = std::stoi(base);

    if (input.rfind("debug ", 0) == 0) // Debug allows you to see what is going, at the cost of speed
    {
        debug = true;
        input = input.substr(6);
    }

    // Removes any characters from string
    if (baseInt == 10)
    {
        input = Remove_Chars(input);

        if (input.empty())
        {
            /// Close the program if there are no numbers
            std::cout << "Error: no numbers found";
            std::cout << "\n===========================================================\n";
            return 1;
        }
    }
    else
    {
        for (int chars = 0; chars <= input.length(); chars++)
        {
            if (!isdigit(input[chars]))
            {
                if (std::islower(input[chars])) input[chars] = std::toupper(input[chars]);

                else { }
            }
        }
    }

    const std::string nString = input;

    if (!baseInt == 10 == 0) checkNumber = std::stoull(nString, nullptr, baseInt);

    // Actually checking if the number is a prime
    
    if (checkNumber > 2147483647)
    {
        std::cout << "Running long prime check, expect wait times up to 2 hours depending on number size\n";
        prime = Long_Prime_Check(checkNumber, debug); /// LongPrimeCheck is faster, but requires a high number to function
    }
    else prime = Prime_Check(static_cast<int>(checkNumber), debug);

    if (prime) std::cout << '\n' << checkNumber << " is a prime";
    else std::cout << '\n' << checkNumber << " is not a prime";

    std::cout << "\n===========================================================\n";

    std::cout << "Press any key to close\n";
    std::cin.get();
    return 0;
}
