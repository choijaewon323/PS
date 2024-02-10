import java.util.*;
import java.io.*;

class Solution {
    
    char[][] map = new char[5][5];
    List<Pair> starts;
    
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};
    
    public int[] solution(String[][] places) {
        
        List<Integer> validates = new ArrayList<>();
        for (final String[] waitingRoom : places) {
            
            starts = new ArrayList<>();
            
            for (int y = 0; y < waitingRoom.length; y++) {
                final String row = waitingRoom[y];
                
                for (int x = 0; x < row.length(); x++) {
                    final char c = row.charAt(x);
                    
                    map[y][x] = c;
                    
                    if (c == 'P') {
                        starts.add(new Pair(y, x));
                    }
                }
            }
            
            if (validate()) {
                validates.add(1);
            } else {
                validates.add(0);
            }
        }
        
        final int[] answer = validates.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
    
    boolean validate() {
        for (final Pair start : starts) {
            if (!bfs(start)) {
                return false;
            }
        }
        
        return true;
    }
    
    boolean bfs(final Pair start) {
        Queue<Pair> q = new LinkedList<>();
        int[][] dist = new int[5][5];
        
        dist[start.y][start.x] = 1;
        q.add(start);
        
        while (!q.isEmpty()) {
            final Pair present = q.poll();
            
            if (map[present.y][present.x] == 'P' && dist[present.y][present.x] != 1) {
                return false;
            }
            
            if (dist[present.y][present.x] == 3) {
                continue;
            }
            
            for (int i = 0; i < 4; i++) {
                final int ny = present.y + dy[i];
                final int nx = present.x + dx[i];
                
                if (inRange(ny, nx) && map[ny][nx] != 'X' && dist[ny][nx] == 0) {
                    dist[ny][nx] = dist[present.y][present.x] + 1;
                    q.add(new Pair(ny, nx));
                }
            }
        }
        
        return true;
    }
    
    boolean inRange(final int y, final int x) {
        if (0 <= y && y < 5 && 0 <= x && x < 5) {
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