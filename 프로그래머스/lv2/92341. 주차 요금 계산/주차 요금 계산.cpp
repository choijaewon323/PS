#include <string>
#include <vector>
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

int carIn[10000];
int carResult[10000];

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // init
    for (int i = 0; i < 10000; i++) {
        carIn[i] = -1;
    }
    
    
    for (string& record : records) {
        vector<string> tempRecord = split(record, ' ');
        
        string time = tempRecord[0];
        int carNum = stoi(tempRecord[1]);
        string state = tempRecord[2];
        
        vector<string> tempTime = split(time, ':');
        
        int minute = stoi(tempTime[0]) * 60 + stoi(tempTime[1]);
        
        if (state == "IN") {
            carIn[carNum] = minute;
        }
        else {  // OUT
            int in = carIn[carNum];
            carIn[carNum] = -1;
            
            carResult[carNum] += minute - in;
        }
    }
    
    int last = 23 * 60 + 59;
    
    // rest
    for (int i = 0; i < 10000; i++) {
        if (carIn[i] != -1) {
            carResult[i] += last - carIn[i];
        }
    }
    
    // calculation
    for (int i = 0; i < 10000; i++) {
        if (carResult[i] != 0) {
            if (carResult[i] <= fees[0]) {
                answer.push_back(fees[1]);
            }
            else {
                int result = fees[1];
                carResult[i] -= fees[0];
                
                int cnt = carResult[i] / fees[2];
                
                if (carResult[i] % fees[2] != 0) {
                    cnt++;
                }
                
                result += fees[3] * cnt;
                answer.push_back(result);
            }
        }
    }
    
    return answer;
}