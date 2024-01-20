import java.util.*;

class Solution {
    boolean[] visited;
    int size;
    int[][] edges;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        size = n;
        edges = computers;
        
        visited = new boolean[size];
        
        Arrays.fill(visited, false);
        
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                answer++;
                dfs(i);
            }
        }
        
        return answer;
    }
    
    void dfs(final int start) {
        visited[start] = true;
        
        for (int next = 0; next < size; next++) {
            if (next == start) {
                continue;
            }
            
            if (!visited[next] && edges[start][next] == 1) {
                dfs(next);
            }
        }
    }
}