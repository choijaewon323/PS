#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define MIN -10000000
#define MAXNUM 101
#define MAX 10000000

int dp[MAXNUM][MAXNUM][2];

vector<int> number;
vector<char> oper;

// prev 0 : 작아야함 prev 1 : 커야함
int func(int start, int end, int prev) {
    if (start == end) {
        return number[start];
    }
    
    if (dp[start][end][prev] != MIN) {
        return dp[start][end][prev];
    }
    
    int result;
    if (prev == 1) {
        result = MIN;
    }
    else {
        result = MAX;
    }
    
    for (int k = start; k <= end - 1; k++) {
        int temp;
        if (oper[k] == '+') {
            if (prev == 1) {
                temp = func(start, k, 1) + func(k + 1, end, 1);
            }
            else {
                temp = func(start, k, 0) + func(k + 1, end, 0);   
            }
        }
        else {
            if (prev == 1) {
                temp = func(start, k, 1) - func(k + 1, end, 0);    
            }
            else {
                temp = func(start, k, 0) - func(k + 1, end, 1);
            }
        }
        
        if (prev == 1) {
            result = max(result, temp);
        }
        else {
            result = min(result, temp);
        }
    }
    
    return dp[start][end][prev] = result;
}

int solution(vector<string> arr) {
    int answer = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            number.push_back(stoi(arr[i]));
        }
        else {
            oper.push_back(arr[i][0]);
        }
    }
    
    for (int y = 0; y < MAXNUM; y++) {
        for (int x = 0; x < MAXNUM; x++) {
            for (int i = 0; i < 2; i++) {
                dp[y][x][i] = MIN;
            }
        }
    }
    
    answer = func(0, number.size() - 1, 1);

    return answer;
}