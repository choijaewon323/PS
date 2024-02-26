import java.util.*;
import java.io.*;

/*
    1. 현재 노드에서 양인지 늑대인지 파악
    2. 왼쪽 및 오른쪽 노드에서 양과 늑대의 개수를 가져옴
    3. 
*/

class Solution {
    
    int[] animal;
    List<Integer>[] edges = new List[18];
    boolean[][][] visited = new boolean[18][18][18];
    
    int answer = 0;
        
    public int solution(int[] info, int[][] ed) {
        
        for (int i = 0; i < 18; i++) {
            edges[i] = new ArrayList<>();
        }
        
        animal = info;
        
        for (final int[] edge : ed) {
            final int parent = edge[0];
            final int child = edge[1];
            
            edges[parent].add(child);
            edges[child].add(parent);
        }
        
        animal[0] = -1;
        visited[0][1][0] = true;
        dfs(0, 1, 0);
        
        return answer;
    }
    
    void dfs(int index, int sheep, int wolf) {
        answer = Math.max(answer, sheep);
        
        for (int i = 0; i < edges[index].size(); i++) {
            int next = edges[index].get(i);
            
            if (animal[next] == 0) {
                if (!visited[next][sheep + 1][wolf]) {
                    visited[next][sheep + 1][wolf] = true;
                    animal[next] = -1;
                    dfs(next, sheep + 1, wolf);
                    animal[next] = 0;
                    visited[next][sheep + 1][wolf] = false;   
                }
                
            } else if (animal[next] == 1) {
                if (sheep > wolf + 1 && !visited[next][sheep][wolf + 1]) {
                    visited[next][sheep][wolf + 1] = true;
                    animal[next] = -1;
                    dfs(next, sheep, wolf + 1);
                    animal[next] = 1;
                    visited[next][sheep][wolf + 1] = false;   
                }
                
            } else {
                if (!visited[next][sheep][wolf]) {
                    visited[next][sheep][wolf] = true;
                    dfs(next, sheep, wolf);
                    visited[next][sheep][wolf] = false;
                }
            }
            
        }
        
    }
    
}