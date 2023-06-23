#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int answer = 0;
    
    for (auto& s : sizes)
    {
        if (s[0] < s[1])
        {
            swap(s[0], s[1]);    
        }
    }
    
    int width = -1;
    for (auto s : sizes)
    {
        width = max(width, s[0]);
    }
    
    int height = -1;
    for (auto s : sizes)
    {
        height = max(height, s[1]);
    }
    
    answer = width * height;
    
    return answer;
}