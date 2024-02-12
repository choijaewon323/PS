class Solution {
    
    int N;
    int[][] board;
    
    int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
    int[] dx = {0, -1, -1, -1, 0, 1, 1, 1};
    
    public int solution(int n) {
        N = n;
        board = new int[n][n];
        
        final int answer = solve(0, 0);
        
        return answer;
    }
    
    int solve(final int y, final int cnt) {
        if (y == N) {
            return 1;
        }
        
        int result = 0;
        for (int x = 0; x < N; x++) {
            if (board[y][x] == 0) {
                set(y, x, 1);
                result += solve(y + 1, cnt + 1);
                set(y, x, -1);
            }
        }
        
        return result;
    }
    
    void set(final int y, final int x, final int to) {
        board[y][x] += to;
        
        for (int i = 0; i < 8; i++) {
            Pair present = new Pair(y, x);
            
            while (true) {
                final int distY = dy[i];
                final int distX = dx[i];
                
                Pair next = nextPos(present.y, present.x, distY, distX);
                
                if (next.y == -1) {
                    break;
                }
                
                board[next.y][next.x] += to;
                present = next;
            }
        }
    }
    
    Pair nextPos(final int y, final int x, final int distY, final int distX) {
        final int ny = y + distY;
        final int nx = x + distX;
        
        if (inRange(ny, nx)) {
            return new Pair(ny, nx);
        }
        return new Pair(-1, -1);
    }
    
    boolean inRange(final int y, final int x) {
        if (0 <= y && y < N && 0 <= x && x < N) {
            return true;
        }
        return false;
    }
    
    static class Pair {
        int y;
        int x;
        
        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}