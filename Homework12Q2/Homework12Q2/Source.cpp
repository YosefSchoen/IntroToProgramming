/*
Homework 12

This Program will take information from an external files and encrypt it.  Then place the encrypted message in a new file

Introduction to Computer Science.

Question 2.

Yosef Schoen

01/18/18
*/


#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char letter;

	//getting Information from external file message.txt and sending it in external file crypto.txt
	ifstream message("message.txt");
	ofstream crypto("crypto.txt");

	//if either file is not found the program will say so
	if (!message || !crypto) {
		cout << "file not found\n";
	}

	while (!message.eof()) {
		//putting the char into letter
		message >> letter;

		//converting letters using azby encrition for lower case letters
		if (letter >= 'a' && letter <= 'z') {
			letter = 'z' - letter + 'a';
		}

		//same as above but for Capital letters
		else if (letter >= 'A' && letter <= 'Z') {
			letter = 'Z' - letter + 'A';
		}

		//adding 1 to every number except 9
		else if (letter >= '0' && letter < '9') {
			letter = letter + 1;
		}
		//turning 9 into a 0
		else if (letter == '9') {
			letter = '0';
		}

		//any other char ie !@#$%^&* will stay the same
		else {
			letter = letter;
		}

		//placing the encrypted version into the external file crypto
		crypto << letter << endl;
	}
	return 0;
}


/*
Example
a -> z
B -> Y
c -> x
d -> w
6 -> 7
@ -> @
8 -> 9
9 -> 0
# -> #
*/