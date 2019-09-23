#include <iostream>
using namespace std;




int smallest(int * array, int num) {
	if (num == 1) {
		return 0;
	}
	int x = smallest(array, num - 1);

	if (array[num - 1] > array[x]) {
		return x;
	}

	else {
		return num - 1;
	}
}




int main() {
	int * array;
	int num;
	do {
		cout << "enter a number:" << endl;
		cin >> num;

		if (num <= 0)
			cout << "ERROR" << endl;
	} 
	while (num <= 0);

	array = new int[num];

	cout << "enter array values: ";

	for (int i = 0; i < num; i++) {
		cin >> array[i];
	}

	cout << "the smallest is: " << array[smallest(array, num)] << endl;

	return 0;
}