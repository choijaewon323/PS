#include <iostream>
using namespace std;
int button[3];
int main() {
	int t;
	cin >> t;
	if (t % 10 != 0) {
		cout << -1 << '\n';
	}
	else {
		button[0] = t / 300;
		t = t % 300;
		button[1] = t / 60;
		t = t % 60;
		button[2] = t / 10;
		cout << button[0] << " " << button[1] << " " << button[2] << '\n';
	}
	return 0;
}