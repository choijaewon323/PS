#include <string>
#include <queue>
#include <vector>

using namespace std;

int makeScoville(vector<int>& scoville, int k)
{
    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    while (true) 
    {
        if (pq.size() >= 2)
        {
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop(); 
        
            if (temp1 >= k)
            {
                break;
            }
        
            int temp = temp1 + (temp2 * 2);
            pq.push(temp);
            result++;
        }
        else {
            break;
        }
    }
    
    if (pq.top() < k)
    {
        return -1;
    }
    else
    {
        return result;
    }
}
    
int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    answer = makeScoville(scoville, K);
    
    return answer;
}