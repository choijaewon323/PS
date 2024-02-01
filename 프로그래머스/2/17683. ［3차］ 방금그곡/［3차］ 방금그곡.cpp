#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>

/*
    방금 그곡 서비스 - 음악 제목, 재생 시작되고 끝나 시각, 악보 제공
    
    네오가 기억한 멜로디와 음은 12개
    
    각 음은 1분에 1개씩 재생
    음악은 반드시 처음부터 재생, 음악 길이보다 재생된 시간이 길 때는 끊김없이
    처음부터 반복해서 재생
    
    음악이 00:00 넘겨서 재생은 안됨
    
    조건이 일치하는 음악 여러개 - 재생된 시간이 제일 긴 음악 제목 반환
    재생 시간도 같으면 먼저 입력된 음악 제목 반환
    
    일치하는 음악 없을 때는 (None) 반환
    
    #이 붙은 문자에 대해 새로운 변환을 먼저 실행해야할듯
    
    C# - H
    D# - I
    F# - J
    G# - K
    A# - L
    
*/

using namespace std;

string convertSharp(const string& input) {
    const int inputSize = input.size();
    stack<char> st;
    
    for (int i = 0; i < inputSize; i++) {
        const char c = input[i];
        
        if (c == '#') {
            const char prev = st.top();
            st.pop();
            
            if (prev == 'C') {
                st.push('H');
            }
            else if (prev == 'D') {
                st.push('I');
            }
            else if (prev == 'F') {
                st.push('J');
            }
            else if (prev == 'G') {
                st.push('K');
            }
            else if (prev == 'A') {
                st.push('L');
            }
        }
        else {
            st.push(c);
        }
    }
    
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    
    return result;
}

vector<string> split(const string& input, const char delimit) {
    vector<string> results;
    stringstream ss(input);
    string temp;
    
    while (getline(ss, temp, delimit)) {
        results.push_back(temp);
    }
    
    return results;
}

int countMinute(const string& startTime, const string& endTime) {
    vector<string> start = split(startTime, ':');
    vector<string> end = split(endTime, ':');
    
    const int endMinute = stoi(end[0]) * 60 + stoi(end[1]);
    const int startMinute = stoi(start[0]) * 60 + stoi(start[1]);

    return endMinute - startMinute;
}

string makeMusic(const int minutes, const string& sheet) {
    string result = "";
    
    const int sheetSize = sheet.size();
    int index = 0;
    
    for (int i = 0; i < minutes; i++) {
        result += sheet[index++];
        index %= sheetSize;
    }
    
    return result;
}

vector<int> makePi(const string& toFind) {
    const int findSize = toFind.size();
    
    vector<int> results(findSize, 0);
    
    int start = 1;
    int matched = 0;
    
    while (start + matched < findSize) {
        if (toFind[start + matched] == toFind[matched]) {
            matched++;
            results[start + matched - 1] = matched;
        }
        else {
            if (matched == 0) {
                start++;
            }
            else {
                start += matched - results[matched - 1];
                matched = results[matched - 1];
            }
        }
    }
    
    return results;
}

bool kmp(const string& longText, const string& toFind) {
    vector<int> pi = makePi(toFind);
    int start = 0; 
    int matched = 0;
    
    const int longSize = longText.size();
    const int findSize = toFind.size();
    
    while (start <= longSize - findSize) {
        if (matched < findSize && longText[start + matched] == toFind[matched]) {
            matched++;
            
            if (matched == findSize) {
                return true;
            }
        }
        else {
            if (matched == 0) {
                start++;
            }
            else {
                start += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    
    return false;
}

string solution(string m, vector<string> musicinfos) {
    const string memory = convertSharp(m);
    
    int longMinute = -1;
    string answer = "(None)";
    
    for (string& input : musicinfos) {
        vector<string> infos = split(input, ',');
        
        const string startTime = infos[0];
        const string endTime = infos[1];
        const string title = infos[2];
        const string sheet = convertSharp(infos[3]);
        
        const int minutes = countMinute(startTime, endTime);
        
        const string music = makeMusic(minutes, sheet);
        
        if (kmp(music, memory)) {
            if (minutes > longMinute) {
                answer = title;
                longMinute = minutes;
            }
        }
    }
    
    return answer;
}