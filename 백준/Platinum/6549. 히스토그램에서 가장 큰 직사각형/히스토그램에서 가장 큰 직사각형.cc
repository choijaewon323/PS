#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

#define MAX 100000

LL input[MAX];

int n;

/*
    세그먼트에 뭐가 저장되어 있어야하지?
    first : 가장 낮은 애
    second : 최대 넓이

    4 * 2 < 3 * 3
*/

LL init(int node, int start, int end) {
    if (start == end) {
        return input[start];
    }

    int mid = (start + end) / 2;

    LL left = init(node * 2, start, mid);
    LL right = init(node * 2 + 1, mid + 1, end);

    LL tempMax = input[mid];
    LL lowest = input[mid];
    
    LL tempLeft = mid;
    LL tempRight = mid;
    
    while (true) {
        if (tempLeft == start && tempRight == end) {
            break;
        }

        if (tempLeft - 1 < start) {
            tempRight++;
            lowest = min(lowest, input[tempRight]);
        } else if (tempRight + 1 > end) {
            tempLeft--;
            lowest = min(lowest, input[tempLeft]);
        } else {
            if (input[tempLeft - 1] >= input[tempRight + 1]) {
                tempLeft--;
                lowest = min(lowest, input[tempLeft]);
            } else {
                tempRight++;
                lowest = min(lowest, input[tempRight]);
            }
        }

        int length = tempRight - tempLeft + 1;
            
        tempMax = max(tempMax, length * lowest);
    }

    return max(tempMax, max(left, right));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }

        LL result = init(1, 0, n - 1);

        cout << result << '\n';
    }

    return 0;
}