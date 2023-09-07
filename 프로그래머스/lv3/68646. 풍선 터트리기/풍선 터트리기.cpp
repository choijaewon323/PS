#include <string>
#include <vector>
#include <stack>

using namespace std;

#define MAX 1000000

int cnt[MAX];

int solution(vector<int> a) {
    int answer = 0;
    
    // base case
    if (a.size() == 1 || a.size() == 2) {
        return a.size();
    }
    
    stack<int> st;
    
    for (int i = 0; i < a.size(); i++) {
        int present = a[i];
        
        while (!st.empty() && a[st.top()] > present) {
            cnt[st.top()]++;
            st.pop();
        }
        
        if (!st.empty()) {
            cnt[i]++;
        }
        st.push(i);
    }
    
    for (int i = 0; i < a.size(); i++) {
        if (cnt[i] < 2) {
            answer++;
        }
    }
    
    return answer;
}