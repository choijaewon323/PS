import java.io.*;
import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        StringTokenizer st = new StringTokenizer(s, " ");
        
        ArrayList<Integer> arr = new ArrayList<>();
        
        while (st.hasMoreTokens()) {
            String temp = st.nextToken();
            
            arr.add(Integer.valueOf(temp));
        }
        
        Collections.sort(arr);
        
        StringBuilder sb = new StringBuilder();
        sb.append(arr.get(0));
        sb.append(" ");
        sb.append(arr.get(arr.size() - 1));
        
        answer = sb.toString();
        
        return answer;
    }
}