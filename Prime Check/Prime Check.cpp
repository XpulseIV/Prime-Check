//Welcome to the
//Super Omega Prime Check Deluxe of Doom from Hell and Beyond

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

//Header Files
#include "hardcoding.h"
#include "IsNotSimplePrime.h"

bool LongPrimeCheck(unsigned long long checkNumber, bool debug) {

    unsigned long long i = 0;
    unsigned long long j = 0;

    bool prime = false;

    long long untilNumber = 1 + ceil(sqrt(checkNumber));

    int length = 1 + std::to_string(untilNumber).length();

    std::vector<bool> sieve;

    sieve.resize(untilNumber, 1);

    if  (not hardcodingdeluxe(checkNumber)) {
        std::cout << checkNumber << "is not a prime" << '\n';
        exit(EXIT_FAILURE);
    }

    std::replace_if(sieve.begin(), sieve.end(), IsNotSimplePrime, 0);

    for (i = 41; i < untilNumber; i++) {

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
                if (debug) {
                    std::cout << "Composite: " << j << '\n';
                }
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

    int untilNumber = 1 + ceil(sqrt(checkNumber));

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

                if (debug) {
                    std::cout << "Composite: " << j << '\n';
                }
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

    if (input.rfind("debug ", 0) == 0) {
        debug = true;
        input = input.substr(5);
    }
    else {
        for (int i = 0; i < input.length(); i++) {
            if (isdigit(input[i])) {
                error1 = false;
            }

            if (error1) {
                std::cout << "Error 1: Number not found";
                exit(EXIT_FAILURE);
            }
        }
    }

    unsigned long long checkNumber = std::stoull(input);

    if (checkNumber > 2147483647)
    {
        std::cout << "Running long prime check, expect wait times up to 2 hours depending on number size" << '\n';
        prime = LongPrimeCheck(checkNumber, debug);
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
