#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	string temp1 = to_string(a) + to_string(b);
	string temp2 = to_string(c) + to_string(d);

	int64_t ab = stoll(temp1);
	int64_t cd = stoll(temp2);
	int64_t result = ab + cd;

	cout << result << '\n';

	return 0;
}