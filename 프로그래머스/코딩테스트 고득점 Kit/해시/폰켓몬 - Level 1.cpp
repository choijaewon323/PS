#include <vector>
#include <map>
using namespace std;

map<int, int> m;

int solution(vector<int> nums)
{
    int answer = 0;
    
    for (auto n : nums) 
    {
        m[n]++;    
    }
    
    int numsSize = nums.size();
    
    if (m.size() >= numsSize / 2)
    {
        answer = numsSize / 2;
    }
    else 
    {
        answer = m.size();    
    }

    return answer;
}