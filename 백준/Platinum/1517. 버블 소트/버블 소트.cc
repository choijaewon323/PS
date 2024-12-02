#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 500000

typedef long long ll;

int temp[MAX];
int input[MAX];
int N;
ll answer = 0;

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (input[i] <= input[j]) {
            temp[k++] = input[i++];
        } else {
            answer += (ll)(mid - i + 1);
            temp[k++] = input[j++];
        }
    }

    if (i > mid) {
        for (int l = j; l <= end; l++) {
            temp[k++] = input[l];
        }
    } else {
        for (int l = i; l <= mid; l++) {
            temp[k++] = input[l];
        }
    }

    for (int l = start; l <= end; l++) {
        input[l] = temp[l];
    }
}

void mergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        mergeSort(start, mid);
        mergeSort(mid + 1, end);

        merge(start, mid, end);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    
    mergeSort(0, N - 1);

    cout << answer << '\n';

    return 0;
}