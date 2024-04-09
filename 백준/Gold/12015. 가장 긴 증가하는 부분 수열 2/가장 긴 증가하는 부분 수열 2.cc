#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000000

int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> result;
	for (int i = 0; i < N; i++) {
		int present = arr[i];

		if (result.empty()) {
			result.push_back(present);
		} else {
			int back = result.back();

			if (back < present) {
				result.push_back(present);
			} else {
				int index = lower_bound(result.begin(), result.end(), present) - result.begin();
				
				result[index] = present;
			}
		}
	}

	int answer = result.size();

	cout << answer << '\n';

	return 0;
}