#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, answer = 0;
	vector<int> coins;

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int temp;
		
		cin >> temp;
		coins.push_back(temp);
	}

	reverse(coins.begin(), coins.end());

	for (auto coin : coins) {
		answer += k / coin;
		k %= coin;
	}

	cout << answer << '\n';

	return 0;
}