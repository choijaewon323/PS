#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> result;

void solve(vector<int> discount, vector<int> prices, 
                             int size, 
                             vector<vector<int>> users, vector<int> emoticons)
{
    // discount set complete
    if (discount.size() == size)
    {
        pair<int, int> tempResult = {0, 0};
        
        for (int i = 0; i < users.size(); i++)
        {
            int tempSum = 0;
            
            for (int j = 0; j < discount.size(); j++)
            {
                if (discount[j] >= users[i][0])
                {
                    tempSum += prices[j];
                }
            }
            
            // emoticon plus
            if (tempSum >= users[i][1])
            {
                tempResult.first++;
            }
            else    // price plus
            {
                tempResult.second += tempSum;
            }
        }
        
        result.push_back(tempResult);
        
        return;
    }
    
    // choose discount
    for (int d = 10; d <= 40; d += 10)
    {
        int price = emoticons[discount.size()] * (100 - d) / 100;
        
        discount.push_back(d);    
        prices.push_back(price);
        
        solve(discount, prices, size, users, emoticons);
        
        discount.pop_back();
        prices.pop_back();
    }
}

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    int size = emoticons.size();
    
    vector<int> discount;
    vector<int> prices;
    
    solve(discount, prices, size, users, emoticons);
    
    sort(result.begin(), result.end(), compare);
    
    pair<int, int> temp = result.front();
    
    answer.push_back(temp.first);
    answer.push_back(temp.second);
    
    return answer;
}