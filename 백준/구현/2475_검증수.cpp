#include <iostream>
using namespace std;
int square(int number) {
	return number * number;
}
int main() {
	int numbers[5];
	for (int i = 0; i < 5; i++) {
		cin >> numbers[i];
	}
	int result = 0;
	for (int i = 0; i < 5; i++) {
		result += square(numbers[i]);
	}
	cout << result % 10 << '\n';
	return 0;
}