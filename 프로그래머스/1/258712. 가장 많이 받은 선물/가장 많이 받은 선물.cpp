#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
#include <sstream>

/*
    선물하기
    이번 달까지 선물 주고받은 기록을 바탕으로
    다음달에 누가 선물 많이 받을지 예측

    1. 두 사람이 선물을 주고 받은 기록이 있다면,
        이번 달까지 두 사람 사이에 더 많은 선물 준 사람이 다음달에 선물 하나 받음
    2. 두 사람간 기록이 없거나 같다면, 선물 지수가 더 큰사람이 선물 지수가 더 작은
    사람에게 선물 하나 받음
        선물 지수 : 이번달까지 자신이 친구들에게 준 선물 수 - 받은 선물 수
        *만약 두사람 간 선물 지수까지도 같으면 선물 주고받지 않음
    
    결과 : 선물을 가장 많이 받을 친구가 받을 선물의 수

    친구들의 수 <= 50

    gifts 길이 <= 10,000
    "A B" 형태 문자열 -> A -> B 형태

*/

using namespace std;


map<pair<string, string>, int> giftPair;
map<string, int> sendCnt;
map<string, int> receiveCnt;

map<string, int> result;

vector<string> split(string input, char delimit) {
    stringstream ss(input);
    vector<string> result;
    string temp;

    while (getline(ss, temp, delimit)) {
        result.push_back(temp);
    }

    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = -1;

    for (string& fr : friends) {
        result[fr] = 0;
    }

    for (string& gift : gifts) {
        vector<string> splited = split(gift, ' ');

        string sender = splited[0];
        string receiver = splited[1];

        sendCnt[sender]++;
        receiveCnt[receiver]++;
        
        giftPair[{sender, receiver}]++;
    }

    int friendsSize = friends.size();
    for (int i = 0; i < friendsSize; i++) {
        for (int j = i + 1; j < friendsSize; j++) {
            string friend1 = friends[i];
            string friend2 = friends[j];

            if (giftPair[{friend1, friend2}] != giftPair[{friend2, friend1}]) { // case 1
                if (giftPair[{friend1, friend2}] > giftPair[{friend2, friend1}]) {
                    result[friend1]++;
                }
                else {
                    result[friend2]++;
                }
            }
            else {  // case 2
                int ratio1 = sendCnt[friend1] - receiveCnt[friend1];
                int ratio2 = sendCnt[friend2] - receiveCnt[friend2];
                
                if (ratio1 > ratio2) {
                    result[friend1]++;
                }
                else if (ratio1 < ratio2) {
                    result[friend2]++;
                }
            }
        }
    }

    for (auto iter = result.begin(); iter != result.end(); iter++) {
        answer = max(answer, iter->second);
    }

    return answer;
}