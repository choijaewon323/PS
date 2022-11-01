#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             
    string buffer;                      

    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);       
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, int, greater<string>> mp;
    string input;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, input);
        vector<string> parsed = split(input, ' ');
        
        if (parsed[1] == "enter") {
            mp[parsed[0]]++;
        }
        else {
            mp[parsed[0]]--;
        }
    }

    for (auto i : mp) {
        if (i.second == 1) {
            cout << i.first << '\n';
        }
    }

	return 0;
}