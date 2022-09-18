#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int flag[10];

int main() {
	string input;
	cin >> input;

	for (auto i : input) {
		int temp = i - '0';

		if (temp == 6) {
			if (flag[6] > flag[9]) {
				flag[9]++;
			}
			else {
				flag[6]++;
			}
		}
		else if (temp == 9) {
			if (flag[6] > flag[9]) {
				flag[9]++;
			}
			else {
				flag[6]++;
			}
		}
		else {
			flag[temp]++;
		}
	}

	int result = -1;
	for (int i = 0; i < 10; i++) {
		result = max(result, flag[i]);
	}

	cout << result << '\n';

	return 0;
}