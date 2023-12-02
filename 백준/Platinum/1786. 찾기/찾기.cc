#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(const string& P) {
    int m = P.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;

    while (begin + matched < m) {
        if (P[begin + matched] == P[matched]) {
            ++matched;

            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0) {
                ++begin;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

vector<int> kmp(const string& T, const string& P) {
    int n = T.size();
    int m = P.size();

    vector<int> result;
    vector<int> pi = getPi(P);

    int begin = 0, matched = 0;

    while (begin <= n - m) {
        if (matched < m && T[begin + matched] == P[matched]) {
            ++matched;

            if (matched == m) {
                result.push_back(begin);
            }
        }
        else {
            if (matched == 0) {
                ++begin;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
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

    vector<int> answers = kmp(T, P);
    
    cout << answers.size() << '\n';

    for (int ans : answers) {
        cout << ans + 1 << " ";
    }
    cout << '\n';

    return 0;
}