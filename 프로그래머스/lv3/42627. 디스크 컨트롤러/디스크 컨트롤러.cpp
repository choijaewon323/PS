#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

struct compare
{
    bool operator() (pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    
    queue<pair<int, int>> input;
    
    for (vector<int> job : jobs)
    {
        input.push({job[0], job[1]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    
    vector<int> temp;
    int second = 0;
    while (!(input.empty() && pq.empty()))
    {
        // 요청 시간이 된 job push
        int size = input.size();
        
        for (int i = 0; i < size; i++)
        {
            pair<int, int> tempInput = input.front();
            
            if (tempInput.first <= second)
            {
                pq.push(tempInput);
                input.pop();
            }
        }
        
        // 우선순위 큐에서 하나 pop, 만약 비어있으면 second 1 증가
        if (pq.empty())
        {
            second++;
            continue;
        }
        // 처리 로직
        pair<int, int> present = pq.top();
        pq.pop();
        
        second += present.second;
        temp.push_back(second - present.first);
    }
    
    int size = temp.size();
    double mean = 0;
    for (int t : temp)
    {
        mean += t;
    }
    mean /= size;
    answer = (int)mean;
    
    return answer;
}