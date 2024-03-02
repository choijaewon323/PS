#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

#define MAX 10000

vector<bool> visited;

int D(int num) {
	return num * 2 % 10000;
}

int S(int num) {
	if (num == 0) {
		return 9999;
	}
	return num - 1;
}

int L(int num) {
	int fourth = num / 1000;
	num %= 1000;
	int third = num / 100;
	num %= 100;
	int second = num / 10;
	int first = num % 10;
	
	return third * 1000 + second * 100 + first * 10 + fourth;
}

int R(int num) {
	int fourth = num / 1000;
	num %= 1000;
	int third = num / 100;
	num %= 100;
	int second = num / 10;
	int first = num % 10;

	return first * 1000 + fourth * 100 + third * 10 + second;
}

string bfs(int start, int end) {
	visited[start] = true;
	queue<pair<int, string>> q;
	q.push({ start, "" });

	while (!q.empty()) {
		int present = q.front().first;
		string opers = q.front().second;
		q.pop();

		if (present == end) {
			return opers;
		}

		int d = D(present);
		if (!visited[d]) {
			visited[d] = true;
			q.push({ d, opers + 'D' });
		}

		int s = S(present);
		if (!visited[s]) {
			visited[s] = true;
			q.push({ s, opers + 'S' });
		}

		int l = L(present);
		if (!visited[l]) {
			visited[l] = true;
			q.push({ l, opers + 'L' });
		}

		int r = R(present);
		if (!visited[r]) {
			visited[r] = true;
			q.push({ r, opers + 'R' });
		}
	}

	return "";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int A, B;
		cin >> A >> B;
		
		visited = vector<bool>(MAX, false);
		string result = bfs(A, B);
		cout << result << '\n';
	}

	return 0;
}