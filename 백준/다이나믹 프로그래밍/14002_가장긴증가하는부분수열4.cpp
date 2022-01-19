#include <iostream>
#include <vector>
using namespace std;
int arr[1001];
vector<vector<int>> dp(1001);
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	int answerIndex = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1].push_back(arr[1]);
	for (int i = 2; i <= n; i++) {
		int tempLength = 0;
		int tempIndex = -1;
		for (int j = 1; j <= i - 1; j++) {
			if (dp[j].size() > tempLength && dp[j].back() < arr[i]) {
				tempLength = dp[j].size();
				tempIndex = j;
			}
		}
		if (tempIndex != -1) {
			for (auto temp : dp[tempIndex]) {
				dp[i].push_back(temp);
			}
			dp[i].push_back(arr[i]);
		}
		else {
			dp[i].push_back(arr[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dp[answerIndex].size() < dp[i].size()) {
			answerIndex = i;
		}
	}
	cout << dp[answerIndex].size() << '\n';
	for (auto i : dp[answerIndex]) {
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}