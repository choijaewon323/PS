#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

map<string, int> cnt;

void solve(string& order, int limit, int prev, string temp) {
    int size = order.size();
    
    if (temp.size() == limit) {
        sort(temp.begin(), temp.end());
        cnt[temp]++;
        return;
    }
    
    if (prev == -1) {
        for (int i = 0; i < size; i++) {
            solve(order, limit, i, temp + order[i]);
        }
        
        return;
    }
    
    for (int i = prev + 1; i < size; i++) {
        solve(order, limit, i, temp + order[i]);
    }
}

bool compare(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

vector<pair<string, int>> result[11];
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string& order : orders) {
        for (int c : course) {
            solve(order, c, -1, "");
        }
    }
    
    map<string, int>::iterator iter;
    for (iter = cnt.begin(); iter != cnt.end(); iter++) {
        if ((iter->second) >= 2) {
            result[(iter->first).size()].push_back({(iter->first), (iter->second)});
        }
    }
    
    for (int c : course) {
        sort(result[c].begin(), result[c].end(), compare);
        
        if (result[c].empty()) {
            continue;
        }
        
        int tempCnt = result[c].front().second;
        
        for (int i = 0; i < result[c].size(); i++) {
            if (tempCnt == result[c][i].second) {
                answer.push_back(result[c][i].first);
                continue;
            }
            
            if (tempCnt > result[c][i].second) {
                break;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}