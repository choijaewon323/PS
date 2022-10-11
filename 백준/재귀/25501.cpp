#include <iostream>
#include <string>
using namespace std;

int countRec;

int recursion(string& s, int l, int r) {
    countRec++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        countRec = 0;
        int result = recursion(s, 0, s.size() - 1);
        cout << result << " " << countRec << '\n';
    }
}