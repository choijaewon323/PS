#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_binary(long long number)
{
    string result = "";
    
    while (true)
    {
        if (number == 0)
        {
            break;
        }
        
        char temp = '0' + (number % 2);
        result += temp;
        
        number /= 2;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

string full_binary(string number)
{   
    int index = 2;
    
    while (true)
    {
        if (number.size() <= index - 1)
        {
            break;
        }
        index *= 2;
    }
    
    string temp = "";
    
    for (int i = 0; i < index - 1 - number.size(); i++)
    {
        temp += "0";
    }
    
    return temp + number;
}

bool isAllZero(string number)
{
    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] == '1')
        {
            return false;
        }
    }
    
    return true;
}

bool solve(string number)
{
    if (number.size() == 1 || isAllZero(number))
    {
        return true;
    }
    
    int mid = number.size() / 2;
    string left = number.substr(0, mid);
    string right = number.substr(mid + 1);
    
    if (number[mid] == '1' && solve(left) && solve(right))
    {
        return true;
    }
    
    return false;
}

vector<int> solution(vector<long long> numbers) 
{
    vector<int> answer;
    
    for (auto &number : numbers)
    {
        string toBinary = to_binary(number);
        string fullBinary = full_binary(toBinary);
        
        bool result = solve(fullBinary);
        
        if (result)
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    
    return answer;
}