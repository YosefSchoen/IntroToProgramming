#include <iostream>
using namespace std;

int main() {

	int n;

	cout << "enter a one digit  number:\n";

	cin >> n;

	for (int i = n; i >= 1; i--) {

		for (int j = 0; j < (n - i); j++) {

			cout << "   ";

		}



		for (int j = i; j >= 1; j--) {

			if (j > 1) {
				cout << j << ", ";
			}

			else {
				cout << j << endl;
			}
		}

	}
	


	return 0;
}
