#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long LL;

#define MAX 5000

int N;
int arr[MAX];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
}

vector<int> solve() {
	LL maxValue = 3000000001ll;
	vector<int> answer(3, 0);

	for (int i = 0; i < N - 2; i++) {
		int left = i + 1;
		int right = N - 1;

		while (left < right) {
			LL present = arr[i];
			present += arr[left];
			present += arr[right];

			if (abs(present) < maxValue) {
				maxValue = abs(present);
				answer[0] = arr[i];
				answer[1] = arr[left];
				answer[2] = arr[right];
			}

			if (present < 0) {
				left++;
			} else {
				right--;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	vector<int> answer = solve();
	for (int i = 0; i < 3; i++) {
		cout << answer[i] << " ";
	}
	cout << '\n';

	return 0;
}