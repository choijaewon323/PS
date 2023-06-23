#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = yellow; i >= 1; i--)
    {
        int width = i;
        int height = yellow / i;
        
        if (width * height == yellow && width >= height)
        {
            int tempBrown = (width + 2) * 2 + height * 2;
            
            if (tempBrown == brown)
            {
                answer.push_back(width + 2);
                answer.push_back(height + 2);
                break;
            }
        }
    }
    
    return answer;
}