#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 50

int N, M;
int knowTruthCount;
bool knowTruth[MAX + 1];
vector<int> party[MAX];

bool isBaseCase() {
	if (knowTruthCount == 0) {
		cout << M << '\n';

		return true;
	}

	return false;
}

void input() {
	cin >> N >> M;
	cin >> knowTruthCount;

	for (int i = 0; i < knowTruthCount; i++) {
		int num;
		cin >> num;

		knowTruth[num] = true;
	}

	for (int i = 0; i < M; i++) {
		int cnt;
		cin >> cnt;

		for (int j = 0; j < cnt; j++) {
			int num;
			cin >> num;

			party[i].push_back(num);
		}
	}
}

bool isContainsTruth(const vector<int>& tempParty) {
	for (int num : tempParty) {
		if (knowTruth[num]) {
			return true;
		}
	}

	return false;
}

void makeAllTruth(const vector<int>& tempParty) {
	for (int num : tempParty) {
		knowTruth[num] = true;
	}
}

void allPossibleTruth() {
	for (int i = 0; i < M; i++) {
		const vector<int> presentParty = party[i];

		if (isContainsTruth(presentParty)) {
			makeAllTruth(presentParty);
		}
	}
}

int solve() {
	for (int i = 0; i < M; i++) {
		allPossibleTruth();
	}

	int result = 0;
	for (int i = 0; i < M; i++) {
		vector<int> presentParty = party[i];

		if (!isContainsTruth(presentParty)) {
			result++;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	if (isBaseCase()) {
		return 0;
	}

	cout << solve() << '\n';
	
	return 0;
}