#include <string>
#include <vector>
#include <map>

using namespace std;

#define MAX 10000

map<string, int> peopleIndex;

int parent[MAX];
vector<int> sellCnt[MAX];
vector<int> answer;

void solve(int people, int cost) {
    if (people == -1) {
        return;
    }
    
    int reminder = cost / 10;
    int me = cost - reminder;
    answer[people] += me;
    solve(parent[people], reminder);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    answer = vector<int>(enroll.size(), 0);
    
    for (int i = 0; i < enroll.size(); i++) {
        string& en = enroll[i];
        
        peopleIndex[en] = i;
        
        string& ref = referral[i];
        
        if (ref == "-") {
            parent[i] = -1;
        }
        else {
            int par = peopleIndex[ref];
            parent[i] = par;
        }
    }
    
    for (int i = 0; i < seller.size(); i++) {
        string& sel = seller[i];
        int am = amount[i];
        
        int people = peopleIndex[sel];
        sellCnt[people].push_back(am);
    }
    
    for (int i = 0; i < enroll.size(); i++) {
        string& en = enroll[i];
        
        int people = peopleIndex[en];
        
        if (sellCnt[people].empty()) {
            continue;
        }
        
        for (int sell : sellCnt[people]) {
            solve(people, sell * 100);
        }
    }
    
    return answer;
}