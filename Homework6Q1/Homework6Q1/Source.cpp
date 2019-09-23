#include <iostream>
using namespace std;

double factorial(double x) {
	int n = x;

	for (int i = 1; i < n; i++) {
		x = x * i;

	}
	return x;
}


int main() {

	int const x = 15;
	int list15[x] = {};
	bool good = true;
	double CheckDoubles = factorial(x);

	cout << "enter 15 numbers:\n";
	for (int i = 0; i < x; i++) {

		cin >> list15[i];

		CheckDoubles = CheckDoubles / list15[i];

		if (list15[i] > 15 || list15[i] < 1) {
			good = false;
		}

	}


	if (CheckDoubles == 1) {
		good = true;
	}

	else {
		good = false;
	}

	if (good == true) {
		cout << "GOOD\n";
	}

	else if (good == false) {
		cout << "NOT GOOD\n";
	}


	return 0;
}