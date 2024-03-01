#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <iostream>

using namespace std;

/*
    A와 B가 n 개의 주사위로 승부
    주사위 6개 면에 각각 하나의 수 쓰여 있음
    주사위를 던졌을 때 각 면이 나올 확률 동일

    각 주사위는 1 ~ n 의 번호 가짐
    주사위에 쓰인 수의 구성은 모두 다름

    A가 먼저 n / 2개 주사위 가져감
    B가 나머지 n / 2개 주사위 가져감

    주사위를 모두 굴린 뒤, 나온 수들을 모두 합해 점수 계산

    점수가 더 큰쪽 승리, 같다면 무승부

    A는 자신이 승리할 확률이 가장 높아지도록 주사위 가져가려 함

    
*/

map<vector<int>, int> mp;

void allCase(vector<vector<int>>& dice, vector<int>& diceIndex, int presentIndex, int acc, vector<int>& result) {
    if (presentIndex == diceIndex.size()) {
        result.push_back(acc);

        return;
    }

    vector<int> presentDice = dice[diceIndex[presentIndex]];
    for (int i = 0; i < 6; i++) {
        int num = presentDice[i];

        allCase(dice, diceIndex, presentIndex + 1, acc + num, result);
    }
}

int winCount(vector<int>& me, vector<int>& oppo) {
    int size = me.size();
    int result = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (me[i] > oppo[j]) {
                result++;
            }
        }
    }

    return result;
}

void makeMap(vector<vector<int>>& dice, vector<int>& diceIndex, int diceSize) {
    if (diceIndex.size() == diceSize) {
        vector<int> me;
        allCase(dice, diceIndex, 0, 0, me);

        vector<bool> visited(dice.size(), false);
        for (int idx : diceIndex) {
            visited[idx] = true;
        }

        vector<int> oppoIndex;
        for (int i = 0; i < visited.size(); i++) {
            bool flag = visited[i];

            if (!flag) {
                oppoIndex.push_back(i);
            }
        }

        vector<int> oppo;
        allCase(dice, oppoIndex, 0, 0, oppo);

        int res = winCount(me, oppo);

        mp[diceIndex] = res;

        return;
    }

    int first;
    if (diceIndex.empty()) {
        first = 0;
    }
    else {
        first = diceIndex.back() + 1;
    }

    int size = dice.size();

    for (int i = first; i < size; i++) {
        diceIndex.push_back(i);
        makeMap(dice, diceIndex, diceSize);
        diceIndex.pop_back();
    }
}

bool compare(pair<vector<int>, int>& a, pair<vector<int>, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;

    int diceSize = dice.size();

    vector<int> initVector;
    makeMap(dice, initVector, diceSize / 2);

    vector<pair<vector<int>, int>> sorted;

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        sorted.push_back({(iter->first), (iter->second)});
    }

    sort(sorted.begin(), sorted.end(), compare);

    answer = sorted.front().first;

    for (int& a : answer) {
        a++;
    }

    return answer;
}