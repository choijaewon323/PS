#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

#define MAX 40000

int n;
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		arr[i] = temp;
	}

	vector<int> lis;
	lis.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);
		}
		else {
			int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[index] = arr[i];
		}
	}

	int answer = lis.size();

	cout << answer << '\n';

	return 0;
}