#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> banned_list[8];
map<vector<int>, int> listUsed;
bool userUsed[8];

int solve(vector<int> ban, int bannedSize, int bannedIndex) {
    if (ban.size() == bannedSize) {
        sort(ban.begin(), ban.end());
        
        if (listUsed[ban] == 0) {
            listUsed[ban]++;
            return 1;
        }
        else {
            return 0;
        }
    }
    
    int result = 0;
    for (int& banned : banned_list[bannedIndex]) {
        if (!userUsed[banned]) {
            userUsed[banned] = true;
            ban.push_back(banned);
            result += solve(ban, bannedSize, bannedIndex + 1);
            ban.pop_back();
            userUsed[banned] = false;
        }
    }
    return result;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    // banned_list 채우기
    for (int b = 0; b < banned_id.size(); b++) {
        string& banned = banned_id[b];
        
        for (int u = 0; u < user_id.size(); u++) {
            string& user = user_id[u];
            
            if (user.size() != banned.size()) {
                continue;
            }
            
            int size = banned.size();
            bool flag = true;
            for (int i = 0; i < size; i++) {
                if (banned[i] == '*') {
                    continue;
                }
                if (banned[i] != user[i]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                banned_list[b].push_back(u);
            }
        }
    }
    
    vector<int> ban;
    answer = solve(ban, banned_id.size(), 0);
    
    return answer;
}