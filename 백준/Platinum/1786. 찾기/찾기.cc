#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(const string &toFind) {
	int m = toFind.size();

	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched < m) {
		if (toFind[begin + matched] == toFind[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;

			continue;
		}

		if (matched == 0) {
			begin++;
			continue;
		}

		begin += matched - pi[matched - 1];
		matched = pi[matched - 1];
	}

	return pi;
}

vector<int> kmp(const string &str, const string &toFind) {
	int n = str.size(), m = toFind.size();

	vector<int> result;

	vector<int> pi = getPi(toFind);

	int begin = 0, matched = 0;

	while (begin <= n - m) {
		if (matched < m && str[begin + matched] == toFind[matched]) {
			++matched;

			if (matched == m) {
				result.push_back(begin);
			}

			continue;
		}

		if (matched == 0) {
			++begin;
			continue;
		}

		begin += matched - pi[matched - 1];
		matched = pi[matched - 1];
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string T, P;

	getline(cin, T);
	getline(cin, P);

	vector<int> results = kmp(T, P);

	cout << results.size() << '\n';

	for (int result : results) {
		cout << result + 1 << " ";
	}
	cout << '\n';

	return 0;
}