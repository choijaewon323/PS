#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int citaSize = citations.size();
    
    sort(citations.begin(), citations.end());
    
    for (int h = 0; h <= 10000; h++)
    {
        int orMore = 0;
        for (auto c : citations)
        {
            if (c >= h)
            {
                orMore++;
            }
        }
        if (orMore >= h && citaSize - orMore <= h)
        {
            answer = h;
        }
    }
    
    return answer;
}