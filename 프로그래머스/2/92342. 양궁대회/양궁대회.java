import java.util.*;

class Solution {
    int[] apeech;
    static final int END = 11;
    
    int dist = -1;
    int[] result = null;
    
    public int[] solution(int n, int[] info) {
        apeech = info;
    
        int[] lion = new int[END];
        
        solve(lion, n, 0, 0);
    
        if (result == null) {
            int[] answer = {-1};
            return answer;
        }
        
        return result;
    }
    
    void solve(final int[] lion, final int max, final int cnt, final int start) {
        if (cnt == max) {
            if (isLionWin(lion)) {
                final int[] temp = copy(lion);
                final int currentDist = calculateDist(temp);
                
                if (result == null) {
                    dist = currentDist;
                    result = temp;
                    
                    return;
                }
                
                if (dist < currentDist) {
                    dist = currentDist;
                    result = temp;
                    
                    return;
                }
                
                if (dist == currentDist) {
                    result = compare(result, temp);
                }
            }
            
            return;
        }
        
        for (int i = start; i < END; i++) {
            if (lion[i] > apeech[i]) {
                continue;
            }
            
            lion[i]++;
            solve(lion, max, cnt + 1, i);
            lion[i]--;
        }
    }
    
    int[] copy(final int[] lion) {
        int[] result = new int[END];
        
        for (int i = 0; i < END; i++) {
            result[i] = lion[i];
        }
        
        return result;
    }
    
    int[] compare(final int[] left, final int[] right) {
        for (int i = END - 1; i >= 0; i--) {
            if (left[i] > right[i]) {
                return left;
            } else if (left[i] < right[i]) {
                return right;
            }
        }
            
        return left;
    }
    
    int calculateDist(final int[] lion) {
        int apeechScore = 0;
        int lionScore = 0;
        
        for (int i = 0; i < END; i++) {
            final int score = 10 - i;
            
            if (apeech[i] == 0 && lion[i] == 0) {
                continue;
            }
            
            if (apeech[i] < lion[i]) {
                lionScore += score;
            } else {
                apeechScore += score;
            }
        }
        
        return lionScore - apeechScore;
    }
    
    boolean isLionWin(final int[] lion) {
        int apeechScore = 0;
        int lionScore = 0;
        
        for (int i = 0; i < END; i++) {
            final int score = 10 - i;
            
            if (apeech[i] == 0 && lion[i] == 0) {
                continue;
            }
            
            if (apeech[i] < lion[i]) {
                lionScore += score;
            } else {
                apeechScore += score;
            }
        }
        
        if (lionScore > apeechScore) {
            return true;
        }
        
        return false;
    }
}