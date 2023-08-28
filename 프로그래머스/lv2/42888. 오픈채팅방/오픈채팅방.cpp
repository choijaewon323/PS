#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

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

struct node {
    string uid;
    int state;
};
    
#define ENTER 0
#define LEAVE 1

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<node> results;
    map<string, string> names;
    
    for (string rec : record) {
        vector<string> temp = split(rec, ' ');
        
        string state = temp[0];
        string uid = temp[1];
        
        if (state == "Enter") {
            string nickname = temp[2];
            names[uid] = nickname;
            results.push_back({uid, ENTER});
        }
        else if (state == "Leave") {
            results.push_back({uid, LEAVE});
        }
        else {  // state : Change
            string nickname = temp[2];
            names[uid] = nickname;
        }
    }
    
    for (node& no : results) {
        string nickname = names[no.uid];
        
        if (no.state == ENTER) {
            answer.push_back(nickname + "님이 들어왔습니다.");
        }
        else if (no.state == LEAVE) {
            answer.push_back(nickname + "님이 나갔습니다.");
        }
    }
  
    return answer;
}