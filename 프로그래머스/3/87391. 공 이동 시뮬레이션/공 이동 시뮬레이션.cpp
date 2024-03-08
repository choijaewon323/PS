#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3

LL N, M;

LL solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    N = n;
    M = m;
    reverse(queries.begin(), queries.end());
    
    LL startY = x, startX = y, endY = x, endX = y;
    
    for (vector<int>& query : queries) {
        int command = query[0];
        int dx = query[1];
        
        switch (command) {
            case RIGHT:
                if (startX != 0) {
                    startX += dx;
                }
                
                endX += dx;
                if (endX > M - 1) {
                    endX = M - 1;
                }
                break;
            case LEFT:
                startX -= dx;
                if (startX < 0) {
                    startX = 0;
                }
                if (endX != M - 1) {
                    endX -= dx;
                }
                break;
            case DOWN:
                if (startY != 0) {
                    startY += dx;
                }
                endY += dx;
                if (endY > N - 1) {
                    endY = N - 1;
                }
                break;
            case UP:
                startY -= dx;
                if (startY < 0) {
                    startY = 0;
                }
                if (endY != N - 1) {
                    endY -= dx;
                }
                break;
        }
        
        if (startY > N - 1 || endY < 0 || startX > M - 1 || endX < 0) {
            return 0;
        }
    }
    LL answer = (endY - startY + 1) * (endX - startX + 1);
    
    return answer;
    
    return answer;
}