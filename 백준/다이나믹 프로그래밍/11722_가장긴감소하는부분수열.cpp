#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= i - 1; j++) {
			if (temp < dp[j] && arr[i] < arr[j]) {
				temp = dp[j];
			}
		}
		dp[i] = temp + 1;
	}
	int answer = -1;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << '\n';
	return 0;
}