#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    string tempA = to_string(a);
    string tempB = to_string(b);
    
    return tempA + tempB > tempB + tempA;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    for (auto n : numbers)
    {
        answer += to_string(n);
    }
    
    if (answer[0] == '0')
    {
        return "0";
    }
    
    return answer;
}