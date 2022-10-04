#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	stack<int> seqStack;
	stack<int> bigNum;
	vector<int> answer;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		seqStack.push(temp);
	}
	while (!seqStack.empty()) {
		bool flag = true;
		int temp = seqStack.top();
		seqStack.pop();
		while (!bigNum.empty()) {
			int bigTemp = bigNum.top();
			bigNum.pop();
			if (temp < bigTemp) {
				flag = false;
				bigNum.push(bigTemp);
				answer.push_back(bigTemp);
				break;
			}
		}
		if (flag) {
			answer.push_back(-1);
		}
		bigNum.push(temp);
	}
	reverse(answer.begin(), answer.end());
	for (auto ans : answer) {
		cout << ans << " ";
	}
	cout << '\n';
	return 0;
}