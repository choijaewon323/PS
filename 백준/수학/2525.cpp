#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b;
	cin >> c;
	a =  (c / 60 + a) % 24;
	int temp = c % 60 + b;
	if (temp >= 60) {
		a++;
		a %= 24;
	}
	b = temp % 60;
	cout << a << " " << b << '\n';
	return 0;
}