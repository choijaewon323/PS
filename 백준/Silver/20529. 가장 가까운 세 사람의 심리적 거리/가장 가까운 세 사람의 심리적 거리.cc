#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

map<vector<string>, int> prevDist;

vector<string> mbti = {
	"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP",
	"ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ"
};

int calculate(string a, string b) {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) {
			result++;
		}
	}
	return result;
}

void makePrev(vector<string> temp) {
	if (temp.size() == 3) {
		int dist = 0;
		dist += calculate(temp[0], temp[1]);
		dist += calculate(temp[1], temp[2]);
		dist += calculate(temp[0], temp[2]);
		prevDist[temp] = dist;
		return;
	}

	for (string m : mbti) {
		temp.push_back(m);
		makePrev(temp);
		temp.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	makePrev(vector<string>());

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N;
		cin >> N;
		map<string, int> cnt;
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			cnt[temp]++;
		}
		int answer = 1000000000;
		for (auto iter = prevDist.begin(); iter != prevDist.end(); iter++) {
			vector<string> present = iter->first;
			int presentCnt = iter->second;

			map<string, int> check;
			for (string s : present) {
				check[s]++;
			}
			
			bool flag = true;
			for (auto it = check.begin(); it != check.end(); it++) {
				string name = it->first;
				int tempCnt = it->second;

				if (cnt[name] < tempCnt) {
					flag = false;
					break;
				}
			}
			if (flag) {
				answer = min(answer, presentCnt);
			}
		}
		cout << answer << '\n';
	}

	return 0;
}