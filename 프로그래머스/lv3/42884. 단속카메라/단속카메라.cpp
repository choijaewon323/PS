#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    int cam = -30001;
    
    sort(routes.begin(), routes.end(), compare);
    
    for (int i = 0; i < routes.size(); i++) {
        if (routes[i][0] > cam)  {
            cam = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}