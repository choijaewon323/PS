#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

string removeSq(string& arr) {
	string temp = arr.substr(1);
	int size = temp.size();
	string result = temp.substr(0, size - 1);
	return result;
}

deque<int> parser(string& arr) {
	string separator = ",";
	int cur_position = 0;
	int position;
	deque<int> results;

	while ((position = arr.find(separator, cur_position)) != string::npos) {
		int len = position - cur_position;
		string temp = arr.substr(cur_position, len);
		results.push_back(stoi(temp));
		cur_position = position + 1;
	}

	string temp = arr.substr(cur_position);
	results.push_back(stoi(temp));

	return results;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		string arr;
		cin >> arr;

		if (n == 0) {
			bool flag = true;
			for (auto str : p) {
				if (str == 'D') {
					cout << "error" << '\n';
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << "[]" << '\n';
			}
		}
		else {
			string noSquare = removeSq(arr);
			deque<int> numbers = parser(noSquare);
			bool flag = true;
			char status = 'F';
			
			for (auto str : p) {
				if (str == 'R') {
					if (status == 'F') {
						status = 'R';
					}
					else {
						status = 'F';
					}
				}
				else {
					if (numbers.empty()) {
						cout << "error" << '\n';
						flag = false;
						break;
					}
					else {
						if (status == 'F') {
							numbers.pop_front();
						}
						else {
							numbers.pop_back();
						}
					}
				}
			}
			if (flag) {
				cout << "[";
				while (!numbers.empty()) {
					int temp;
					if (status == 'F') {
						temp = numbers.front();
						numbers.pop_front();
					}
					else {
						temp = numbers.back();
						numbers.pop_back();
					}

					if (numbers.empty()) {
						cout << temp;
						break;
					}
					else {
						cout << temp << ",";
					}
				}
				cout << "]" << '\n';
			}
		}
	}

	return 0;
}