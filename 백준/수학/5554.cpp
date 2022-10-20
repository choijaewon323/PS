#include <iostream>
using namespace std;
int main() {
	int x = 0, y = 0;
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		y += temp;
	}
	x = y / 60;
	y = y % 60;
	cout << x << '\n' << y << '\n';
	return 0;
}