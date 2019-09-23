/*
source.cpp
program will create a dictionary, and allow user to add, delete, search, print all the words in dictionary
intro to computer science
exercise #9 question #4
chaim wald
Dec 27
*/

#include <iostream>
#include <cstring>
using namespace std;

enum Inputs { NEW, DELETE, SEARCH, PRINT_CHAR, PRINT_ALL, EXIT };
void newStr(char ** lexicon, const int lex_size, const char *word);
bool delStr(char ** lexicon, int lex_size, const char *word);
char* searchStr(char ** lexicon, const int lex_size, const char *word);
void printChar(char ** lexicon, const int lex_size, const char letter);
void printAll(char ** lexicon, const int lex_size);


int main() {

	char ** lexicon = new char *[80];
	int option;
	char word[80];
	int lex_size = 0;
	bool run = true;
	char letter = 0;

	while (run) {
		cout << "enter 0-5:" << endl;
		cin >> option;

		switch (option) {
		case NEW:
			cout << "enter the word:" << endl;
			cin >> word;
			lex_size++;
			newStr(lexicon, lex_size, word);
			break;
		case DELETE:
			cout << "enter the word to delete:" << endl;
			cin >> word;
			if (delStr(lexicon, lex_size, word)) {
				lex_size--;
			}
			printAll(lexicon, lex_size);
			break;
		case SEARCH:
			cout << "enter the word to search for:" << endl;
			cin >> word;
			if (!searchStr(lexicon, lex_size, word)) {
				cout << "not found" << endl;
			}
			else {
				cout << "found" << endl;
			}
			break;
		case PRINT_CHAR:
			cout << "enter the char:" << endl;
			cin >> letter;
			printChar(lexicon, lex_size, letter);
			break;
		case PRINT_ALL:
			printAll(lexicon, lex_size);
			break;
		case EXIT:
			run = false;
			break;
		}
	}
	//deleting the dynamically allocated memory every time
	for (int i = 0; i < lex_size; i++) {
		delete[] lexicon[i];
	}

	return 0;
}

void newStr(char **lexicon, const int lex_size, const char * word) {

	//allocating memory to lexicon
	lexicon[lex_size - 1] = new char[80];

	//were inserting the word to the end of the dictionary, by copying the word over
	strcpy_s(lexicon[lex_size - 1], 80, word);

	//if lex_size is > 1, meaning there is more than just one word in the dictionary
	//then we will have to make sure it is in alphabetical order
	if (lex_size > 1) {
		//declaring a temporary char to hold the word
		char holder[80];
		//loop running through dictionary, starting from the end 
		for (int i = lex_size - 1; i > 0; i--) {
			//condition using the compare tool, if the first string (lexicon[i]) is of lesser value than
			//second string (lexicon[i - 1]), which is the previous word, then we have to sort them 
			if (strcmp(lexicon[i], lexicon[i - 1]) < 0) {
				//copying the word(unsorted) from lexicon into holder
				strcpy_s(holder, 80, lexicon[i]);
				//copying the word(unsorted) into correct position, which is the previous spot
				strcpy_s(lexicon[i], 80, lexicon[i - 1]);
				//copying the word which we placed in holder into the i - 1 position
				strcpy_s(lexicon[i - 1], 80, holder);
			}
		}
	}
	printAll(lexicon, lex_size);
}

//creating a delete function that will remove any chosen word from the dictionary
bool delStr(char **lexicon, int lex_size, const char * word) {

	//declaring boolean flag
	bool remove = false;

	//if the size is greater than 0, meaning there is a possibility to remove a word
	if (lex_size > 0) {
		//declaring a temporary char to hold the word
		char holder[80];
		//loop running through the dictionary
		for (int i = 0; i < lex_size; i++) {
			//condition using the compare tool, were going to check if the word that the user input
			//to delete exists in the dictionary (thus equaling 0, meaning the words are a match).
			if (strcmp(lexicon[i], word) == 0) {
				//setting boolean flag to true
				remove = true;
				//condition to see if the word we want to delete is at the end of the dictionary
				//if its not, then we want to move it all the way to the end
				if (i != lex_size - 1) {
					//we want to copy the chosen word (lexicon[i]) to delete, into holder
					strcpy_s(holder, 80, lexicon[i]);
					//copying the words that are found at the end of the dictionary (lexicon[i + 1]) into
					//lexicon[i], moving them forward one by one
					strcpy_s(lexicon[i], 80, lexicon[i + 1]);
					//copying the word we want to remove (now placed in holder), and copying it into
					//(lexicon[i + 1]), slowly moving word(holder), which we want to remove all the way to the end
					strcpy_s(lexicon[i + 1], 80, holder);
				}
			}
		}
	}
	//now that we placed the word we want to delete in position we want it, we can go ahead and delete it.
	//run condition when remove is false
	if (remove) {
		//deleting the word the user has chosen, which is at the end of dictionary
		delete lexicon[lex_size - 1];
		return true;
	}
	else {
		return false;
	}
}

//creating search function to find the word were searching for
char* searchStr(char ** lexicon, const int lex_size, const char * word) {

	//loop to search for the words inputed
	for (int i = 0; i < lex_size; i++) {
		//when we compare if it equals zero that means it is the word
		if (strcmp(lexicon[i], word) == 0) {
			//return said word
			return lexicon[i];
		}
	}
	//if the word was not found
	return NULL;
}

//creating print function to print all the words in the dictionary starting with
//the character the user searched for
void printChar(char **lexicon, const int lex_size, const char letter) {

	//loop running amount of lex_size
	for (int i = 0; i < lex_size; i++) {
		//if the first letter of the word is equal to the letter 
		if (lexicon[i][0] == letter) {
			//then print out the word thats at that address, with a space
			cout << lexicon[i] << " ";
		}
	}
	cout << endl;
}

//creating print function to print all the words currently in the dictionary
void printAll(char ** lexicon, const int lex_size) {

	//loop running the amount of words size there is
	for (int i = 0; i < lex_size; i++) {
		//putting out a word every time around, with a space, and a line
		cout << lexicon[i] << " ";
	}
	cout << endl;
}
