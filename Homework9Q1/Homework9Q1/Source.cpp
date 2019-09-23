#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 80;

char crypto(char num) {
	char min = 97;
	char max = 122;
	char CryptoNum = -1;

	if (num < 97 || num > 122) {
		CryptoNum == num;
	}
	else if (num >= 97 || num <= 122) {
		for (int i = 0; i < 26; i++) {
			if (num - i == min) {
				CryptoNum = max - i;
			}
		}
	}
	return CryptoNum;
}

int main() {
	char MyString[MAX];

	cout << "enter a string:\n";

	for (int i = 0; i < MAX; i++) {
		cin >> MyString[i];
	}

	cout << "after crypto:\n";

	for (int i = 0; i < MAX; i++) {
		cout << crypto(MyString[i]);
	}

	return 0;
}