#include <iostream>
using namespace std;

int main() {
	int x;
	int n;
	float sum = 0;

	cout << "enter 2 numbers:\n";

	cin >> x >> n;

	while (n < 0) {
		cout << "ERROR\n";

		cin >> n;
	}

	for (int i = 1; i <= n; i++) {

		int abrX = 1;
		int sign = 1;

		for (int j = 1; j <= i - 1; j++) {
			sign = sign * -1;
		}

		for (int j = 1; j <= (2 * i) - 1; j++) {
			abrX = abrX * x;
		}

		sum = sum + ((sign / ((2.0 * i) - 1)) * abrX);
	}

	cout << sum << endl;

	return 0;
}