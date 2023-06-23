#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> delim(string s)
{
    istringstream iss(s);
    string buf;
    vector<int> result;
    
    while (getline(iss, buf, ' '))
    {
        int temp = stoi(buf);
        result.push_back(temp);
    }
    
    return result;
}

string solution(string s) 
{
    string answer = "";
    
    vector<int> result = delim(s);
    
    sort(result.begin(), result.end());
    
    answer += to_string(result.front());
    answer += " ";
    answer += to_string(result.back());
    
    return answer;
}