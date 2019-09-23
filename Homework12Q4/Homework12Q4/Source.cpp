/*
Homework 12

This Program will take information from a file about students and output it to the terminal

Introduction to Computer Science.

Question 4.

Yosef Schoen

01/18/18
*/


#include <iostream>
#include <fstream>
using namespace std;

//each student will have an ID a name and a grade 
struct Student {
	int id;
	char name[25];
	int mark;
};

//an array of all the students 
Student StudentArray[50];

//This function will copy all the information of each student in the the array of student strucures
int CopyData(char file[]) {
	int i = 0;

	//inputting all the information from an external file student_file.txt
	ifstream StudentFile("student_file.txt");

	//if the program can't find the file it will say so
	if (!StudentFile) {
		cout << "file does not exist" << endl;
	}

	//until the file is not done, it will continue inputing data into the array of students structures
	while (!StudentFile.eof()) {
		StudentFile >> StudentArray[i].id;
		StudentFile >> StudentArray[i].name;
		StudentFile >> StudentArray[i].mark;
		i++;
	}
	//closing the file when done
	StudentFile.close();
	//returning the size of the file (number of students)
	return i;
}

// function to print the data to the terminal
void print(int NumberOfStudents) {
	for (int i = 0; i < NumberOfStudents; i++) {
		cout << "name: " << StudentArray[i].name 
			 << " id: " << StudentArray[i].id << " mark "
			 << StudentArray[i].mark << endl;
	}
}

int main() {
	//this file is where the data and size of the external file will be stored
	char file[25];

	//the size of the external file will be stored in NumberOf Students
	int NumberOfStudents = CopyData(file);

	//Will Print the results
	print(NumberOfStudents);


	return 0;
}



/*
Example
0 Yosef 60
101 Dovid 80
102 Saleem 75
103 Malachi 55
104 Mahmud 30
105 Kyle 40
106 Enrique 70
107 Santiago 90
108 Wonglee 85
*/