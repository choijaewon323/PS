#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    if (enemy.size() <= k) {
        return enemy.size();
    }
    
    int soldier = n;
    for (int round = 0; round < enemy.size(); round++) {
        minPQ.push(enemy[round]);
        
        if (minPQ.size() > k) {
            int temp = minPQ.top();
            minPQ.pop();
            
            if (temp > soldier) {
                return round;
            }
            
            soldier -= temp;
        }
    }
    
    return enemy.size();
}