#include <iostream>
using namespace std;


int main() {

	float list[6] = {};
	int indices[6] = {};
	float min = 1;
	int counter = 0;

	cout << "enter 6 numbers between 0 and 1:\n";

	for (int i = 0; i < 6; i++) {

		cin >> list[i];

		if (list[i] <= 0 || list[i] >= 1) {
			cout << "ERROR:\n";

			i = 0;

			cin >> list[i];
		}



	}

	for (int i = 0; i < 6; i++) {

		for (int j = 0; j < 6; j++) {

			if (list[j] < min) {
				min = list[j];
				counter = j;
			}
		}

		indices[i] = counter;
		min = 1;
		list[counter] = 2;
	}


	cout << "sorted indices:\n";

	for (int i = 0; i < 6; i++) {
		cout << indices[i] << " ";
	}

	cout << endl;

	return 0;
}