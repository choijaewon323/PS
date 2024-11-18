#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
#define INF 1000000001

int input[MAX];
int segment[MAX * 4];
int N, M;

int init(int node, int left, int right) {
    if (left == right) {
        return segment[node] = input[left];
    }
    
    int mid = (left + right) / 2;
    int leftRes = init(node * 2, left, mid);
    int rightRes = init(node * 2 + 1, mid + 1, right);

    return segment[node] = min(leftRes, rightRes);
}

int query(int node, int left, int right, int nodeLeft, int nodeRight) {
    if (right < nodeLeft || nodeRight < left) {
        return INF;
    }

    if (left <= nodeLeft && nodeRight <= right) {
        return segment[node];
    }

    int mid = (nodeLeft + nodeRight) / 2;
    int leftRes = query(node * 2, left, right, nodeLeft, mid);
    int rightRes = query(node * 2 + 1, left, right, mid + 1, nodeRight);

    return min(leftRes, rightRes);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    init(1, 0, N - 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        
        cin >> a >> b;
        cout << query(1, a - 1, b - 1, 0, N - 1) << '\n';   
    }

    return 0;
}