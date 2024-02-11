import java.util.*;
import java.io.*;

class Solution {
    final Stack<Node> st = new Stack<Node>();
    
    public int solution(String s) {
        int answer = s.length();
        
        for (int cnt = 1; cnt <= s.length() - 1; cnt++) {
            answer = Math.min(answer, compress(s, cnt));
        }
        
        return answer;
    }
    
    int compress(final String s, final int cnt) {
        for (int i = 0; i < s.length(); i += cnt) {
            if (i + cnt - 1 < s.length()) {
                final String substr = subString(s, i, i + cnt - 1);
                
                operation(substr);
                continue;
            }
            
            final String substr = subString(s, i, s.length() - 1);
            
            st.add(new Node(substr, 1));
        }
        
        int result = 0;
        
        while (!st.isEmpty()) {
            final Node node = st.pop();
            
            if (node.count == 1) {
                result += node.substr.length();
            } else {
                result += node.substr.length();
                result += String.valueOf(node.count).length();
            }
        }
        
        return result;
    }
    
    void operation(final String substr) {
        if (st.isEmpty()) {
            st.add(new Node(substr, 1));
            
            return;
        }
        final Node node = st.peek();
                    
        if (node.substr.equals(substr)) {
            st.pop();
            st.add(new Node(node.substr, node.count + 1));
            
            return;
        }
        
        st.add(new Node(substr, 1));
    }
    
    String subString(final String s, final int start, final int end) {
        StringBuilder sb = new StringBuilder();
        
        for (int i = start; i <= end; i++) {
            final char c = s.charAt(i);
            
            sb.append(c);
        }
        
        return sb.toString();
    }
    
    static class Node {
        String substr;
        int count;
        
        Node (String substr, int count) {
            this.substr = substr;
            this.count = count;
        }
    }
}