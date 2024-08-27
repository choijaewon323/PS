#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define NONE 0
#define MY 1
#define DISCARD 2
#define DECK 3

int sumNumber;

int numbers[1001];

vector<int> my;
set<int> discard;

void init(vector<int>& cards) {
    int size = cards.size();
    
    for (int i = 0; i < size / 3; i++) {
        int num = cards[i];
        numbers[num] = MY;
        my.push_back(num);
    }
}

bool checkNonCoin() {
    int mySize = my.size();
    
    for (int i = 0; i < mySize; i++) {
        for (int j = i + 1; j < mySize; j++) {
            if (my[i] + my[j] == sumNumber) {
                my.erase(my.begin() + j);
                my.erase(my.begin() + i);
                
                return true;
            }
        }
    }
    
    return false;
}

bool checkOneCoin() {
    int mySize = my.size();
    
    for (int i = 0; i < mySize; i++) {
        int num = my[i];
        
        int restNum = sumNumber - num;
        
        if (discard.find(restNum) != discard.end()) {
            my.erase(my.begin() + i);
            discard.erase(restNum);
            return true;
        }
    }
    return false;
}

bool checkTwoCoin() {
    vector<int> temp;
    
    for (auto iter = discard.begin(); iter != discard.end(); iter++) {
        temp.push_back(*iter);
    }
    
    int size = temp.size();
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (temp[i] + temp[j] == sumNumber) {
                discard.erase(temp[i]);
                discard.erase(temp[j]);
                return true;
            }
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    
    sumNumber = cards.size() + 1;
    init(cards);
    
    int size = cards.size();
    
    int i;
    for (i = size / 3; i < size; i += 2) {
        answer++;
        int firstCard = cards[i];
        int secondCard = cards[i + 1];
        
        discard.insert(firstCard);
        discard.insert(secondCard);
        
        if (checkNonCoin()) {
            continue;
        }
        
        if (coin >= 1 && checkOneCoin()) {
            coin--;
            continue;
        }
        
        if (coin >= 2 && checkTwoCoin()) {
            coin -= 2;
            continue;
        }
        
        break;
    }
    
    if (i == size) {
        answer++;
    }
    
    return answer;
}