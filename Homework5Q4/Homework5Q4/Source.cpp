/*
Homework 5

This program will give you a list of prime numbers.

Introduction to Computer Science.

Question 4.

Yosef Schoen

22/11/17
*/



// need c time and c standard library
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int isPrime(int x) {

	bool isPrime;

	// declaring all numbers are prime until proven otherwise
	for (int i = 2; i <= x; i++) {
		isPrime = true;

		//testing to see if they not are prime.
		for (int j = 2; j < i / 2; j++) {

			if (i % j == 0) {
				isPrime = false;
				break;
			}

		}

	}

	return isPrime;
}

// function to find nearest prime greater than the users number
int findPrime(int x) {
	int i;
	for (i = 0; i < 100; i++) {
		isPrime(x + i);

		if (isPrime(x + i)) {
			break;
		}
	}

	return (x + i);
}

int main() {

	//random number declaration
	srand((unsigned)time(NULL));

	int num;

	cout << "enter number of values:\n";

	cin >> num;

	//calling the random number only if user inputs somthing negative
	if (num < 0) {

		rand();
	}

	// if users number is prime it will show it with first function
	if (isPrime(num)) {
		cout << "table size: " << num << endl;
	}

	// if the users number is not prime it will call the second function
	//to show next prime number.
	else {
		cout << "table size: " << findPrime(num) << endl;
	}

	return 0;
}