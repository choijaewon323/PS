#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX 10
#define ALPHA 26

int N;
string words[MAX];

map<char, int> cost;
map<char, char> mappedNum;

int calcPower(int power) {
	if (power == 0) {
		return 1;
	}
 	return 10 * calcPower(power - 1);
}

bool compare(pair<char, int> &a, pair<char, int> &b) {
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	for (int i = 0; i < N; i++) {
		string& word = words[i];
		
		int wordSize = word.size();
		for (int j = 0; j < wordSize; j++) {
			char c = word[j];

			int power = wordSize - j - 1;
			int presentCost = calcPower(power);
			cost[c] += presentCost;
		}
	}

	vector<pair<char, int>> alpha;
	for (auto iter = cost.begin(); iter != cost.end(); iter++) {
		char key = iter->first;
		int tempCost = iter->second;

		alpha.push_back({ key, tempCost });
	}

	sort(alpha.begin(), alpha.end(), compare);

	char num = '9';
	for (int i = 0; i < alpha.size(); i++) {
		char c = alpha[i].first;
		char num = (char)((9 - i) + '0');
		mappedNum[c] = num;
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		string &word = words[i];

		string temp = "";
		for (char c : word) {
			temp += mappedNum[c];
		}

		answer += stoi(temp);
	}

	cout << answer << '\n';

	return 0;
}