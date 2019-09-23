#include <iostream>
using namespace std;

int main() {
	int num;
	int next = 0;
	int prev = 0;
	bool sorted = true;


	cout << "enter a number:" << endl;

	cin >> num;

	while (num < 0) {

		cout << "ERROR" << endl;
		cin >> num;

	}

	for (num; num % 10 > 0; num = num / 10) {

		next = num % 10;

		if (next < prev) {
			sorted = false;
		}
		prev = next;
	}
	if (sorted) {
		cout << "YES\n";
	}

	else {
		cout << "NO\n";
	}

	return 0;
}