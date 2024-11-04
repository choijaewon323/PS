#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*

    -99 1 2 5 5 7 10

    정수의 개수 N
    1 <= N <= 100,000

    정수는 -10,000 <= x <= 10,000

    시간 제한 : 10,000,000 -> O(N log N) 시간 이하 알고리즘 필요

    우선순위 큐?
    중간에 있는 수를 골라내기 어려움

    양쪽에 우선순위 큐를 둔다면?

    왼쪽 큰수부터 나오는 큐
    오른쪽 작은 수부터 나오는 큐

    만약 둘다 비어있으면
        왼쪽에 넣음
        왼쪽 출력
    만약 왼쪽만 차있고 오른쪽은 비어있으면
        왼쪽 확인
        
        만약 왼쪽보다 present가 크면
            오른쪽 큐에 집어넣음
            왼쪽 출력
        만약 왼쪽보다 작거나 같으면
            왼쪽 뽑음
            오른쪽으로 넣음
    만약 둘다 차잇으면
    
    
*/

#define MAX 100000

int N;
int input[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    priority_queue<int, vector<int>, greater<int>> rightPQ;
    priority_queue<int, vector<int>, less<int>> leftPQ;

    for (int i = 0; i < N; i++) {
        int present = input[i];

        if (leftPQ.empty() && rightPQ.empty()) {
            leftPQ.push(present);
            cout << present << '\n';
        }
        else if (!leftPQ.empty() && rightPQ.empty()) {
            int leftNum = leftPQ.top();

            if (leftNum < present) {
                rightPQ.push(present);
                cout << leftNum << '\n';
            } else {
                leftPQ.pop();
                rightPQ.push(leftNum);
                
                leftPQ.push(present);
                cout << present << '\n';
            }
        }
        else if (!leftPQ.empty() && !rightPQ.empty()) {
            int leftNum = leftPQ.top();
            int rightNum = rightPQ.top();

            if (leftNum <= present && present <= rightNum) {
                leftPQ.push(present);
            } else if (present < leftNum) {
                leftPQ.push(present);
            } else if (present > rightNum) {
                rightPQ.push(present);
            }

            if ((leftPQ.size() + rightPQ.size()) % 2 == 1) {
                if (rightPQ.size() > leftPQ.size()) {
                    while (leftPQ.size() != rightPQ.size() + 1) {
                        int temp = rightPQ.top();
                        rightPQ.pop();
                        leftPQ.push(temp);
                    }
                } else if (rightPQ.size() + 1 < leftPQ.size()) {
                    while (leftPQ.size() != rightPQ.size() + 1) {
                        int temp = leftPQ.top();
                        leftPQ.pop();
                        rightPQ.push(temp);
                    }
                }
                cout << leftPQ.top() << '\n';
            } else {
                if (rightPQ.size() > leftPQ.size()) {
                    while (leftPQ.size() != rightPQ.size()) {
                        int temp = rightPQ.top();
                        rightPQ.pop();
                        leftPQ.push(temp);
                    }
                } else if (leftPQ.size() > rightPQ.size()) {
                    while (leftPQ.size() != rightPQ.size()) {
                        int temp = leftPQ.top();
                        leftPQ.pop();
                        rightPQ.push(temp);
                    }
                }
                cout << leftPQ.top() << '\n';
            }
        }
    }
    
    return 0;
}