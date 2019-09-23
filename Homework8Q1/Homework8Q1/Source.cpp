#define MAX 10
#include <iostream>
using namespace std;

enum choices { EXIT, ADD, DELETE, PRINT, SEARCH, AVG_TRAVEL, AVG_STOPS, SHORTEST_TRAVEL };

int search(int buses[][3], int & numOfBuses, int line) {
	for (int i = 0; i < numOfBuses; i++) {
		if (*((*(buses + i)) + 0) == line) {
			return i;
		}
	}
	return -1;
}

void addLine(int buses[][3], int & numOfBuses, int line, int stops, int duration) {

	// checking for errors

	if (numOfBuses == MAX) {
	cout << "Error! Cannot add any more buses\n";
	return;
	}
	if (search(buses, numOfBuses, line) != -1) {
		cout << "Error! Bus number " << line << " already exists\n";
		return;
	}

	// shifting right all bus lines that are larger than the bus line to be 
	// inserted.  allows for placing new bus line in its correct position

	int i = numOfBuses;
	while ((i > 0) && (*(*(buses + i - 1)) > line)) {
		for (int j = 0; j<3; j++)
			*((*(buses + i)) + j) = *((*(buses + i - 1)) + j);
		i--;
	}
	// correct index to place new bus is found
	// inserting new bus line in correct position (index) 
	*(*(buses + i)) = line;
	*((*(buses + i)) + 1) = stops;
	*((*(buses + i)) + 2) = duration;

	numOfBuses++;	// updates numOfBuses since one more bus was added to array
}

void deleteLine(int buses[][3], int & numOfBuses, int line) {
	int i = search(buses, numOfBuses, line);

	if (i == -1) {
		return;
	}

	else {
		for (; i < numOfBuses; i++) {
			for (int j = 0; j < numOfBuses; j++) {
				*(*(buses + i) + j) = *(*(buses + i + 1) + j);
			}
		}
	}
	numOfBuses = numOfBuses - 1;
}

// prints out the buses that are saved in the database

void print(int buses[][3], int numBuses) {

	for (int i = 0; i<numBuses; i++) { // for each bus that is present in the database
		int * oneBus = buses[i];	// store the bus' data in oneBus
		for (int j = 0; j<3; j++) { // prints the 3 pieces of data of the bus
			cout << *(oneBus + j);
			cout << " ";
		}
		cout << endl;
	}
}

float averageTravel(int buses[][3], int & numOfBuses) {
	float sum = 0;
	for (int i = 0; i < numOfBuses; i++) {
		sum = sum + *((*(buses + i)) + 2);
	}
	return (sum / numOfBuses);
}

float averageStops(int buses[][3], int & numOfBuses){
	float sum = 0;
	for (int i = 0; i < numOfBuses; i++) {
		sum = sum + *((*(buses + i)) + 1);
	}
	return sum / numOfBuses;
}

int shortest(int buses[][3], int & numOfBuses) {
	int minimun = *(*(buses) + 2);
	for (int i = 0; i < numOfBuses; i++) {
		if (*(*(buses + i) + 2) < minimun) {
			minimun = *(*(buses + i));
		}
	}
	return minimun;
}

int main() {

	int buses[MAX][3];	// 2D array of buses - 
						// 10 rows to hold 10 different bus lines
						// each row holds bus number, number of stops, 
						//and duration of ride

	int numBuses = 0;	// number of buses that is currently stored in the array bus

	int line;
	int stops;
	int durationOfRide;
	int choice;

	do {
		cout << "enter 0-7" << endl;
		cin >> choice;
		switch (choice) {
		case ADD: // add a line to the array of buses
			cout << "enter the line to add" << endl;
			cin >> line;
			cout << "enter the number of stops" << endl;
			cin >> stops;
			cout << "enter the duration of the ride" << endl;
			cin >> durationOfRide;
			addLine(buses, numBuses, line, stops, durationOfRide);
			print(buses, numBuses);
			break;

		case DELETE:	// delete a line from the array of buses
			cout << "enter the line to delete" << endl;
			cin >> line;
			deleteLine(buses, numBuses, line);
			print(buses, numBuses);
			break;

		case PRINT: // print all lines
			print(buses, numBuses);
			break;

		case SEARCH: // search for a particular line
			cout << "enter the line to search for" << endl;
			cin >> line;
			cout << search(buses, numBuses, line) << endl;
			break;

		case AVG_TRAVEL: // calculate average travel time of all buses
			cout << averageTravel(buses, numBuses) << endl;
			break;

		case AVG_STOPS:  // calcuate average stops of all buses
			cout << averageStops(buses, numBuses) << endl;
			break;

		case SHORTEST_TRAVEL: // calculate the bus with the shortest travel time
			cout << shortest(buses, numBuses) << endl;
			break;

		case EXIT: break;   // exit the program

		default: cout << "ERROR" << endl;
		}// switch

	} while (choice != 0);
	return 0;
}