#include <string>
#include <vector>

using namespace std;

long long factorial[21];

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    // base case
    if (n == 1) {
        answer.push_back(1);
        
        return answer;
    }
    
    factorial[0] = 0;
    
    long long tempFac = 1;
    for (int i = 1; i <= 20; i++) {
        tempFac *= i;
        factorial[i] = tempFac;
    }
    
    k--;
    
    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        temp.push_back(i);
    }
    
    while (temp.size() > 1) {
        int size = temp.size();
        
        int index = k / factorial[size - 1];
        
        answer.push_back(temp[index]);
        temp.erase(temp.begin() + index);
        
        k %= factorial[size - 1];
    }
    
    answer.push_back(temp[0]);
    
    return answer;
}