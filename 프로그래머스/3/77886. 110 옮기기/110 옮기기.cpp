#include <string>
#include <vector>
#include <algorithm>
#include <stack>

/*
    0과 1로 이루어진 문자열 x에 대해, 어떤 연산을 통해 x를 최대한 사전 순으로 앞에 오도록 만들고자 함
    
    어떤 연산 : x에 있는 110을 뽑아서, 임의의 위치에 다시 삽입
    
    예) x = "11100"일 때, 중앙의 "110"을 뽑으면 "10"이 되고, 이를 x의 맨 앞에
    삽입하면 x = "11010"이 된다.
    
    규칙성
    111이 발견되었을 때, 110이 있는 경우 111의 앞에 110을 붙인다.
*/

using namespace std;

int findLastZero(string str)
{
    int result = -1;
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '0')
        {
            result = i;
        }
    }
    return result;
}

string substring(string rest, int lastZero)
{
    string result = "";
    for (int i = 0; i <= lastZero; i++)
    {
        result += rest[i];
    }
    return result;
}

string convert(string number)
{
    stack<char> st;
    string zero = "011";
    
    int size = number.size();
    
    int numberOf110 = 0;
    
    for (int i = 0; i < size; i++)
    {
        char c = number[i];
        
        st.push(c);
        
        if (st.size() >= 3 && st.top() == '0')
        {
            int index = 0;
            vector<char> temp;
            bool flag = false;
            
            while (st.top() == zero[index])
            {
                temp.push_back(st.top());
                st.pop();
                index++;
                
                if (index == 3)
                {
                    flag = true;
                    break;
                }
            }
            
            if (flag)
            {
                numberOf110++;
            }
            else
            {
                for (int i = temp.size() - 1; i >= 0; i--)
                {
                    st.push(temp[i]);
                }
            }
        }
    }
    
    string rest = "";
    while (!st.empty())
    {
        rest += st.top();
        st.pop();
    }
    
    reverse(rest.begin(), rest.end());
    
    string result = "";
    
    int zeroIndex = findLastZero(rest);
    
    if (zeroIndex == -1)
    {
        for (int i = 0; i < numberOf110; i++) 
        {
            result += "110";
        }
        
        result += rest;
    }
    else
    {
        int index = zeroIndex;
        
        string substr = substring(rest, index);
        
        result += substr;
        for (int i = 0; i < numberOf110; i++)
        {
            result += "110";
        }
        for (int i = substr.size(); i < rest.size(); i++)
        {
            result += rest[i];
        }
    }
    
    return result;
}

vector<string> solution(vector<string> s) 
{
    vector<string> answer;
    
    for (string number : s)
    {
        answer.push_back(convert(number));
    }
    
    return answer;
}