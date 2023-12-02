#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPi(const string& str) {
    int size = str.size();

    vector<int> pi(size, 0);

    int begin = 1, matched = 0;

    while (begin + matched < size) {
        if (str[begin + matched] == str[matched]) {
            matched++;

            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int L;
    string input;

    cin >> L;
    cin >> input;

    vector<int> answers = getPi(input);
    
    int answer = L - answers[L - 1];

    cout << answer << '\n';

    return 0;
}