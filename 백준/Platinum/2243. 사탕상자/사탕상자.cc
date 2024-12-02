#include <iostream>
#include <algorithm>
using namespace std;

/*
    사탕 : 1 가장 맛남, 1,000,000 가장 맛없음

    n번째로 맛난 사탕 꺼내줌

    구간은 뭘 나타내야 하나?
        seg의 리프 노드 : 사탕의 맛이 i인 사탕의 개수

    
*/

#define MAX 1000000

typedef long long ll;

ll segment[MAX * 4 + 1];
int n;

int query(int node, int start, int end, ll rank) {
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
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int A, B, C;

        cin >> A;

        if (A == 1) {   // pop
            cin >> B;

            int ans = query(1, 1, 1000000, B);
            cout << ans << '\n';
            update(1, 1, 1000000, ans, -1);
        } else {
            cin >> B >> C;

            update(1, 1, 1000000, B, C);
        }
    }

    return 0;
}