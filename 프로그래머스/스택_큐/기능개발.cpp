#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int numOfTask = progresses.size();
    queue<int> q;
    
    for (int i = 0; i < numOfTask; i++) {
        q.push(i);
    }
    
    while (!q.empty()) {
        int count = 0;
        int temp = q.front();
        q.pop();
        count++;
        
        if (progresses[temp] < 100) {
            while (progresses[temp] < 100) {
                for (int i = 0; i < numOfTask; i++) {
                    progresses[i] += speeds[i];
                }
            }
        }
        
        while (!q.empty()) {
            int nextDone = q.front();
            
            if (progresses[nextDone] >= 100) {
                q.pop();
                count++;
            }
            else {
                break;
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}