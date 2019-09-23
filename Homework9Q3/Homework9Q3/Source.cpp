#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 80;

int search(char text[MAX], char word[MAX]) {
	bool match = false;
	int TextCounter = 1;
	int WordCounter = 1;
	int JumpCounter = -1;

	if (strlen(word) == 1) {
		return 0;
	}

	for (int i = 0; i < strlen(word); i++) {
		for (int j = 0; j < strlen(text); j++) {
			if (word[i] == text[j]) {
				match = true;
				break;
			}

			else {
				WordCounter = i + 1;
				TextCounter = j + 1;
			}
		}

		if (match == true) {
			break;
		}
	}

	for (int i = WordCounter; i < strlen(word); i++) {
		for (int j = TextCounter; j < strlen(text); j++) {
			if (word[i] == text[j]) {
				return JumpCounter;
			}

			else {
				JumpCounter++;
			}
		}
		
	}

	return -1;
}


int main() {
	char text[MAX];

	cout << "enter text:\n";

	cin.getline(text, MAX);

	char word[MAX];

	cout << "enter word:\n";

	cin.getline(word, MAX);

	cout << "size of jump: " << search(text, word) << endl;

	return 0;
}