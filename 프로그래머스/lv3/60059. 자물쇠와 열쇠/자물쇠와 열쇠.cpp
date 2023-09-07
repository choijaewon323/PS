#include <string>
#include <vector>

using namespace std;

int hole;
int N, M;

bool inRange(int y, int x) {
    if (0 <= y && y < M && 0 <= x && x < M) {
        return true;
    }
    return false;
}

vector<vector<int>> roll(vector<vector<int>>& key) {
    
    vector<vector<int>> result;
    
    for (int x = M - 1; x >= 0; x--) {
        vector<int> temp;
        for (int y = 0; y < M; y++) {
            temp.push_back(key[y][x]);
        }
        
        result.push_back(temp);
    }
    
    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    M = key.size();
    N = lock.size();
    
    int hole = 0;
    int keyEdge = 0;
    
    for (vector<int>& k : key) {
        for (int t : k) {
            if (t == 1) {
                keyEdge++;
            }
        }
    }
    
    for (vector<int>& l : lock) {
        for (int t : l) {
            if (t == 0) {
                hole++;
            }
        }
    }
    
    if (keyEdge == 0 && hole == 0) {
        return true;
    }
    
    if (keyEdge != 0 && hole == 0) {
        return true;
    }
    
    if (keyEdge == 0 && hole != 0) {
        return false;
    }
    
    for (int dy = -N; dy <= N; dy++) {
        for (int dx = -N; dx <= N; dx++) {
            int temp = 0;
            bool flag = true;
            
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (inRange(y + dy, x + dx)) {
                        if (key[y + dy][x + dx] == 1 && lock[y][x] == 0) {
                            temp++;
                        }
                        if (key[y + dy][x + dx] == 1 && lock[y][x] == 1) {
                            flag = false;
                        }
                    }
                }
            }
            
            if (temp == hole) {
                if (flag) {
                    return true;
                }
            }
        }
    }
    
    key = roll(key);
    for (int dy = -N; dy <= N; dy++) {
        for (int dx = -N; dx <= N; dx++) {
            int temp = 0;
            bool flag = true;
            
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (inRange(y + dy, x + dx)) {
                        if (key[y + dy][x + dx] == 1 && lock[y][x] == 0) {
                            temp++;
                        }
                        if (key[y + dy][x + dx] == 1 && lock[y][x] == 1) {
                            flag = false;
                        }
                    }
                }
            }
            
            if (temp == hole) {
                if (flag) {
                    return true;
                }
            }
        }
    }
    
    key = roll(key);
    for (int dy = -N; dy <= N; dy++) {
        for (int dx = -N; dx <= N; dx++) {
            int temp = 0;
            bool flag = true;
            
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (inRange(y + dy, x + dx)) {
                        if (key[y + dy][x + dx] == 1 && lock[y][x] == 0) {
                            temp++;
                        }
                        if (key[y + dy][x + dx] == 1 && lock[y][x] == 1) {
                            flag = false;
                        }
                    }
                }
            }
            
            if (temp == hole) {
                if (flag) {
                    return true;
                }
            }
        }
    }
    
    key = roll(key);
    for (int dy = -N; dy <= N; dy++) {
        for (int dx = -N; dx <= N; dx++) {
            int temp = 0;
            bool flag = true;
            
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (inRange(y + dy, x + dx)) {
                        if (key[y + dy][x + dx] == 1 && lock[y][x] == 0) {
                            temp++;
                        }
                        if (key[y + dy][x + dx] == 1 && lock[y][x] == 1) {
                            flag = false;
                        }
                    }
                }
            }
            
            if (temp == hole) {
                if (flag) {
                    return true;
                }
            }
        }
    }
    
    return answer;
}