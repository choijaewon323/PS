#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	deque<int> dq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		if (temp == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (temp == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (temp == "pop_front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (temp == "pop_back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (temp == "size") {
			cout << dq.size() << '\n';
		}
		else if (temp == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (temp == "front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		else {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}
	}
	return 0;
}