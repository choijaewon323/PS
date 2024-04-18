#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000000];
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> lis;
	vector<int> record;
	for (int i = 0; i < N; i++) {
		int num = arr[i];

		if (lis.empty()) {
			lis.push_back(num);
			record.push_back(0);
		} else {
			if (lis.back() < num) {
				record.push_back(lis.size());
				lis.push_back(num);
			} else {
				int index = lower_bound(lis.begin(), lis.end(), num) - lis.begin();

				lis[index] = num;
				record.push_back(index);
			}
		}
	}

	vector<int> answer;
	int initIndex = lis.size() - 1;
	for (int i = N - 1; i >= 0; i--) {
		int index = record[i];

		if (index == initIndex) {
			answer.push_back(arr[i]);
			initIndex--;
		}
	}

	reverse(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int a : answer) {
		cout << a << " ";
	}
	cout << '\n';

	return 0;
}