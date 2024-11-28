#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
#define INF 1000000001

int input[MAX + 1];
int segment[MAX * 4 + 1];
int N, M;

/*
    segment[] = 구간 내에서 가장 작은 값
*/
int init(int node, int start, int end) {
    if (start == end) {
        return segment[node] = input[start];
    }

    int mid = (start + end) / 2;
    int left = init(node * 2, start, mid);
    int right = init(node * 2 + 1, mid + 1, end);

    return segment[node] = min(left, right);
}

int findMin(int node, int start, int end, int left, int right) {
    if (end < left || start > right) {
        return INF;
    }

    if (left <= start && end <= right) {
        return segment[node];
    }

    int mid = (start + end) / 2;
    int leftMin = findMin(node * 2, start, mid, left, right);
    int rightMin = findMin(node * 2 + 1, mid + 1, end, left, right);

    return min(leftMin, rightMin);
}

int update(int node, int start, int end, int index, int to) {
    if (index < start || index > end) {
        return segment[node];
    }

    if (start == end) {
        if (start == index) {
            return segment[node] = to;
        }
        return INF;
    }

    int mid = (start + end) / 2;
    
    int left = update(node * 2, start, mid, index, to);
    int right = update(node * 2 + 1, mid + 1, end, index, to);

    return segment[node] = min(left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> input[i];
    }

    init(1, 1, N);

    cin >> M;
    for (int j = 0; j < M; j++) {
        int a, b, c;

        cin >> a >> b >> c;
        if (a == 1) {

            input[b] = c;
            update(1, 1, N, b, c);
        } else {
            cout << findMin(1, 1, N, b, c) << '\n';
        }
    }

    return 0;
}