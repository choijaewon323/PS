#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int d;
	cin >> d;

	int temp = d;
	a += temp / 3600;
	temp %= 3600;

	b += temp / 60;
	temp %= 60;

	c += temp;

	if (c >= 60) {
		b++;
		c %= 60;
	}

	if (b >= 60) {
		a++;
		b %= 60;
	}

	if (a >= 24) {
		a %= 24;
	}

	cout << a << " " << b << " " << c << '\n';

	return 0;
}