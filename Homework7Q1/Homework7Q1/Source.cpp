#include <iostream>
using namespace std;


int search(int list[], int size, int x) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int middle = (left + right) / 2;

		if (list[middle] == x) {
			return middle;
		}

		else if (list[middle] > x) {
			right = middle - 1;
		}

		else if (list[middle] > x) {
			left = middle + 1;
		}
	}

	return -1;
}




int main() {
	int num;
	int index = 1;
	const int size = 10;
	int list[size] = {};

	cout << "enter 10 number:\n";
	for (int i = 0; i < size; i++) {
	
		cin >> list[i];

		if (list[i] <= list[i - 1]) {
			cout << "ERROR\n";
			i = 0;
			cin >> list[i];
		}
	}
	
	cout << "enter 1 number:\n";

	cin >> num;

	if (search(list, size, num) == -1) {
		cout << "not found\n";
	}

	else {
		cout << "the number " << num << " was found at index " << search(list, size, num) << endl;
	}

	return 0;
}