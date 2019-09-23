#include <iostream>
using namespace std;


void swap(int * arr, int i, int j);
void reverse(int * arr, int num);

int main() {
	int * arr;
	int num;

	cout << "enter a number: ";
	cin >> num;

	arr = new int[num];

	cout << "enter array values: ";

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	cout << "before: \n";

	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	reverse(arr, num);

	cout << "after: \n";

	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}

void swap(int * arr, int i, int j) {

	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void reverse(int * arr, int num) {

	if (num > 1) {
		swap(arr, 0, num - 1);
		reverse(arr + 1, num - 2);
	}
}