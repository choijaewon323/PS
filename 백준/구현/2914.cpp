#include <iostream>
using namespace std;

int main() {
	int numOfSongs, aver;

	cin >> numOfSongs >> aver;

	if (numOfSongs == 1 && aver == 1) {
		cout << 1 << '\n';
		return 0;
	}

	if (numOfSongs == 1) {
		cout << numOfSongs * aver << '\n';
	}
	else if (aver == 1) {
		cout << numOfSongs << '\n';
	}
	else {
		cout << numOfSongs * (aver - 1) + 1 << '\n';
	}

	return 0;
}