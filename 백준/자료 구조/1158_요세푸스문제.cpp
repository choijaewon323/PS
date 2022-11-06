#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<int> perm;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 1; i <= k - 1; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		int num = q.front();
		q.pop();
		perm.push_back(num);
	}
	cout << "<";
	for (int i = 0; i < perm.size() - 1; i++) {
		cout << perm[i] << ", ";
	}
	cout << perm.back() << ">" << '\n';
	return 0;
}