#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500000

vector<int> input;
int N, M;

bool isPresent(int num) {
	int left = 0;
	int right = input.size() - 1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (input[mid] == num) {
			return true;
		} else if (input[mid] < num) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		
		cout << (int)isPresent(num) << '\n';
	}

	return 0;
}