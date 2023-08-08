#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	map<char, int> mp;

	string N;
	int B;

	cin >> N >> B;

	char temp = 'A';
	for (int i = 10; i <= 35; i++) {
		mp[temp] = i;
		temp++;
	}

	reverse(N.begin(), N.end());

	int answer = 0;
	for (int i = 0; i < N.size(); i++) {
		char t = N[i];
		int num;

		if ('0' <= t && t <= '9') {
			num = t - '0';
		}
		else {
			num = mp[t];
		}

		answer += num * pow(B, i);
	}

	cout << answer << '\n';

	return 0;
}