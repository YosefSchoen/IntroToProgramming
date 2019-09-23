#include <iostream>
using namespace std;

int main() {
	const int x = 500;
	const int y = 100;
	int vector1[x] = {};
	int vector2[y] = {};
	int size1;
	int size2;
	int total = 0;

	cout << "enter size of first array:\n";

	cin >> size1;

	cout << "enter first array values:\n";

	for (int i = 0; i < size1; i++) {

		cin >> vector1[i];
	}

	cout << "enter size of second array:\n";

	cin >> size2;

	cout << "enter second array values:\n";
	for (int i = 0; i < size2; i++) {
		cin >> vector2[i];

	}

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {

			if (vector2[j] != vector1[i + j]) {
				break;
			}

			if (j == size2 - 1) {
				total = total + 1;
			}
		}
	}



	cout << "result: " << total << " times\n";




	return 0;
}