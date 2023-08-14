#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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

string solution(string s) {
    string answer = "";
    
    vector<string> splited = split(s, ' ');
    
    for (string& sp : splited) {
        if (sp == "") {
            answer += ' ';
            
            continue;
        }
        
        char first = sp[0];
        
        if ('a' <= first && first <= 'z') {
            // upper
            
            sp[0] = sp[0] - ('a' - 'A');
        }
        
        if (sp.size() >= 2) {
            for (int i = 1; i < sp.size(); i++) {
                if ('A' <= sp[i] && sp[i] <= 'Z') {
                    // lower
                    sp[i] = sp[i] + ('a' - 'A');
                }
            }
        }
        
        answer += (sp + ' ');
    }
    
    if (s.size() < answer.size()) {
        int dist = answer.size() - s.size();
        
        answer = answer.substr(0, answer.size() - dist);
    }
    
    return answer;
}