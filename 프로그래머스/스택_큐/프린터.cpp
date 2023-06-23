#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    int numOfTask = priorities.size();
    vector<int> answerVec;
    
    for (int i = 0; i < numOfTask; i++) {
        q.push(i);
    }
    
    while (!q.empty()) {
        int present = q.front();
        q.pop();
        
        int tempMax = -1;
        int tempSize = q.size();
        for (int i = 0; i < tempSize; i++) {
            int temp = q.front();
            q.pop();
            
            if (tempMax < priorities[temp]) {
                tempMax = priorities[temp];
            }
            q.push(temp);
        }
        
        if (priorities[present] < tempMax) {
            q.push(present);
        }
        else {
            answerVec.push_back(present);
        }
    }
    
    for (int i = 0; i < numOfTask; i++) {
        if (answerVec[i] == location) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}