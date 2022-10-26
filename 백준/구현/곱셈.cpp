#include <iostream>
using namespace std;

int main() {
	int num1, num2;

	cin >> num1 >> num2;

	int tempNum = num2;

	int temp1 = num2 / 100;
	num2 = num2 - (temp1 * 100);
	int temp2 = num2 / 10;
	num2 = num2 - (temp2 * 10);
	int temp3 = num2;

	cout << temp3 * num1 << '\n';
	cout << temp2 * num1 << '\n';
	cout << temp1 * num1 << '\n';
	cout << num1 * tempNum << '\n';

	return 0;
}