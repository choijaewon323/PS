#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, bool> mp;

bool compare(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    string input = s.substr(1, s.size() - 2);
    
    int index = 0;
        
    vector<vector<int>> numbers;
    
    // 문자열 파싱
    while (index < input.size()) {
        if (input[index] == '{') {
            vector<int> temp;
            string append = "";
            index++;
            
            while (true) {
                if ('0' <= input[index] && input[index] <= '9') {
                    append += input[index];
                }
                else if (input[index] == ',') {
                    temp.push_back(stoi(append));
                    append = "";
                }
                else if (input[index] == '}') {
                    if (!append.empty()) {
                        temp.push_back(stoi(append));
                        append = "";
                    }
                    break;
                }
                index++;
            }
            index++;
            
            if (!temp.empty())
                numbers.push_back(temp);
        }
        else {
            index++;
        }
    }
    
    // 정렬
    sort(numbers.begin(), numbers.end(), compare);
    
    for (vector<int>& num : numbers) {
        for (int n : num) {
            if (!mp[n]) {
                answer.push_back(n);
                mp[n] = true;
            }
        }
    }
    
    return answer;
}