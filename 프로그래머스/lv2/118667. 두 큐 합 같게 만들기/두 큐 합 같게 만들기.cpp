#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    queue<int> q1;
    queue<int> q2;
    
    // base case
    ll acc1 = 0;
    for (int q : queue1) {
        acc1 += q;
        q1.push(q);
    }
    ll acc2 = 0;
    for (int q : queue2) {
        acc2 += q;
        q2.push(q);
    }
    if ((acc1 + acc2) % 2 == 1) {
        return -1;
    }
    if (acc1 == acc2) {
        return 0;
    }
    
    int limit = queue1.size() * 4;
    int cnt = 0;
    while (true) {
        
        if (cnt > limit) {
            cnt = -1;
            break;
        }
        
        if (acc1 > acc2) {
            int fr = q1.front();
            acc1 -= fr;
            acc2 += fr;
            q1.pop();
            q2.push(fr);
        }
        else if (acc1 < acc2) {
            int fr = q2.front();
            acc2 -= fr;
            acc1 += fr;
            q2.pop();
            q1.push(fr);
        }
        else {
            break;
        }
        cnt++;
    }
    
    answer = cnt;
    
    return answer;
}