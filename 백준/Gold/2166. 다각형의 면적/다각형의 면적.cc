#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef long double LD;
typedef long long LL;

vector<pair<LL, LL>> xy;
int N;

LD absolute(LD x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		LL x, y;
		cin >> x >> y;

		xy.push_back({ x,y });
	}
}

LL calculate(pair<LL, LL> xy1, pair<LL, LL> xy2, pair<LL, LL> xy3) {
	LL x1 = xy1.first;
	LL y1 = xy1.second;
	LL x2 = xy2.first;
	LL y2 = xy2.second;
	LL x3 = xy3.first;
	LL y3 = xy3.second;

	LL temp1 = x1 * y2 + x2 * y3 + x3 * y1;
	LL temp2 = x2 * y1 + x3 * y2 + x1 * y3;
	LL result = temp1 - temp2;
	return result;
}

LD solve() {
	LD result = 0;
	pair<LL, LL> standard = xy[0];

	for (int i = 1; i < N - 1; i++) {
		pair<LL, LL> xy1 = xy[i];
		pair<LL, LL> xy2 = xy[i + 1];

		result += calculate(standard, xy1, xy2);
	}

	return result / 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	cout << fixed;
	cout.precision(1);
	cout << absolute(solve()) << '\n';

	return 0;
}