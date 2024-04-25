#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define COUNTER 1
#define LINE 0
#define CLOCK -1

typedef long long LL;

struct Line {
	int x1;
	int y1;
	int x2;
	int y2;
};

int ccw(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) {
	LL result = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

	if (result > 0) {
		return COUNTER;
	} else if (result == 0) {
		return LINE;
	} else {
		return CLOCK;
	}
}

bool isIntersact(Line a, Line b) {
	
	int result1 = ccw(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
	int result2 = ccw(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
	int result3 = ccw(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
	int result4 = ccw(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

	int res12 = result1 * result2;
	int res34 = result3 * result4;

	if (res12 == 0 && res34 == 0) {
		pair<int, int> tmp1 = { a.x1, a.y1 };
		pair<int, int> tmp2 = { a.x2, a.y2 };
		pair<int, int> tmp3 = { b.x1, b.y1 };
		pair<int, int> tmp4 = { b.x2, b.y2 };

		if (tmp1 > tmp2) {
			swap(tmp1, tmp2);
		}
		if (tmp3 > tmp4) {
			swap(tmp3, tmp4);
		}

		return tmp3 <= tmp2 && tmp1 <= tmp4;
	}

	return (res12 <= 0 && res34 <= 0);
}

int input() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Line a = { x1, y1, x2, y2 };
	cin >> x1 >> y1 >> x2 >> y2;
	Line b = { x1, y1, x2, y2 };
	
	bool result = isIntersact(a, b);

	if (result) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << input() << '\n';

	return 0;
}