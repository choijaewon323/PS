#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int mul5 = n / 5;
	int mul25 = n / 25;
	int mul125 = n / 125;

	cout << mul5 + mul25 + mul125 << '\n';

	return 0;
}