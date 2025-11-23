// Threaded Prime Number Generator.cpp
// Author: Bob Langelaan
// Date: July 27th, 2022

// Will generate prime numbers until user enters a newline character

#include <iostream>
#include <iomanip>
#include <future>
#include <ctime>
#include <cmath>

using namespace std;

unsigned long long CalcNextPrime(unsigned long long); // function prototype
bool startPrimes(); // function prototype for first thread
bool waitForInput(); // function prototype for second thread

bool finished = false;  // keep displaying prime every second while false

int main()
{
    cout << "Starting thread to calculate primes" << endl;
    auto result1 = async(launch::async, startPrimes); // launch first thread
    cout << "Starting thread to wait for input" << endl;
    auto result2 = async(launch::async, waitForInput); // launch 2nd thread

    // wait for results from each thread
    result1.get();
    result2.get();

    // Execution does not continue until both threads have completed

    cout << "Thats all folks :)" << endl;
    
} // end main

// executes function nextPrime asynchronously
bool startPrimes()
{
    time_t oldTime = time(nullptr);
    unsigned long long nextPrime = 2;
    cout << "Next prime: " << nextPrime << endl; //output first prime
    
    nextPrime = 1;  // So that we calculate 3 next
                    // From this point all primes will be odd so we can add 2 each time
    while (!finished)
    {
        time_t newTime;

        // Wait for next second to arrive
        while ((newTime = time(nullptr)) == oldTime);//no body to this while loop

        oldTime = newTime;

        // Calculate the next prime
        // From this point all primes will be odd so we can add 2 each time
        nextPrime = CalcNextPrime(nextPrime+2);

        // And output it
        cout << "Next prime: " << nextPrime << endl;
    }
    
    return true;
} // end function startPrimes

// Calculates next prime #
// Not most efficient algorithm, but not so bad either
unsigned long long CalcNextPrime(unsigned long long first)
{
    while (true)
    {
        bool notPrime = false;
        unsigned long long upperLimit = sqrt(first);
        for (unsigned long long val = 3; !notPrime && val <= (upperLimit + 1); val += 2)
        {
            if (first % val == 0)
            {
                notPrime = true;
            }
        }

        // if we found next prime
        if (!notPrime)
        {
            return first; // we have found the next prime
        }
        else
        {
            first += 2; // next number to investigate if prime
                        // only need to check odd numbers
        }
    }

} // end function CalNextPrime

// Waits for input to stop other thread
bool waitForInput()
{
    getchar(); //type enter for this statement to complete
    finished = true; // This will cause other thread to complete
    return true;
}