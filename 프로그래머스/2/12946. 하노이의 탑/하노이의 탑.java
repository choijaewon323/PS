import java.util.*;

class Solution {
    List<Node> results = new ArrayList<>();
    
    public int[][] solution(int n) {
        hanoi(n, 1, 2, 3);
        
        final int[][] answer = new int[results.size()][2];
        
        for (int i = 0; i < results.size(); i++) {
            final Node present = results.get(i);
            
            answer[i][0] = present.from;
            answer[i][1] = present.to;
        }
        
        return answer;
    }
    
    void hanoi(final int n, final int from, final int by, final int to) {
        if (n == 0) {
            return;
        }
        
        hanoi(n - 1, from, to, by);
        move(from, to);
        hanoi(n - 1, by, from, to);
    }
    
    void move(final int from, final int to) {
        results.add(new Node(from, to));
    }
    
    static class Node {
        int from;
        int to;
        
        Node(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }
}