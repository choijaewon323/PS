#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int r, c, k;
vector<vector<int>> A;
map<int, int> cnt;

bool compare(int a, int b) {
	if (cnt[a] == cnt[b]) {
		return a < b;
	}

	return cnt[a] < cnt[b];
}

void R() {
	int row = A.size();
	int column = A[0].size();
	vector<vector<int>> result(row);

	int maxCol = -1;

	for (int y = 0; y < row; y++) {
		vector<int> temp;
		cnt.clear();

		for (int x = 0; x < column; x++) {
			int num = A[y][x];

			if (num == 0) {
				continue;
			}

			cnt[num]++;
			if (cnt[num] == 1) {
				temp.push_back(num);
			}
		}

		sort(temp.begin(), temp.end(), compare);

		vector<int> tempResult;
		
		int tempSize = temp.size();
		if (tempSize >= 50) {
			for (int i = 0; i < 50; i++) {
				tempResult.push_back(temp[i]);
				tempResult.push_back(cnt[temp[i]]);
			}
		} else {
			for (int i = 0; i < tempSize; i++) {
				tempResult.push_back(temp[i]);
				tempResult.push_back(cnt[temp[i]]);
			}
		}

		maxCol = max(maxCol, (int)tempResult.size());

		result[y] = tempResult;
	}

	for (int y = 0; y < row; y++) {
		int dist = maxCol - result[y].size();

		for (int i = 0; i < dist; i++) {
			result[y].push_back(0);
		}
	}

	A = result;
}

vector<vector<int>> roll(vector<vector<int>> &arr) {
	int row = arr.size();
	int column = arr[0].size();

	vector<vector<int>> result(column, vector<int>(row));

	for (int y = row - 1; y >= 0; y--) {
		for (int x = 0; x < column; x++) {
			int num = arr[y][x];

			result[x][row - y - 1] = num;
		}
	}

	return result;
}

void C() {
	// 뒤부터 수행 후 시계방향 90도 회전하면 똑같음
	int row = A.size();
	int column = A[0].size();
	vector<vector<int>> result;

	int maxCnt = -1;

	for (int x = column - 1; x >= 0; x--) {
		vector<int> temp;
		cnt.clear();

		for (int y = 0; y < row; y++) {
			int num = A[y][x];

			if (num == 0) {
				continue;
			}

			cnt[num]++;
			if (cnt[num] == 1) {
				temp.push_back(num);
			}
		}

		sort(temp.begin(), temp.end(), compare);

		vector<int> tempResult;

		int tempSize = temp.size();
		if (tempSize >= 50) {
			for (int i = 0; i < 50; i++) {
				tempResult.push_back(temp[i]);
				tempResult.push_back(cnt[temp[i]]);
			}
		} else {
			for (int i = 0; i < tempSize; i++) {
				tempResult.push_back(temp[i]);
				tempResult.push_back(cnt[temp[i]]);
			}
		}
		maxCnt = max(maxCnt, (int)tempResult.size());

		result.push_back(tempResult);
	}

	for (int y = 0; y < column; y++) {
		int dist = maxCnt - result[y].size();

		for (int i = 0; i < dist; i++) {
			result[y].push_back(0);
		}
	}

	A = roll(result);
}

void print() {
	for (int y = 0; y < A.size(); y++) {
		for (int x = 0; x < A[y].size(); x++) {
			cout << A[y][x] << " ";
		}
		cout << '\n';
	}

	cout << '\n';
}

void func() {
	int row = A.size();
	int column = A[0].size();
	
	if (row >= column) {
		R();
	} else {
		C();
	}
}

bool inRange() {
	int row = A.size();
	int column = A[0].size();

	if (0 <= r - 1 && r - 1 < row && 0 <= c - 1 && c - 1 < column) {
		return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	A = vector<vector<int>>(3, vector<int>(3));

	cin >> r >> c >> k;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> A[y][x];
		}
	}

	if (inRange() && A[r - 1][c - 1] == k) {
		cout << 0 << '\n';
		return 0;
	}

	for (int second = 1; second <= 100; second++) {
		func();

		if (inRange() && A[r - 1][c - 1] == k) {
			cout << second << '\n';

			return 0;
		}
	}

	cout << -1 << '\n';

	return 0;
}