#include <iostream>
using namespace std;


const int a = 10;
const int b = 30;

void merge(int x[], int y[], int sizeX, int sizeY, int New[]) {
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < sizeX && j < sizeY) {
		if (x[i] > y[j]) {
			New[k] = x[i];
			i++;
		}

		else {
			New[k] = y[j];
			j++;
		}

		k++;
	}

	while (i < sizeX) {
		New[k] = x[i];
		i++;
		k++;
	}

	while (j < sizeY) {
		New[k] = y[j];
	}
}



int main() {

	int vector1[a];
	int vector2[a];
	int vector3[a];
	int tempNewVector[b];
	int NewVector[b];

	int size1 = 0;
	int size2 = 0;
	int size3 = 0;
	int sizeTempNew;
	int sizeNew;

	cout << "enter values for the first vector:\n";

	for (int i = 0; i < a; i++) {
		cin >> vector1[i];

		if (vector1[i] == 0) {
			break;
		}

		if (vector1[i] >= vector1[i - 1] && i != 0) {
			cout << "ERROR\n";
			i = 0;
		}
		size1++;
	}

	cout << "enter values for the second vector:\n";

	for (int i = 0; i < a; i++) {
		cin >> vector2[i];

		if (vector2[i] == 0) {
			break;
		}

		if (vector2[i] >= vector2[i - 1] && i != 0) {
			cout << "ERROR\n";
			i = 0;
		}
		size2++;
	}

	cout << "enter values for the third vector:\n";

	for (int i = 0; i < a; i++) {
		cin >> vector3[i];

		if (vector3[i] == 0) {
			break;
		}

		if (vector3[i] >= vector3[i - 1] && i != 0) {
			cout << "ERROR\n";
			i = 0;
		}
		size3++;
	}
	sizeTempNew = size1 + size2;
	merge(vector1, vector2, size1, size2, tempNewVector);

	sizeNew = size3 + sizeTempNew;
	merge(vector3, tempNewVector, size3, sizeTempNew, NewVector);

	for (int i = 0; i < 30; i++) {
		cout << "merge vector is:\n: " << NewVector[i] << " ";
	}


	return 0;
}