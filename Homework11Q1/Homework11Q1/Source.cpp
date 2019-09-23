#include <iostream>
using namespace std;

void printABs(int num) {
	if (num > 0) {
		cout << 'a';
		printABs(num - 1);
		cout << 'b';
	}
}

int main() {
	int num;
	cout << "enter a number:" << endl;
	cin >> num;
	printABs(num);
	return 0;
}