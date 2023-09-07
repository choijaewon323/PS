#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    map<string, int> tempCnt;
    
    for (string& gem : gems) {
        tempCnt[gem]++;
    }
    
    int allSize = tempCnt.size();
    int size = gems.size();
    
    map<string, int> mp;
    
    int left = 0;
    int right = 0;
    mp[gems[left]]++;
    int answerLeft = 0;
    int answerRight = size;
    
    while (left <= right && right < size) {
        if (allSize == mp.size()) { // 만족하는 경우
            int range = right - left + 1;
            
            if (range < answerRight - answerLeft + 1) {
                answerLeft = left;
                answerRight = right;
            }
            else if (range == answerRight - answerLeft + 1) {
                answerLeft = min(answerLeft, left);
                answerRight = min(answerRight, right);
            }
            
            mp[gems[left]]--;
            if (mp[gems[left]] == 0) {
                auto it = mp.find(gems[left]);
                mp.erase(it);
            }
            left++;
            
            continue;
        }
        
        // 만족하지 않는 경우
        right++;
        if (right < size) {
            mp[gems[right]]++;
        }
    }
    
    answer.push_back(answerLeft + 1);
    answer.push_back(answerRight + 1);
    
    return answer;
}