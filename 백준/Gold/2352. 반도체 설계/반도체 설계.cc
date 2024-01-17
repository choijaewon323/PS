#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 40000

int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> temp;
	temp.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (temp.back() < arr[i]) {
			temp.push_back(arr[i]);
		}
		else {
			int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
			temp[idx] = arr[i];
		}
	}

	cout << temp.size() << '\n';

	return 0;
}