#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isAlpha(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        return true;
    }
    return false;
}

char toLower(char c) {
    if ('A' <= c && c <= 'Z') {
        c += ('a' - 'A');
    }
    return c;
}

int solution(string str1, string str2) {
    int answer = 0;

    // 문자열 쪼개기
    vector<string> a;
    map<string, int> cntA;
    for (int i = 0; i < str1.size() - 1; i++) {
        if (isAlpha(str1[i]) && isAlpha(str1[i + 1])) {
            string temp = "";
            temp += toLower(str1[i]);
            temp += toLower(str1[i + 1]);

            if (cntA[temp] == 0) {
                a.push_back(temp);   
            }
            cntA[temp]++;
        }
    }
    
    vector<string> b;
    map<string, int> cntB;
    for (int i = 0; i < str2.size() - 1; i++) {
        if (isAlpha(str2[i]) && isAlpha(str2[i + 1])) {
            string temp = "";
            temp += toLower(str2[i]);
            temp += toLower(str2[i + 1]);

            if (cntB[temp] == 0) {
                b.push_back(temp);   
            }
            cntB[temp]++;
        }
    }
    
    if (a.empty() && b.empty()) {
        return 65536;
    }
    
    if (a.empty() || b.empty()) {
        return 0;
    }
    
    map<string, bool> visited;
    int inter = 0;
    for (string& tempA : a) {
        bool flag = true;
        for (string& tempB : b) {
            if (tempA == tempB) {
                inter += min(cntA[tempA], cntB[tempA]);
                visited[tempA] = true;
                flag = false;
                break;
            }
        }
        if (flag) {
            visited[tempA] = true;
        }
    }
    for (string& tempB : b) {
        if (!visited[tempB]) {
            bool flag = true;
            for (string& tempA : a) {
                if (tempA == tempB) {
                    inter += min(cntA[tempA], cntB[tempA]);
                    visited[tempA] = true;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                visited[tempB] = true;
            }
        }
    }
    
    visited.clear();
    int uni = 0;
    for (string& tempA : a) {
        bool flag = true;
        for (string& tempB : b) {
            if (tempA == tempB) {
                uni += max(cntA[tempA], cntB[tempA]);
                visited[tempA] = true;
                flag = false;
                break;
            }
        }
        if (flag) {
            uni += cntA[tempA];
            visited[tempA] = true;
        }
    }
    for (string& tempB : b) {
        if (!visited[tempB]) {
            bool flag = true;
            for (string& tempA : a) {
                if (tempA == tempB) {
                    uni += max(cntA[tempA], cntB[tempA]);
                    visited[tempA] = true;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                uni += cntB[tempB];
                visited[tempB] = true;
            }
        }
    }
    
    double sim = (double)inter / uni;
    sim *= 65536;
    answer = (int)sim;
    
    return answer;
}