#include <iostream>
using namespace std;



int main() {

	int list1[6] = {};
	int list2[6] = {};
	int newList[6] = {};
	bool keep = true;

	cout << "enter first 6 numbers:\n";

	for (int i = 0; i < 6; i++) {
		cin >> list1[i];
	}

	cout << "enter next 6 numbers:\n";

	for (int i = 0; i < 6; i++) {
		cin >> list2[i];
	}

	cout << "set difference is:\n";
	for (int i = 0; i < 6; i++) {

		for (int j = 0; j < 6; j++) {
			if (list1[i] == list2[j]) {
				keep = false;
				break;
			}
		}
		if (keep == true) {

			newList[i] = list1[i];
		}

		keep = true;
	}

	for (int i = 0; i < 6; i++) {

		if (newList[i] > 0) {
			cout << newList[i] << " ";
		}

	}

	bool empty = false;
	for (int i = 0; i < 6; i++) {
		if (newList[i] == 0 && newList[i + 1] == 0) {
			empty = true;
			cout << "empty\n";
			break;
		}


		else if (empty == false) {
			break;
		}
	}
	return 0;
}
