#include <iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	int left = 1, right = 1;
	if (x == 1) {
		cout << left << "/" << right << '\n';
		return 0;
	}
	left = 1, right = 2;
	if (x == 2) {
		cout << left << "/" << right << '\n';
		return 0;
	}
	int i = 2;
	bool flagLeft = false, flagRight = true;
	while (true) {
		if (flagRight) {
			while (true) {
				right--;
				left++;
				i++;
				if (i == x) {
					cout << left << "/" << right << '\n';
					return 0;
				}
				if (right == 1) {
					left++;
					i++;
					if (i == x) {
						cout << left << "/" << right << '\n';
						return 0;
					}
					flagRight = false;
					flagLeft = true;
					break;
				}
			}
		}
		else if (flagLeft) {
			while (true) {
				left--;
				right++;
				i++;
				if (i == x) {
					cout << left << "/" << right << '\n';
					return 0;
				}
				if (left == 1) {
					right++;
					i++;
					if (i == x) {
						cout << left << "/" << right << '\n';
						return 0;
					}
					flagRight = true;
					flagLeft = false;
					break;
				}
			}
		}
	}
	return 0;
}