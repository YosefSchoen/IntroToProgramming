#include <iostream>
using namespace std;

int main() {
	const int V1Max = 500;
	const int V2Max = 100;
	int vector1[V1Max];
	int vector2[V2Max];
	int v1Size;
	int v2Size;

	cout << "enter size of first array:\n";

	cin >> v1Size;

	for (int i = 0; i < v1Size; i++) {
		cin >> vector1[i];
	}

	cout << "enter size of the second array\n";

	cin >> v2Size;

	for (int i = 0; i < v2Size; i++) {
		int match = 0;

		cin >> vector2[i];

		for (int j = 0; j < v1Size; j++) {
			if (vector2[i] == vector1[j]) {
				match = match + 1;
			}
		}
		cout << match << endl;
	}


	return 0;
}