#include <iostream>
using namespace std;

const int Words = 10;
const int Letters = 5;

void bubble(char Matrix[Words][Letters]) {
	char temp[Words][Letters];

	for (int i = 0; i < Letters; i++) {
		for (int j = 0; j < Words; j++) {
			if (Matrix[j][0] == Matrix[j + 1][0]) {
				for (int k = 0; k < Words; k++) {
					temp[k][k] = Matrix[k][k];
					Matrix[k][k] = Matrix[k + 1][k];
					Matrix[k + 1][0] = temp[k][k];
				}
			}
		}
	}

	for (int i = 0; i < Words; i++) {
		for (int j = 0; j < Letters; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	
	char dictionary[Words][Letters];

	cout << "enter 10 words:\n";

	for (int i = 0; i < Words; i++) {
		for (int j = 0; j < Letters; j++) {
			cin >> dictionary[i][j];
		}
	}

	cout << "after sorting:\n";
	bubble(dictionary);

	/*for (int i = 0; i < Words; i++) {
		for (int j = 0; j < Letters; j++) {
			cout << dictionary[i][j] << " ";
		}
		cout << endl;
	}*/



	return 0;
}