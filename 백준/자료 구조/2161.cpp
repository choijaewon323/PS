#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n;
	queue<int> card;
	vector<int> result;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		card.push(i);
	}

	while (card.size() > 1) {
		// 버리기
		int temp = card.front();
		card.pop();
		result.push_back(temp);

		// 옮기기
		temp = card.front();
		card.pop();
		card.push(temp);
	}

	for (auto i : result) {
		cout << i << " ";
	}
	cout << card.front() << '\n';

	return 0;
}