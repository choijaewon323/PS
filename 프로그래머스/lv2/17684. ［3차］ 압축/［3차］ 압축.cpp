#include <string>
#include <vector>
#include <map>
#include <iostream>


using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> dictionary;
    
    for (int i = 1; i <= 26; i++) {
        string temp = "";
        temp += 'A' + (i - 1);
        dictionary[temp] = i;
    }
    
    // base case
    if (msg.size() == 1) {
        string temp = "";
        temp += msg[0];
        
        answer.push_back(dictionary[temp]);
        
        return answer;
    }
    
    int pushIndex = 27;
    int index = 0;
    
    string temp = "";
    string prev = "";
    
    while (index < msg.size()) {
        temp += msg[index];
            
        if (dictionary[temp] == 0) {
            answer.push_back(dictionary[prev]);
            dictionary[temp] = pushIndex;
            pushIndex++;
            temp = "";
            prev = "";
            index--;
        }
        else {
            prev = temp;
        }
        index++;
    }
    
    answer.push_back(dictionary[temp]);
    
    return answer;
}