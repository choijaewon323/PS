import java.util.*;

class Solution {
    Map<String, LinkedList<String>> edges = new HashMap<>();
    Map<String, Boolean> visited = new HashMap<>();
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        init(begin, words);
        
        answer = bfs(begin, target);
        
        return answer;
    }
    
    int bfs(String begin, String target) {
        Queue<Pair> queue = new LinkedList<>();
        
        visited.replace(begin, true);
        
        queue.add(new Pair(begin, 0));
        
        while (!queue.isEmpty()) {
            Pair present = queue.poll();
            String word = present.word;
            int count = present.count;
            
            if (word.equals(target)) {
                return count;
            }
            
            for (String edge : edges.get(word)) {
                if (!(visited.get(edge))) {
                    visited.replace(edge, true);
                    queue.add(new Pair(edge, count + 1));
                }
            }
        }
        
        return 0;
    }
    
    void init(final String begin, final String[] words) {
        visited.put(begin, false);
        edges.put(begin, new LinkedList<>());
        
        for (String word : words) {
            visited.put(word, false);
            edges.put(word, new LinkedList<>());
        }
        
        setEdge(begin, words);
    }
    
    void setEdge(final String begin, final String[] words) {
        for (String oppo : words) {
            if (oppo.equals(begin)) {
                continue;
            }
                
            if (isOneDifferent(begin, oppo)) {
                edges.get(begin).add(oppo);
            }
        }
        
        for (String word : words) {
            for (String oppo : words) {
                if (oppo.equals(word)) {
                    continue;
                }
                
                if (isOneDifferent(word, oppo)) {
                    edges.get(word).add(oppo);
                    edges.get(oppo).add(word);
                }
            }
        }
    }
    
    boolean isOneDifferent(String word, String oppo) {
        int count = 0;
        
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) != oppo.charAt(i)) {
                count++;
            }
        }
        
        if (count > 1) {
            return false;
        }
        
        return true;
    }
    
    static class Pair {
        final String word;
        final int count;
        
        Pair(String word, int count) {
            this.word = word;
            this.count = count;
        }
    }
}