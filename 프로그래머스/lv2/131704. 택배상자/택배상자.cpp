#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    int orderIndex = 0;
    stack<int> st;
    
    for (int box = 1; box <= order.size(); box++) {
        if (box == order[orderIndex]) {
            answer++;
            orderIndex++;
        }
        else if (!st.empty() && st.top() == order[orderIndex]) {
            box--;
            answer++;
            st.pop();
            orderIndex++;
        }
        else {
            st.push(box);
        }
    }
    
    while (orderIndex < order.size()) {
        if (st.top() == order[orderIndex]) {
            answer++;
            orderIndex++;
            st.pop();
        }
        else {
            break;
        }
    }
    
    return answer;
}