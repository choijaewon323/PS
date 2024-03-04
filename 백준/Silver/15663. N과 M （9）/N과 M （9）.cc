#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
vector<int> numbers;
bool visited[8];
map<vector<int>, bool> checked;

void pick(vector<int> &arr) {
	if (arr.size() == M) {
		if (checked[arr]) {
			return;
		}
		checked[arr] = true;

		for (int a : arr) {
			cout << a << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr.push_back(numbers[i]);
			pick(arr);
			arr.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());
	vector<int> arr;
	pick(arr);

	return 0;
}