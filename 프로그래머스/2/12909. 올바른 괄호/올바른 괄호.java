import java.util.*;

class Solution {
    Stack<Character> st = new Stack<>();
    
    boolean solution(String s) {
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (st.isEmpty()) {
                if (c == '(') {
                    st.push(c);
                }
                else {
                    return false;
                }
            }
            else {
                if (c == '(') {
                    st.push(c);
                }
                else {
                    if (st.peek() == '(') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        
        if (!st.isEmpty()) {
            return false;
        }
        
        return true;
    }
    
    boolean solve(String s) {
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (st.isEmpty()) {
                if (c == '(') {
                    st.push(c);
                }
                else {
                    return false;
                }
            }
            else {
                if (c == '(') {
                    st.push(c);
                }
                else {
                    if (st.peek() == '(') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        
        if (!st.isEmpty()) {
            return false;
        }
        
        return true;
    }
}