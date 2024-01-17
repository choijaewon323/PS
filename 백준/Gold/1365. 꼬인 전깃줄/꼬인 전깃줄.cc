#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100000

int N;
int arr[MAX];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int lis() {
	vector<int> temp;
	temp.push_back(arr[0]);

	for (int i = 1; i < N; i++) {
		if (temp.back() < arr[i]) {
			temp.push_back(arr[i]);
		}
		else {
			int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();

			temp[index] = arr[i];
		}
	}

	return temp.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	int result = lis();

	int answer = N - result;

	cout << answer << '\n';

	return 0;
}