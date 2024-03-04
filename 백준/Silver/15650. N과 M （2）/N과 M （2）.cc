#include <iostream>
#include <vector>
using namespace std;

int N, M;

void pick(vector<int> &arr, int before) {
	if (arr.size() == M) {
		for (int a : arr) {
			cout << a << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = before + 1; i <= N; i++) {
		arr.push_back(i);
		pick(arr, i);
		arr.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	vector<int> arr;
	pick(arr, 0);

	return 0;
}