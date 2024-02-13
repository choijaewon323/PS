/*
    0 0 0
    0 0 0
    0 0 0
    0 0 0
*/

class Solution {
    public long solution(int w, int h) {
        long answer = 0;
        
        for (long x = 1; x <= w; x++) {
            final long temp = h * x;
            
            long y = temp / w;
            
            if (temp % w != 0) {
                y++;
            }
            
            final long prev = h * (x - 1);
            final long prevY = prev / w;
            
            answer += y - prevY;
        }
        
        final long result = (long)w * h - answer;
        
        return result;
    }
}