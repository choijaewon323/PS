import java.util.*;

class Solution {
    
    Map<Integer, Integer> numbers = new HashMap<>();
    int begin;
    int end;
    
    public int[] solution(long b, long e) {
        Long wrapBegin = b;
        Long wrapEnd = e;
        
        begin = wrapBegin.intValue();
        end = wrapEnd.intValue();
        
        for (int i = begin; i <= end; i++) {
            numbers.put(i, 0);
        }
        
        for (int num = 10000000; num >= 1; num--) {
            if (num * 2 < begin) {
                final int start = findFirst(num);
                
                calculate(start, num);
            } else if (inRange(num * 2)) {
                calculate(num * 2, num);
            }
        }
        
        final int[] answer = makeAnswer();
        
        return answer;
    }
    
    int[] makeAnswer() {
        List<Integer> results = new ArrayList<>();
        
        for (int i = begin; i <= end; i++) {
            final int number = numbers.get(i);
            
            results.add(number);
        }
        
        return results.stream().mapToInt(Integer::intValue).toArray();
    }
    
    int findFirst(final int addition) {
        final int temp = begin / addition;
        
        final int result = addition * temp;
        
        if (inRange(result)) {
            return result;
        }
        
        return result + addition;
    }
    
    void calculate(final int num, final int addition) {
        for (int i = num; i <= end; i += addition) {
            if (numbers.get(i).equals(0)) {
                numbers.put(i, addition);
            }
        }
    }
    
    boolean inRange(final int num) {
        if (begin <= num && num <= end) {
            return true;
        }
        return false;
    }
}