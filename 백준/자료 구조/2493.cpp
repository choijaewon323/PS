#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> answers(500001, 0);
	stack<pair<int, int>> towers;
	stack<pair<int, int>> tempTowers;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		towers.push(make_pair(i, temp));
	}
	while (!towers.empty()) {
		pair<int, int> temp = towers.top();
		towers.pop();
		while (!tempTowers.empty()) {
			pair<int, int> smallTemp = tempTowers.top();
			tempTowers.pop();
			if (temp.second > smallTemp.second) {
				answers[smallTemp.first] = temp.first;
			}
			else {
				tempTowers.push(smallTemp);
				break;
			}
		}
		tempTowers.push(temp);
	}
	for (int i = 1; i <= n; i++) {
		cout << answers[i] << " ";
	}
	cout << '\n';
	return 0;
}