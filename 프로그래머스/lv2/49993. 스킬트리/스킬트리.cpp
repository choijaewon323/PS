#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string& st : skill_trees) {
        int index = 0;
        map<char, bool> mp;
        
        // init
        for (char s : skill) {
            mp[s] = true;
        }
        
        bool flag = true;
        for (char s : st) {
            if (mp[s]) {
                if (skill[index] == s) {
                    index++;
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag) {
            answer++;
        }
    }
    
    return answer;
}