#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
	map<string, int> mp;
	string input;
	string temp;
	int size;
	cin >> input;

	size = input.size();
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < size - i + 1; j++) {
			temp = input.substr(j, i);
			mp[temp]++;
		}
	}

	cout << mp.size() << '\n';

	return 0;
}