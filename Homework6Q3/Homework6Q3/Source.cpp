#include <iostream>
using namespace std;


void RemoveRepeats(const int array1[], int array2[], int size1, int& size2) {

	for (int i = 0; i < size1; i++) {
		bool match = false;

		for (int j = 0; j < size2; j++) {
			if (array1[i] == array2[j]) {
				match = true;
				break;
			}
		}

		if (match == false) {

			array2[size2] = array1[i];
			size2 = size2 + 1;
		}
	}
}


int main() {

	const int x = 100;
	int MyArray[x] = {};
	int NewArray[x] = {};
	int size1 = 0;
	int size2 = 0;

	cout << "enter up to 100 values, to stop enter 0:\n";


	for (int i = 0; i < x; i++) {

		cin >> MyArray[i];

		if (MyArray[i] == 0) {
			break;
		}

		else {

			size1 = size1 + 1;
		}

	}

	RemoveRepeats(MyArray, NewArray, size1, size2);

	cout << "the new vector is:\n";

	for (int i = 0; i < size2; i++) {
		cout << NewArray[i] << " ";
	}

	cout << endl;
	cout << "number of elements: " << size2 << endl;


	return 0;
}