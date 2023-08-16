#include <iostream>

using namespace std;

int main() {
	int input;

	cin >> input;

	int change = 1000 - input;

	int answer = 0;

	while (change > 0) {
		if (change >= 500) {
			change -= 500;
		}
		else if (change >= 100) {
			change -= 100;
		}
		else if (change >= 50) {
			change -= 50;
		}
		else if (change >= 10) {
			change -= 10;
		}
		else if (change >= 5) {
			change -= 5;
		}
		else {
			change--;
		}
		answer++;
	}

	cout << answer << '\n';

	return 0;
}