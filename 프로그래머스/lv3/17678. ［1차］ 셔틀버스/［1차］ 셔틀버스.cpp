#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimit) {
    stringstream ss(input);
    string temp;
    vector<string> result;
   
    while (getline(ss, temp, delimit)) {
        result.push_back(temp);
    }
    
    return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<pair<int, int>> table;
    
    // 입력 배열 초기화
    for (string& tt : timetable) {
        vector<string> temp = split(tt, ':');
        
        int hour = stoi(temp[0]);
        int min = stoi(temp[1]);
        
        table.push_back({hour, min});
    }
    
    sort(table.begin(), table.end());
    
    // bus 초기화
    vector<pair<int, int>> bus;
    
    bus.push_back({9, 0});
    
    n--;
    
    int initHour = 9;
    int initMin = 0;
    for (int i = 0; i < n; i++) {
        initMin += t;
        
        if (initMin >= 60) {
            initHour += initMin / 60;
            initMin %= 60;
        }
        
        bus.push_back({initHour, initMin});
    }
    
    pair<int, int> tempAnswer;
    
    int idx = 0;
    for (int i = 0; i < bus.size(); i++) {
        pair<int, int> present = bus[i];
        int cnt = 0;
        pair<int, int> last = present;
        
        // 해당 버스에 탈 수 있는 인원들
        while (idx < table.size()) {
            if (table[idx].first > present.first) {
                break;
            }
            
            if (table[idx].first == present.first && table[idx].second > present.second) {
                break;
            }
            
            if (cnt == m) {
                break;
            }
            
            last = table[idx];
            cnt++;
            idx++;
        }
        
        if (cnt < m) {
            tempAnswer = present;
        }
        else {
            tempAnswer = last;
            tempAnswer.second--;
            
            if (tempAnswer.second == -1) {
                tempAnswer.first--;
                tempAnswer.second = 59;
            }
        }
    }
    
    string hour = to_string(tempAnswer.first);
    
    if (hour.size() == 1) {
        hour = '0' + hour;
    }
    
    string min = to_string(tempAnswer.second);
    
    if (min.size() == 1) {
        min = '0' + min;
    }
    
    answer += hour;
    answer += ':';
    answer += min;
    
    return answer;
}