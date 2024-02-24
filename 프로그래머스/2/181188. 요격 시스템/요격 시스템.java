import java.util.*;

class Solution {
    List<Node> nodes = new ArrayList<>();
    
    public int solution(int[][] targets) {
        int answer = 0;
        
        for (final int[] target : targets) {
            final int start = target[0];
            final int end = target[1];
            
            nodes.add(new Node(start, end));
        }
        
        Collections.sort(nodes, (o1, o2) -> {
            if (o1.end <= o2.end) {
                return -1;
            }
            return 1;
        });
        
        int start = 0;
        int end = 0;
        
        for (final Node node : nodes) {
            if (node.start >= end) {
                answer++;
                end = node.end;
            }
        }
        
        return answer;
    }
    
    static class Node {
        int start;
        int end;
        
        Node(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}