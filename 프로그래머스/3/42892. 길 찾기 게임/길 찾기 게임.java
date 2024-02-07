import java.util.*;
import java.io.*;

/*
    x좌표 증가순으로 정렬 시 중위 순회 결과를 얻을 수 있다.
    
    중위 : 왼-루-오
    
    전위 : 루-왼-오
    
    후위 : 왼-오-루
    
    6 9 4 1 5 8 /7/ 2 3
    
    6 9 /4/ 1 5 8
    0 1
    
    rootIndex = 0
    
    
*/

class Solution {
    
    Node[] inorder;
    List<Integer> preorder = new ArrayList<>();
    List<Integer> postorder = new ArrayList<>();
    
    public int[][] solution(int[][] nodeinfo) {
        init(nodeinfo);
        
        // test
        // printInorder();
        
        pre(0, inorder.length - 1);
        post(0, inorder.length - 1);
        
        int[][] answer = new int[2][];
        
        answer[0] = preorder.stream().mapToInt(Integer::intValue).toArray();
        answer[1] = postorder.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
    
    void pre(final int start, final int end) {
        if (start > end) {
            return;
        }
        
        final int rootIndex = findRootIndex(start, end);
        
        final int root = inorder[rootIndex].num;
        
        preorder.add(root);
        pre(start, rootIndex - 1);
        pre(rootIndex + 1, end);
    }
    
    void post(final int start, final int end) {
        if (start > end) {
            return;
        }
        
        final int rootIndex = findRootIndex(start, end);
        
        final int root = inorder[rootIndex].num;
        
        post(start, rootIndex - 1);
        post(rootIndex + 1, end);
        postorder.add(root);
    }
    
    int findRootIndex(final int start, final int end) {
        
        int highY = -1;
        int result = -1;
        
        for (int i = start; i <= end; i++) {
            final int num = inorder[i].num;
            final int y = inorder[i].y;
            final int x = inorder[i].x;
            
            if (highY < y) {
                highY = y;
                result = i;
            }
        }
        
        return result;
    }

    void init(final int[][] nodeinfo) {
        List<Node> temp = new ArrayList<>();
        
        for (int i = 0; i < nodeinfo.length; i++) {
            final int num = i + 1;
            final int y = nodeinfo[i][1];
            final int x = nodeinfo[i][0];
            
            temp.add(new Node(num, y, x));
        }
        
        Collections.sort(temp, (e1, e2) -> {
            if (e1.x < e2.x) {
                return -1;
            }
            return 1;
        });
    
        inorder = new Node[temp.size()];
        
        for (int i = 0; i < temp.size(); i++) {
            inorder[i] = temp.get(i);
        }
    }
    
    static class Node {
        int num;
        int y;
        int x;
        
        Node(int num, int y, int x) {
            this.num = num;
            this.y = y;
            this.x = x;
        }
    }   
}