#include <iostream>
using namespace std;

int main() {
	int resultIndex, result = -1;
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		for (int j = 0; j < 4; j++) {
			int tempNum;
			cin >> tempNum;
			temp += tempNum;
		}
		if (result < temp) {
			resultIndex = i + 1;
			result = temp;
		}
	}
	cout << resultIndex << " " << result << '\n';
	return 0;
}