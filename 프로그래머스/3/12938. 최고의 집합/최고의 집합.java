import java.util.*;

class Solution {
    public int[] solution(int n, int s) {
        int[] answer = new int[n];
        
        if (s < n) {
            int[] result = {-1};
            return result;
        }
        
        Arrays.fill(answer, s / n);
        
        for (int i = 0; i < s % n; i++) {
            answer[i]++;
        }
        
        Arrays.sort(answer);
        
        return answer;
    }
}