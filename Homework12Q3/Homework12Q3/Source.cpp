/*
Homework 12

This Program will take the grades of four students and find out who has the biggest average

Introduction to Computer Science.

Question 3.

Yosef Schoen

01/18/18
*/


#include <iostream>
#include <fstream>
using namespace std;


//this function will find the biggest student average
int largest(float average[4]) {
	//setting the biggest average to the first student
	float biggest = average[0];
	//counter will remember which number student has the biggest average
	int counter;

	//the loop will run through the averages and determin if which is the largest
	for (int i = 0; i < 4; i++) {
		if (average[i] > biggest) {
			//if the the next students average is larger than the original largest, it will reasign the value of biggest to that student
			biggest = average[i];
			//if the students average is bigger than the previous biggest student that students number will be remembered
			counter = i + 1;
		}
	}
	//returning the students number with the biggest average
	return counter;
}

//the main will input all the external files and find the students averages in an array
int main() {
	//getting all the grades of the four students
	ifstream GradeOne("grade1.txt");
	ifstream GradeTwo("grade2.txt");
	ifstream GradeThree("grade3.txt");
	ifstream GradeFour("grade4.txt");

	//each grade will be temporarily stored into grade 
	float grade;

	//each grade will be added to the sum of all of that student's grades
	//each students sum will be stored in one spot in the array
	float sum[4] = { 0, 0, 0, 0 };

	//the number of grades will be used with sum to find the average
	int NumOfGrades[4] = { 0, 0, 0, 0 };

	//each of the student's average will be stored in one spot in the array
	float average[4];

	//if external files are not found the program will say so
	if (!GradeOne || !GradeTwo || !GradeThree || !GradeFour) {
		cout << "file not found\n";
	}
	
	while (!GradeOne.eof()) {
		//storing the grade in to grade from the external file
		GradeOne >> grade;
		//adding up the sum of all of the grades of student one
		sum[0] = sum[0] + grade;
		//incrementing the number of grades from that were in the external file
		NumOfGrades[0]++;
	}

	//dividing the sum by the number of grades to find the average
	average[0] = sum[0] / NumOfGrades[0];

	//same proccess for the second student
	while (!GradeTwo.eof()) {
		GradeTwo >> grade;
		sum[1] = sum[1] + grade;
		NumOfGrades[1]++;
	}

	average[1] = sum[1] / NumOfGrades[1];

	//same proccess for the third student
	while (!GradeThree.eof()) {
		GradeThree >> grade;
		sum[2] = sum[2] + grade;
		NumOfGrades[2]++;
	}

	average[2] = sum[2] / NumOfGrades[2];

	//same proccess for the fourth student
	while (!GradeFour.eof()) {
		GradeFour >> grade;
		sum[3] = sum[3] + grade;
		NumOfGrades[3]++;
	}

	average[3] = sum[3] / NumOfGrades[3];

	//calling the function to find the largest average and outputting it to the terminal
	cout << largest(average) << endl;

	return 0;
}

/*
Example

Student one
1, 2, 3, 4

Student Two
2, 4, 6, 8, 10, 12

Student Three
1, 3

Student Four 
5, 1, 3
*/
