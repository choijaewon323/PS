#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int book[24][60];

vector<string> split(string input, char delimit) {
    stringstream ss(input);
    string temp;
    vector<string> result;
    
    while (getline(ss, temp, delimit)) {
        result.push_back(temp);
    }
    
    return result;
}

void timeCalc(int startHH, int startMM, int endHH, int endMM) {
    if (startHH != endHH) {
        for (int h = startHH; h <= endHH; h++) {
            if (h == endHH) {
                for (int m = 0; m < endMM; m++) {
                    book[h][m]++;
                }
            }
            else if (h == startHH) {
                for (int m = startMM; m <= 59; m++) {
                    book[h][m]++;
                }
            }
            else {
                for (int m = 0; m <= 59; m++) {
                    book[h][m]++;
                }
            }
        }
    }
    else {
        for (int m = startMM; m < endMM; m++) {
            book[startHH][m]++;
        }
    }
}

void clean(int endHH, int endMM) {
    if (endHH == 23) {
        for (int m = endMM; m < endMM + 10; m++) {
            if (m > 59) {
                continue;
            }
            book[endHH][m]++;
        }
    }
    else {
        int cnt = 0;
        while (cnt != 10) {
            book[endHH][endMM]++;
            endMM++;
            if (endMM == 60) {
                endMM = 0;
                endHH++;
            }
            cnt++;
        }
    }
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for (vector<string>& input : book_time) {
        vector<string> start = split(input[0], ':');
        vector<string> end = split(input[1], ':');
        
        int startHH = stoi(start[0]);
        int startMM = stoi(start[1]);
        int endHH = stoi(end[0]);
        int endMM = stoi(end[1]);
        
        timeCalc(startHH, startMM, endHH, endMM);
        clean(endHH, endMM);
    }
    
    for (int h = 0; h <= 23; h++) {
        for (int m = 0; m <= 59; m++) {
            answer = max(answer, book[h][m]);
        }
    }
    
    return answer;
}