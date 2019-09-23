#include <iostream>
#include <fstream>
using namespace std;
/*
Homework 12

This Program will take information from two external files about student names and grade and place them into a new file 

Introduction to Computer Science.

Question 1.

Yosef Schoen

01/18/18
*/


int main() {

	//inputting the names and grades of students from the external files names.txt and grades.txt
	//and outputting them in the external file roster.txt
	ifstream names("names.txt");
	ifstream grades("grades.txt");
	ofstream roster("roster.txt");
	 
	char name[50];
	float grade;

	//if any of the files not found the program will say so
	if (!names || !grades || !roster) {
		cout << "files not found\n";
	}

	
	while (!names.eof() && !grades.eof()) {
		//inputting the name into names
		names >> name;
		//outputting the name into roster
		roster << name << " ";

		//same with grades
		grades >> grade;
		roster << grade << " ";

		roster << endl;

		//if the amount of names is larger than the amount of grades
		if (!names.eof() && grades.eof()) {
			cout << "finished reading grades before names\n";

			//outputting to the terminal the names that do not have a grade
			while (!names.eof()) {
				names >> name;
				cout << name << endl;
			}
		}

		//if the amount of grades is larger than the amount of names
		if (names.eof() && !grades.eof()) {
			cout << "finished reading names before grades\n";

			//outputting to the terminal the grades that do not have a name
			while (!grades.eof()) {
				grades >> grade;
				cout << grade << endl;
			}
		}
	}
}


/*
Example 1

Elkana 90
Chana 80
Eli 85
Shmuel 95


Example 2

Elkana 90
Chana 80
Eli 85

finished reading grades before names
Shmuel


Example 3

Elkana 90
Chana 80
Eli 85

finished reading names before grades
95
*/