#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000

typedef long long ll;

ll segment[MAX * 4 + 1];
int n;

int query(int node, int start, int end, ll rank) {
    if (rank > segment[node]) {
        return -1; // 잘못된 rank 요청 처리
    }

    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    ll cntInSection = segment[node * 2];

    if (cntInSection >= rank) {
        return query(node * 2, start, mid, rank);
    } else {
        return query(node * 2 + 1, mid + 1, end, rank - cntInSection);
    }
}

void update(int node, int start, int end, int index, int diff) {
    if (index < start || end < index) {
        return;
    }

    if (segment[node] + diff < 0) {
        return; // 음수로 내려가는 업데이트는 무시
    }

    segment[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(segment, segment + MAX * 4 + 1, 0); // 세그먼트 트리 초기화

    cin >> n;
    for (int i = 0; i < n; i++) {
        int A, B, C;

        cin >> A;

        if (A == 1) {   // pop
            cin >> B;

            int taste = query(1, 1, 1000000, B);
            cout << taste << '\n';
            update(1, 1, 1000000, taste, -1);
        } else {
            cin >> B >> C;

            update(1, 1, 1000000, B, C);
        }
    }

    return 0;
}
