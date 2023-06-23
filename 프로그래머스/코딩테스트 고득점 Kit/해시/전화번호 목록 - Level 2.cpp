#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
bool isLengthUsed[21];

bool compare(string& a, string& b) 
{
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    
    if (phone_book.size() == 1) 
    {
        return true;
    }
    
    sort(phone_book.begin(), phone_book.end(), compare);
    
    for (auto p : phone_book)
    {
        for (int i = 1; i <= p.size() - 1; i++)
        {
            if (isLengthUsed[i])
            {
                if (m[p.substr(0, i)] != 0)
                {
                    return false;
                }
            }
        }
        m[p]++;
        isLengthUsed[p.size()] = true;
    }
    
    return answer;
}