#include <iostream>
using namespace std;

int main() {
	int l, p;
	cin >> l >> p;
	int correct = l * p;
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		cout << temp - correct << " ";
	}
	cout << '\n';
	return 0;
}