#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int n;
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		q.push(temp);
	}
	while (!q.empty()) {
		cout << q.top().first << " " << q.top().second << '\n';
		q.pop();
	}
	return 0;
}