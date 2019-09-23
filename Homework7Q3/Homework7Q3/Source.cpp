#include <iostream>
using namespace std;

/*const int Row = 10;
const int Column = 10;

void insert(int Matrix[Row][Column]) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++) {

			cout << Matrix[i][j] << " ";
			
		}

		cout << endl;
	}
}

void insert(int arr[][10])
{
	int j, temp[10];

	for (int i = 0; i < 10; i++) {
		j = i;

		while (j > 0 && arr[j] < arr[j - 1]) {
			temp[i] = arr[i][j];
			arr[i][j] = arr[i][j - 1];
			arr[i][j - 1] = temp[i];
			j--;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	const int Row = 10;
	const int Column = 10;
	int NewMatrixL[Row][Column];
	int NewMatrixR[Row][Column];

	int Matrix[Row][Column] = {
		{ 34, 1, 21, 29, 81, 45, 36, 78, 100, 3 },
		{ 26, 35, 18, 82, 90, 50, 83, 34, 62, 84 },
		{ 46, 82, 16, 31, 22, 81, 77, 85, 36, 25 },
		{ 9, 32, 49, 2, 84, 35, 24, 21, 89, 67 },
		{ 75, 96, 56, 10, 66, 1, 58, 11, 76, 37 },
		{ 72, 62, 89, 36, 58, 54, 99, 13, 33, 59 },
		{ 29, 19, 5, 14, 10, 12, 6, 82, 81, 32 },
		{ 75, 44, 64, 50, 64, 53, 56, 99, 34, 89 },
		{ 72, 42, 77, 75, 22, 57, 69, 57, 86, 17 },
		{ 54, 3, 81, 24, 17, 26, 22, 61, 90, 87 },
	};

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++)
			if (i < j) {
				//NewMatrixR[i][j]
				insert(Matrix);
			}

			else if (i > j) {
				//NewMatrixL[i][j]
				 insert(Matrix);
			}
	}


	/*for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++) {

			cout << i << " " << j << ": ";

			if (i == j) {
				cout << Matrix[i][j] << endl;
			}

			else if (i > j) {
				cout << "one ";
				cout << NewMatrixL[i][j] << endl;
			}
			else if (i < j) {
				cout << "two ";
				cout << NewMatrixR[i][j] << endl;
			}
		}
	}
	
	return 0;
}
*/



#include <iostream>
using namespace std;

const int Row = 10;
const int Column = 10;

//function to swap for the insertion sort.
void swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}


void inserSort(int arr[], int size) //insertion sort
{
	for (int i = 0; i < size; i++) {
		if (i > 0 && arr[i] < arr[i - 1]) {

			// current is what i is, because its smaller, so swap
			for (int current = i; arr[current] < arr[current - 1]; current--)
			{
				swap(arr, current, current - 1); // calling the swap function
			}

		}
	}
}

int main()
{
	int Matrix[Row][Column];
	int temp[45] = {};

	// user input
	cout << "enter 100 numbers:" << endl;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			{
				cin >> Matrix[i][j];
			}
		}
	}

	//Enter into an upper triangle temporary, and sort the function of insertion sort,
	//first collapse the loop
	int k = 0;
	for (int i = 0; i < Row - 1; i++) // starts at 0,0,, and only repeats 9 times, only uses rows 8 times becuase row starts at 0
	{
		for (int j = i + 1; j < Column; j++) //  starts at 0,1, becuase at 0,0 nothing is changed.  i + 1 bc columns need to start at place 1
		{
			temp[k] = Matrix[i][j]; // put all values of matrix into temp, and keep track of the size of k.
			k++;
		}
	}

	inserSort(temp, 45); // call function insertion sort

						 // rebuild the collapsed matrix for the top
	k = 0;
	for (int i = 0; i < Row - 1; i++) // same paramters in the for loop as when we collapsed it because we still start at i =0
	{
		for (int j = i + 1; j < Column; j++) // amount of columns will still always be 1 above the amount of rows, so j = i+1
		{
			Matrix[i][j] = temp[k]; // always keep track of the size and place of the array.
			k++;
		}

	}
	//Enter into an array temporarily lower triangle, and it sort of insertion sort function
	k = 0;  // always need to reset k to zero because our matrix and temporary array always start at place 0 || 0,0
	for (int i = 1; i < Row; i++)// j always starts at 0, because the columns start at 0, and this time the columns will always be smaller than the rows, so j < i
	{
		for (int j = 0; j < i; j++)
		{
			temp[k] = Matrix[i][j];
			k++;
		}

	}



	inserSort(temp, 45);

	k = 0;
	for (int i = 1; i < Row; i++)
	{
		// j only goes until i rows
		for (int j = 0; j < i; j++)
		{
			Matrix[i][j] = temp[k];
			k++;
		}

	}

	//Output matrix as requested.
	cout << "sorted matrix:" << endl;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
enter 100 numbers:
1 11 21 31 41 51 61 71 81 91
2 12 22 32 42 52 62 72 82 92
3 13 23 33 43 53 63 73 83 93
4 14 24 34 44 54 64 74 84 94
5 15 25 35 45 55 65 75 85 95
6 16 26 36 46 56 66 76 86 96
7 17 27 37 47 57 67 77 87 97
8 18 28 38 48 58 68 78 88 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100
sorted matrix:
1 11 21 22 31 32 33 41 42 43
2 12 44 51 52 53 54 55 61 62
3 4 23 63 64 65 66 71 72 73
5 6 7 34 74 75 76 77 81 82
8 9 10 13 45 83 84 85 86 87
14 15 16 17 18 56 88 91 92 93
19 20 24 25 26 27 67 94 95 96
28 29 30 35 36 37 38 78 97 98
39 40 46 47 48 49 50 57 89 99
58 59 60 68 69 70 79 80 90 100
Program ended with exit code: 0
*/
