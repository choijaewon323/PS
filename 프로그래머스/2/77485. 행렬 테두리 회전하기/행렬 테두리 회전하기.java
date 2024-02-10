import java.util.*;
import java.io.*;

class Solution {
    
    static final int MAX = 100;
    
    static final int INF = 100000000;
    
    int[][] map = new int[MAX + 1][MAX + 1];
    int R;
    int C;
    
    public int[] solution(int rows, int columns, int[][] queries) {
        R = rows;
        C = columns;
        
        init();
        
        List<Integer> minimums = new ArrayList<>();
        
        for (final int[] query : queries) {
            final int min = findMin(query);
            
            minimums.add(min);
            roll(query);
        }
        
        final int[] answer = minimums.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
    
    void roll(final int[] query) {
        final int startY = query[0];
        final int startX = query[1];
        final int endY = query[2];
        final int endX = query[3];
        
        Deque<Integer> q = new ArrayDeque<>();
        
        for (int x = startX; x <= endX; x++) {
            q.add(map[startY][x]);
        }
        
        for (int y = startY + 1; y <= endY - 1; y++) {
            q.add(map[y][endX]);
        }
        
        for (int x = endX; x >= startX; x--) {
            q.add(map[endY][x]);
        }
        
        for (int y = endY - 1; y >= startY + 1; y--) {
            q.add(map[y][startX]);
        }
        
        final int temp = q.removeLast();
        q.addFirst(temp);
        
        for (int x = startX; x <= endX; x++) {
            map[startY][x] = q.poll();
        }
        
        for (int y = startY + 1; y <= endY - 1; y++) {
            map[y][endX] = q.poll();
        }
        
        for (int x = endX; x >= startX; x--) {
            map[endY][x] = q.poll();
        }
        
        for (int y = endY - 1; y >= startY + 1; y--) {
            map[y][startX] = q.poll();
        }
    }
    
    int findMin(final int[] query) {
        final int startY = query[0];
        final int startX = query[1];
        final int endY = query[2];
        final int endX = query[3];
        
        int result = INF;
        
        for (int x = startX; x <= endX; x++) {
            result = Math.min(result, map[startY][x]);
        }
        
        for (int y = startY + 1; y <= endY - 1; y++) {
            result = Math.min(result, map[y][endX]);
        }
        
        for (int x = endX; x >= startX; x--) {
            result = Math.min(result, map[endY][x]);
        }
        
        for (int y = endY - 1; y >= startY + 1; y--) {
            result = Math.min(result, map[y][startX]);
        }
        
        return result;
    }
    
    void init() {
        int num = 1;
        
        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                map[y][x] = num;
                num++;
            }
        }
    }
}