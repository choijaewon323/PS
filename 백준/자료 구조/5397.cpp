#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string l;
		deque<char> left;
		deque<char> right; 
		cin >> l;

		for (auto s : l) {
			switch (s) {
				case '<':
					if (!left.empty()) {
						char temp = left.back();
						left.pop_back();
						right.push_front(temp);
					}
					break;
				case '>':
					if (!right.empty()) {
						char temp = right.front();
						right.pop_front();
						left.push_back(temp);
					}
					break;
				case '-':
					if (!left.empty()) {
						left.pop_back();
					}
					break;
				default:
					left.push_back(s);
			}
		}

		while (!left.empty()) {
			char temp = left.front();
			left.pop_front();
			cout << temp;
		}
		while (!right.empty()) {
			char temp = right.front();
			right.pop_front();
			cout << temp;
		}
		cout << '\n';
	}

	return 0;
}