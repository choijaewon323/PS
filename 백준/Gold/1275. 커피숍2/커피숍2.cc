#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

typedef long long LL;

LL segment[MAX * 4];
LL input[MAX];
int N, Q;

LL init(int node, int left, int right) {
    if (left == right) {
        return segment[node] = input[left];
    }

    int mid = (left + right) / 2;
    LL leftRes = init(node * 2, left, mid);
    LL rightRes = init(node * 2 + 1, mid + 1, right);

    return segment[node] = leftRes + rightRes;
}

LL query(int node, int left, int right, int nodeLeft, int nodeRight) {
    if (left > nodeRight || right < nodeLeft) {
        return 0;
    }
    if (left <= nodeLeft && nodeRight <= right) {
        return segment[node];
    }

    int mid = (nodeLeft + nodeRight) / 2;
    LL leftRes = query(node * 2, left, right, nodeLeft, mid);
    LL rightRes = query(node * 2 + 1, left, right, mid + 1, nodeRight);

    return leftRes + rightRes;
}

LL update(int node, int index, LL num, int nodeLeft, int nodeRight) {
    if (nodeLeft > index || nodeRight < index) {
        return segment[node];
    }

    if (nodeLeft == nodeRight) {
        return segment[node] = num;
    }

    int mid = (nodeLeft + nodeRight) / 2;
    LL leftRes = update(node * 2, index, num, nodeLeft, mid);
    LL rightRes = update(node * 2 + 1, index, num, mid + 1, nodeRight);

    return segment[node] = leftRes + rightRes;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    init(1, 0, N - 1);

    for (int i = 0; i < Q; i++) {
        LL x, y, a, b;

        cin >> x >> y >> a >> b;

        if (x > y) {
            swap(x, y);
        }

        LL result = query(1, x - 1, y - 1, 0, N - 1);
        update(1, a - 1, b, 0, N - 1);
        cout << result << '\n';
    }

    return 0;
}