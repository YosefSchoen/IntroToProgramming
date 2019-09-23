#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 80;


void reverse(char sentence[MAX]) {
	char NewSentence[MAX];
	for (int i = 0; i < strlen(sentence); i++) {
		NewSentence[i] = sentence[(strlen(sentence) - 1) - i];

		cout << strlen((sentence) - 1) - i << ' ';
	}
	
	for (int i = 0; i < strlen(sentence); i++) {
		cout << NewSentence[i];
	}
}

void getLine(char sentence[MAX]){
	cout << "enter a string: " << endl;
	cin.getline(sentence, MAX);
}

int main() {
	char sentence[MAX];
	char NewSentence[MAX];
	getLine(sentence);

	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] == ' ') {
			reverse(sentence);
		}
		else if (i == strlen(sentence)) {
			reverse(sentence);
		}
	}
	

	return 0;
}