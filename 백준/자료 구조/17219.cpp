#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter) {
	istringstream iss(str);
	string buffer;                      

	vector<string> result;

	while (getline(iss, buffer, delimiter)) {
		result.push_back(buffer);               
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	map<string, string> mp;
	cin >> n >> m;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);
		vector<string> result = split(line, ' ');
		mp[result[0]] = result[1];
	}

	for (int i = 0; i < m; i++) {
		string ans;
		cin >> ans;
		cout << mp[ans] << '\n';
	}

	return 0;
}