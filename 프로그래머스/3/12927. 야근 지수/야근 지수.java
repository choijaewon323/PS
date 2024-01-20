import java.util.*;

class Solution {
    static int END;
    
    public long solution(int n, int[] works) {
        long answer = 0;
        
        if (checkBaseCase(n, works)) {
            return 0;
        }

        END = works.length;
        Arrays.sort(works);
        
        int[] results = solve(works, n);
        
        answer = findAnswer(results);
        
        return answer;
    }
    
    long findAnswer(final int[] results) {
        long result = 0L;
        
        for (int temp : results) {
            result += (long)(temp * temp);
        }
        
        return result;
    }
    
    int[] solve(final int[] works, final int n) {
        int rest = n;
        int[] results = works.clone();
        
        int maxValue = works[END - 1];
        
        while (true) {
            if (rest == 0) {
                break;
            }
            
            int index = lowerBoundIndex(results, maxValue);
            maxValue--;
            
            if (index != END) {
                for (int i = index; i < END; i++) {
                    if (rest > 0) {
                        rest--;
                        results[i]--;
                    }
                }
            }
        }
        
        return results;
    }
    
    int lowerBoundIndex(final int[] works, final int number) {
        int left = 0;
        int right = works.length - 1;
        int result = works.length;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (works[mid] >= number) {
                result = mid;
                
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    int sumAll(final int[] works) {
        int result = 0;
        
        for (int work : works) {
            result += work;
        }
        
        return result;
    }
    
    boolean checkBaseCase(final int n, final int[] works) {
        int result = sumAll(works);
        
        if (result <= n) {
            return true;
        }
        return false;
    }
}