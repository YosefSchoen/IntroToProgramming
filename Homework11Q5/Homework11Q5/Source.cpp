#include <iostream>
using namespace std;

//ghost calling functions
bool Legal(char** Chessboard, int row, int column, int size);
bool placeQueen(char** Chessboard, int row, int column, int size);
void printBoard(char** Chessboard, int size);

int main() {

	//will create a matrix out of a double pointer called Chessboard
	char** Chessboard;
	int size;

	//user will input desired size of the board
	cout << "enter size of board " << endl;
	cin >> size;

	//dynamically allocating memory to the Chessboard
	Chessboard = new char*[size];

	//dynamically allocating memory to each column of the board so it will be an N x N Grid
	for (int i = 0; i < size; i++) {
		Chessboard[i] = new char[size];
	}

	//filling the board up with blank spaces (_)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Chessboard[i][j] = '_';
		}
	}

	//bool success to check if solution was possible
	bool success;

	//assigning placeQueen function true/false to success
	success = placeQueen(Chessboard, 0, 0, size);
	//if there wasnt a solution

	if (success == false) {
		cout << "There are no possible solutions!" << endl;
	}
	else {
		//calling function to print the board 
		printBoard(Chessboard, size);
		cout << "We have found a solution!" << endl;
	}

	//freeing up the dynamically allocated memory
	for (int i = 0; i < size; i++) {
		delete[] Chessboard[i];
	}
	delete[] Chessboard;

	return 0;
}

//Legal will check if the next place on the board is a legal move
bool Legal(char** Chessboard, int row, int column, int size) {

	//cheking the desired row
	for (int i = 0; i < column; i++) {
		if (Chessboard[row][i] == 'Q') {
			return false;
		}
	}
	//checking the desired upper diagonal
	for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
		if (Chessboard[i][j] == 'Q') {
			return false;
		}
	}
	//checking the desired lower diagonal
	for (int i = row, j = column; i < size && j >= 0; i++, j--) {
		if (Chessboard[i][j] == 'Q') {
			return false;
		}
	}
	//if the function passed all previous points then it must be legal
	return true;
}

//function to place the queens on Chessboard
bool placeQueen(char** Chessboard, int row, int column, int size) {

	//base case of recursion calls if the function reaches the last column
	if (column >= size) {
		return true;
	}
	//checking the rows in a given column
	for (int i = 0; i < size; i++) {

		//if Legal returns true, a queen can be placed here
		if (Legal(Chessboard, i, column, size) == true) {
			//placing the queen
			Chessboard[i][column] = 'Q';

			//call the function recursively to place queens
			if (placeQueen(Chessboard, 0, column + 1, size) == true) {

				//if true this means we have found a solution
				return true;
			}
			//else that we cannot place a queen in this spot then backtrack
			else {
				//and place a _ (remove) in that spot.
				Chessboard[i][column] = '_';
			}
		}
	}
	// there can't be any possible solutions at this point
	return false;
}

//Print function to print Chessboard
void printBoard(char** Chessboard, int size) {
	char a = 'a';
	cout << "   ";
	for (int i = 0; i < size; i++) {
		cout << static_cast<char>(a + i) << "  ";
	}

	cout << endl;

	for (int i = 0; i < size; i++) {
		if (i < 9) {
			cout << " " << i + 1;
		}
		else {
			cout << i + 1;
		}
		for (int j = 0; j < size; j++) {

			cout << "|" << Chessboard[i][j] << '|';
		}
		cout << endl;
	}
	cout << endl;
}