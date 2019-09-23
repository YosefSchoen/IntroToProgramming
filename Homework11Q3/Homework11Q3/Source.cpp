#include <iostream>
using namespace std;


void swap(int * array, int i, int j);
int smallest(int * array, int num);
void sort(int * array, int num);

int main() {
	int * arr;
	int num;
	do {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num <= 0)
			cout << "ERROR" << endl;
	} while (num <= 0);
	arr = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	cout << "before: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	sort(arr, num);
	cout << "after: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}


void swap(int * array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

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

void sort(int * array, int num) {

	if (num == 1) {
		return;
	}
	
	int x = smallest(array, num);

	swap(array, 0, x);

	sort(array + 1, num - 1);

}