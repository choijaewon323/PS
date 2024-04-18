#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> lines;
map<int, int> bToA;
bool isUsed[500001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;

		cin >> a >> b;
		lines.push_back({ a, b });
		bToA[b] = a;
	}

	sort(lines.begin(), lines.end());
	vector<int> arr;
	for (pair<int, int> &temp : lines) {
		arr.push_back(temp.second);
	}

	vector<int> answer;
	vector<int> indexRecord;
	for (int i = 0; i < N; i++) {
		int present = arr[i];

		if (answer.empty()) {
			answer.push_back(present);
			indexRecord.push_back(0);
		} else {
			if (answer.back() < present) {
				indexRecord.push_back(answer.size());
				answer.push_back(present);
			} else {
				int index = lower_bound(answer.begin(), answer.end(), present) - answer.begin();
				
				answer[index] = present;
				indexRecord.push_back(index);
			}
		}
	}

	int initIndex = answer.size() - 1;
	
	for (int i = indexRecord.size() - 1; i >= 0; i--) {
		int index = indexRecord[i];

		if (index == initIndex) {
			initIndex--;
			int realNum = arr[i];
			isUsed[realNum] = true;
		}
	}

	vector<int> result;
	for (pair<int, int> &temp : lines) {
		int b = temp.second;

		if (!isUsed[b]) {
			result.push_back(temp.first);
		}
	}

	cout << result.size() << '\n';
	for (int r : result) {
		cout << r << '\n';
	}
	
	return 0;
}