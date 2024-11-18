#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 4000

typedef long long LL;

vector<int> cdNum;
int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        D[i] = d;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cdNum.push_back(C[i] + D[j]);
        }
    }

    sort(cdNum.begin(), cdNum.end());

    LL answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = A[i] + B[j];

            int oppoCnt = upper_bound(cdNum.begin(), cdNum.end(), -num) - lower_bound(cdNum.begin(), cdNum.end(), -num);
            answer += oppoCnt;
        }
    }

    cout << answer << '\n';

    return 0;
}