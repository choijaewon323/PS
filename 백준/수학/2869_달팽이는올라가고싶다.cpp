#include <iostream>
using namespace std;
int main() {
	int a, b, v;
	cin >> a >> b >> v;
	if (v - a == 0) {
		cout << 1 << '\n';
		return 0;
	}
	int result;
	int tempV = v - a;
	result = tempV / (a - b);
	v = a + (tempV % (a - b));
	while (true) {
		v = v - a;
		result++;
		if (v <= 0) {
			cout << result << '\n';
			return 0;
		}
		v = v + b;
	}
	return 0;
}