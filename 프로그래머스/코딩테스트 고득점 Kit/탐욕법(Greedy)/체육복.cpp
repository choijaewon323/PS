#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n + 1, 1);
    
    for (auto i : lost)
    {
        students[i]--;
    }
    
    for (auto i : reserve)
    {
        students[i]++;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            if (students[i] == 2 && students[i + 1] == 0)
            {
                students[i]--;
                students[i + 1]++;
            }
            continue;
        }
        if (i == n)
        {
            if (students[i] == 2 && students[i - 1] == 0)
            {
                students[i]--;
                students[i - 1]++;
            }
            continue;
        }
        
        if (students[i] == 2 && students[i - 1] == 0)
        {
            students[i]--;
            students[i - 1]++;
        }
        
        if (students[i] == 2 && students[i + 1] == 0)
        {
            students[i]--;
            students[i + 1]++;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (students[i] == 1 || students[i] == 2)
        {
            answer++;
        }
    }
    
    return answer;
}