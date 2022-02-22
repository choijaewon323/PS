#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
void move(pair<char, int>& a, pair<char, int>& b) {
	pair<char, int> temp;
	temp = a;
	a = b; 
	b = temp;
}
int main() {
	int n1, n2;
	vector<pair<char, int>> line;
	cin >> n1 >> n2;
	string temp1;
	cin >> temp1;
	reverse(temp1.begin(), temp1.end());
	for (auto i : temp1) {
		line.push_back(make_pair(i, 0));
	}
	string temp2;
	cin >> temp2;
	for (auto i : temp2) {
		line.push_back(make_pair(i, 1));
	}
	int t;
	cin >> t;
	for (int index = 1; index <= t; index++) {
		vector<int> moveIndex;
		for (int i = 1; i < line.size(); i++) {
			if (line[i].second == 1 && line[i - 1].second == 0) {
				moveIndex.push_back(i);
			}
		}
		for (auto in : moveIndex) {
			move(line[in - 1], line[in]);
		}
	}
	for (auto i : line) {
		cout << i.first;
	}
	cout << '\n';
	return 0;
}