#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for (auto c : clothes)
    {
        m[c[1]]++;
    }
    
    for (auto i = m.begin(); i != m.end(); i++)
    {
        answer *= (i->second) + 1;
    }
    
    return answer - 1;
}