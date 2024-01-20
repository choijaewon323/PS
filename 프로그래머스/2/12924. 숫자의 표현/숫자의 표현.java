import java.util.*;

class Solution {
    int[] numbers;
    
    public int solution(int n) {
        int answer = 0;
        
        numbers = new int[n];
        
        for (int i = 0; i < n; i++) {
            numbers[i] = i + 1;
        }
        
        answer = solve(n);
        
        return answer;
    }
    
    int solve(final int number) {
        int result = 0;
        int left = 0;
        int right = 0;
        int accumulator = numbers[left];
        
        while (left <= right && inRange(right)) {
            if (left == right) {
                if (number == accumulator) {
                    result++;
                }
                
                right++;
                if (inRange(right)) {
                    accumulator += numbers[right];
                }
            }
            else {
                if (number == accumulator) {
                    result++;
                    
                    right++;
                    if (inRange(right)) {
                        accumulator += numbers[right];
                    }
                }
                else if (number > accumulator) {
                    right++;
                    if (inRange(right)) {
                        accumulator += numbers[right];
                    }
                }
                else {
                    accumulator -= numbers[left];
                    left++;
                }
            }
        }
        
        return result;
    }
    
    boolean inRange(final int index) {
        if (0 <= index && index < numbers.length) {
            return true;
        }
        
        return false;
    }
}