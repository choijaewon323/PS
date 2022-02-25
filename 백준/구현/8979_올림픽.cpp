#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct nation {
	int number;
	int gold;
	int silver;
	int bronze;
	int rank;
} Nation;

bool compare(Nation& n1, Nation& n2) {
	if (n1.gold == n2.gold && n1.silver == n2.silver) {
		return n1.bronze > n2.bronze;
	}
	else if (n1.gold == n2.gold) {
		return n1.silver > n2.silver;
	}
	return n1.gold > n2.gold;
}

int main() {
	int n, k;
	vector<Nation> nations;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		Nation temp;
		cin >> temp.number >> temp.gold >> temp.silver >> temp.bronze;
		nations.push_back(temp);
	}

	sort(nations.begin(), nations.end(), compare);
	
	int temp = 1;
	nations.front().rank = 1;
	for (int i = 1; i < nations.size(); i++) {
		if (nations[i - 1].gold == nations[i].gold &&
			nations[i - 1].silver == nations[i].silver &&
			nations[i - 1].bronze == nations[i].bronze) {
			nations[i].rank = temp;
		}
		else {
			temp = i + 1;
			nations[i].rank = i + 1;
		}
	}

	int answer;

	for (auto& i : nations) {
		if (i.number == k) {
			answer = i.rank;
			break;
		}
	}

	cout << answer << '\n';
	
	return 0;
}