#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

map<string, vector<string>> reportedBy;

map<string, int> cnt;

vector<string> split(string str, char delimit) {
    stringstream ss(str);
    string temp;
    vector<string> result;
    while (getline(ss, temp, delimit)) {
        result.push_back(temp);
    }
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for (string& re : report) {
        vector<string> temp = split(re, ' ');
        string reporter = temp[0];
        string reported = temp[1];
        
        if (reportedBy[reported].empty()) {
            reportedBy[reported].push_back(reporter);
        }
        else {
            bool flag = true;
            for (string& r : reportedBy[reported]) {
                if (r == reporter) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                reportedBy[reported].push_back(reporter);
            }
        }
    }
    
    for (string& id : id_list) {
        if (reportedBy[id].size() >= k) {
            for (string& reporter : reportedBy[id]) {
                cnt[reporter]++;
            }
        }
    }
    
    for (string& id : id_list) {
        answer.push_back(cnt[id]);
    }
    
    return answer;
}