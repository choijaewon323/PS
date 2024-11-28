#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

typedef long long LL;

#define MAX 1000000

LL input[MAX + 1];
LL segment[MAX * 4 + 1];

LL findSum(int node, int start, int end, int left, int right) {
    if (end < left || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return segment[node];
    }

    int mid = (start + end) / 2;
    LL leftSum = findSum(node * 2, start, mid, left, right);
    LL rightSum = findSum(node * 2 + 1, mid + 1, end, left, right);

    return leftSum + rightSum;
}

void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end) {
        return;
    }

    segment[node] += diff;

    int mid = (start + end) / 2;

    if (start != end) {
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;

        if (n == 0) {
            int a, b;
            cin >> a >> b;

            if (a > b) {
                swap(a, b);
            }

            cout << findSum(1, 1, N, a, b) << '\n';
        } else {
            int j, d;

            cin >> j >> d;

            int diff = d - input[j];
            
            input[j] = d;
            update(1, 1, N, j, diff);
        }
    }

    return 0;
}