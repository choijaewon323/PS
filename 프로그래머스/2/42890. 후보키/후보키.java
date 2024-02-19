import java.util.*;
import java.io.*;

class Solution {
    Set<String> candidate = new HashSet<>();
    String[][] table;
    int columnSize;
    int rowSize;
    
    public int solution(String[][] relation) {
        table = relation;
        rowSize = relation.length;
        columnSize = relation[0].length;
        
        for (int count = 1; count <= columnSize; count++) {
            makeKey(new ArrayList<>(), count, -1);
        }
        
        final int answer = candidate.size();
        
        return answer;
    }
    
    void makeKey(List<Integer> subset, final int maxSize, final int prev) {
        if (subset.size() == 0) {
            for (int i = 0; i < columnSize; i++) {
                subset.add(i);
                makeKey(subset, maxSize, i);
                subset.remove(subset.size() - 1);
            }
            
            return;
        }
        
        if (subset.size() == maxSize) {
            if (checkUnique(subset) && checkMinimum(subset)) {
                candidate.add(converter(subset));
            }
            
            return;
        }

        for (int i = prev + 1; i < columnSize; i++) {
            subset.add(i);
            makeKey(subset, maxSize, i);
            subset.remove(subset.size() - 1);
        }
    }
    
    String converter(List<Integer> subset) {
        StringBuilder sb = new StringBuilder();
        
        for (final int sub : subset) {
            sb.append(sub);
        }
        
        return sb.toString();
    }
    
    String[][] makeTuple(List<Integer> subset) {
        String[][] results = new String[rowSize][subset.size()];
        
        for (int r = 0; r < rowSize; r++) {
            for (int c = 0; c < subset.size(); c++) {
                final int index = subset.get(c);
                results[r][c] = table[r][index];
            }
        }
        
        return results;
    }
    
    boolean checkUnique(List<Integer> subset) {
        final String[][] tuple = makeTuple(subset);
        
        for (int i = 0; i < rowSize; i++) {
            final String[] present = tuple[i];
            
            for (int j = 0; j < rowSize; j++) {
                if (i == j) {
                    continue;
                }
                
                final String[] oppo = tuple[j];
                
                boolean flag = true;
                for (int c = 0; c < tuple[i].length; c++) {
                    if (!present[c].equals(oppo[c])) {
                        flag = false;
                    }
                    
                    if (!flag) {
                        break;
                    }
                }
                
                if (flag) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    boolean isContains(final char c, List<Integer> subset) {
        for (final int sub : subset) {
            if (sub == c - '0') {
                return true;
            }
        }
        return false;
    }
    
    boolean checkMinimum(List<Integer> subset) {
        for (final String cand : candidate) {
            boolean flag = true;
            
            for (int i = 0; i < cand.length(); i++) {
                final char c = cand.charAt(i);
                
                if (!isContains(c, subset)) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                return false;
            }
        }
        
        return true;
    }
}