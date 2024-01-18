import java.util.*;

class Solution {
    int cnt = 0;
    int convertCnt = 0;
    
    public int[] solution(String s) {
        StringBuilder sb = new StringBuilder(s);
        
        while (sb.length() != 1) {
            convertCnt++;
            StringBuilder temp = new StringBuilder();
            
            for (int i = 0; i < sb.length(); i++) {
                if (sb.charAt(i) == '1') {
                    temp.append('1');
                }
            }
            
            cnt += (sb.length() - temp.length());
            
            sb = new StringBuilder(Integer.toBinaryString(temp.length()));
        }
        
        int[] answer = new int[2];
        answer[0] = convertCnt;
        answer[1] = cnt;
        
        return answer;
    }
}