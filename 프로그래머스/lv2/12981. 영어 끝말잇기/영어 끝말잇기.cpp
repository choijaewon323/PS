#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> mp;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int wordIndex = 0;
    int turn = 1;
    int peopleIndex = 1;
    string last = "";
    
    int answerPeople = 0;
    int answerTurn = 0;
    
    for (string& word : words) {
        if (last != "") {   // 3번 조건
            if (last.back() != word[0]) {
                answerPeople = peopleIndex;
                answerTurn = turn;
                break;
            }
            else {
                last = word;
            }
        }
        else {
            last = word;
        }
        
        if (mp[word] > 0) { // 4번 조건
            answerPeople = peopleIndex;
            answerTurn = turn;
            break;
        }
        else {
            mp[word]++;
        }
        
        // index check
        peopleIndex++;
        if (peopleIndex > n) {
            peopleIndex = 1;
            turn++;
        }
    }
    
    answer.push_back(answerPeople);
    answer.push_back(answerTurn);

    return answer;
}