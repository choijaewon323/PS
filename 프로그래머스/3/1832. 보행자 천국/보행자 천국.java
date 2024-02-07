import java.util.*;
import java.io.*;

class Solution {
    static final int MOD = 20170805;
    static final int RIGHT = 0;
    static final int DOWN = 1;
    
    int[][] map;
    int Y;
    int X;
    
    int[] dy = {0, 1};
    int[] dx = {1, 0};
    
    int[][][] dp = new int[500][500][2];
    
    public int solution(int m, int n, int[][] cityMap) {
        Y = m;
        X = n;
        map = cityMap;
        
        init();
        
        final int answer = solve(0, 0, 0);
        
        return answer;
    }
    
    void init() {
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                for (int i = 0; i < 2; i++) {
                    dp[y][x][i] = -1;
                }
            }
        }
    }
    
    int solve(final int y, final int x, final int direction) {
        if (y == Y - 1 && x == X - 1) {
            return 1;
        }
        
        if (dp[y][x][direction] != -1) {
            return dp[y][x][direction];
        }
        
        if (map[y][x] == 0) {
            int result = 0;
            
            for (int i = 0; i < 2; i++) {
                final int ny = y + dy[i];
                final int nx = x + dx[i];
                
                if (inRange(ny, nx)) {
                    result += solve(ny, nx, i);
                    result %= MOD;
                }
            }
            
            return dp[y][x][direction] = result;
        } else if (map[y][x] == 2) {
            int result = 0;
            
            final int ny = y + dy[direction];
            final int nx = x + dx[direction];
            
            if (inRange(ny, nx)) {
                result += solve(ny, nx, direction);
                result %= MOD;
            }
            
            return dp[y][x][direction] = result;
        } else {
            return dp[y][x][direction] = 0;
        }
    }
    
    boolean inRange(final int y, final int x) {
        if (0 <= y && y < Y && 0 <= x && x < X) {
            return true;
        }
        return false;
    }
}