#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef long long LL;

int solution(vector<int> scoville, int K) {
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    
    for (int sc : scoville) {
        pq.push(sc);
    }
    
    int answer = 0;
    while (true) {
        if (pq.size() < 2) {
            break;
        }
        
        LL minimum = pq.top();
        
        if (minimum >= K) {
            return answer;
        }
        
        LL first = pq.top();
        pq.pop();
        LL second = pq.top();
        pq.pop();
        
        LL newSc = first + second * 2;
        pq.push(newSc);
        answer++;
    }
    
    if (pq.top() >= K) {
        return answer;
    } 
    
    return -1;
}