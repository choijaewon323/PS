#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

typedef unsigned long long ULL;

int N, S;
vector<int> origin;
vector<int> leftArr;
vector<int> rightArr;

map<int, ULL> mp;
ULL answer;

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		origin.push_back(temp);
	}

	int mid = N / 2;
	for (int i = 0; i < mid; i++) {
		leftArr.push_back(origin[i]);
	}
	for (int i = mid; i < N; i++) {
		rightArr.push_back(origin[i]);
	}
}

void leftFunc(vector<int> &temp, int index) {
	if (index == leftArr.size()) {
		int result = 0;
		for (int i : temp) {
			result += i;
		}
		mp[result]++;
		return;
	}

	temp.push_back(leftArr[index]);
	leftFunc(temp, index + 1);
	temp.pop_back();

	leftFunc(temp, index + 1);
}

void rightFunc(vector<int> &temp, int index) {
	if (index == rightArr.size()) {
		int result = 0;
		for (int i : temp) {
			result += i;
		}

		answer += mp[S - result];
		return;
	}

	temp.push_back(rightArr[index]);
	rightFunc(temp, index + 1);
	temp.pop_back();

	rightFunc(temp, index + 1);
}

void solve() {
	vector<int> temp;
	leftFunc(temp, 0);
	rightFunc(temp, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	if (S == 0) {
		answer--;
	}
	cout << answer << '\n';

	return 0;
}