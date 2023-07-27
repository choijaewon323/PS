#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>

using namespace std;

vector<string> split(string input)
{
    istringstream ss(input);
    
    string temp;
    vector<string> result;
    
    while (getline(ss, temp, ' '))
    {
        result.push_back(temp);
    }
    
    return result;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> minPQ;
    priority_queue<int> maxPQ;
    int cnt = 0;
    
    for (string &oper : operations)
    {
        vector<string> input = split(oper);
        
        if (input[0] == "I")
        {
            int number = stoi(input[1]);
            
            minPQ.push(number);
            maxPQ.push(number);
            cnt++;
        }
        else if (input[0] == "D")
        {
            // if empty, continue
            if (cnt == 0)
            {
                continue;
            }
            
            if (input[1] == "1")
            {
                int result = maxPQ.top();
                maxPQ.pop();
                cnt--;
                
                vector<int> temp;
                
                while (!minPQ.empty())
                {
                    int present = minPQ.top();
                    minPQ.pop();
                    
                    if (result == present)
                    {
                        break;
                    }
                    temp.push_back(present);
                }
                
                for (int t : temp)
                {
                    minPQ.push(t);
                }
            }
            else if (input[1] == "-1")
            {
                int result = minPQ.top();
                minPQ.pop();
                cnt--;
                
                vector<int> temp;
                
                while (!maxPQ.empty())
                {
                    int present = maxPQ.top();
                    maxPQ.pop();
                    
                    if (result == present)
                    {
                        break;
                    }
                    temp.push_back(present);
                }
                
                for (int t : temp)
                {
                    maxPQ.push(t);
                }
            }
        }
    }
    
    if (cnt == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxPQ.top());
        answer.push_back(minPQ.top());
    }
    
    return answer;
}