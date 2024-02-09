import java.util.*;
import java.io.*;

/*
    기둥 요구사항
    - 바닥 위
    - 보의 한쪽 끝 부분 위
    - 다른 기둥 위
    
    보 요구사항
    - 한쪽 끝 부분이 기둥 위
    - 양쪽 끝 부분이 다른 보와 동시 연결
*/

class Solution {
    
    static final int COLUMN = 0;
    static final int ROW = 1;
    static final int NONE = -1;
    static final int MAX = 103;
    
    boolean[][] columnWall;
    boolean[][] rowWall;
    int N;
    
    public int[][] solution(int n, int[][] build_frame) {
        N = n + 1;
        columnWall = new boolean[MAX][MAX];
        rowWall = new boolean[MAX][MAX];
        
        for (final int[] frame : build_frame) {
            final int b = frame[3];
            
            if (b == 0) {
                remove(frame);
            } else {
                make(frame);
            }
        }
        
        List<Node> nodes = makeNodes();
        
        Collections.sort(nodes, (e1, e2) -> {
            if (e1.x < e2.x) {
                return -1;
            } else if (e1.x == e2.x) {
                if (e1.y < e2.y) {
                    return -1;
                } else if (e1.y == e2.y) {
                    if (e1.a < e2.a) {
                        return -1;
                    }
                    return 1;
                }
                
                return 1;
            }
            
            return 1;
        });
        
        final int[][] answer = makeAnswer(nodes);
        
        return answer;
    }
    
    int[][] makeAnswer(final List<Node> nodes) {
        int[][] results = new int[nodes.size()][3];
        
        for (int i = 0; i < nodes.size(); i++) {
            final Node present = nodes.get(i);
            
            results[i][0] = present.x;
            results[i][1] = present.y;
            results[i][2] = present.a;
        }
        
        return results;
    }
    
    List<Node> makeNodes() {
        List<Node> results = new ArrayList<>();
        
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (columnWall[y][x]) {
                    results.add(new Node(y, x, COLUMN));
                }
                if (rowWall[y][x]) {
                    results.add(new Node(y, x, ROW));
                }
            }
        }
        
        return results;
    }
    
    void make(final int[] frame) {
        final int a = frame[2];
        
        if (a == COLUMN) {
            makeColumn(frame);
            
            return;
        }
        
        makeRow(frame);
    }
    
    void remove(final int[] frame) {
        final int a = frame[2];
        
        if (a == COLUMN) {
            removeColumn(frame);
            
            return;
        }
        
        removeRow(frame);    
    }
    
    void makeColumn(final int[] frame) {
        final int y = frame[1];
        final int x = frame[0];
        
        if (columnValidate(y, x)) {
            columnWall[y][x] = true;
        }
    }
    
    void makeRow(final int[] frame) {
        final int y = frame[1];
        final int x = frame[0];
        
        if (rowValidate(y, x)) {
            rowWall[y][x] = true;
        }
    }
    
    void removeColumn(final int[] frame) {
        final int y = frame[1];
        final int x = frame[0];
        
        columnWall[y][x] = false;
        
        if (!check()) {
            columnWall[y][x] = true;
        }
    }
    
    void removeRow(final int[] frame) {
        final int y = frame[1];
        final int x = frame[0];
        
        rowWall[y][x] = false;
        
        if (!check()) {
            rowWall[y][x] = true;
        }
    }
        
    boolean check() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (columnWall[y][x]) {
                    if (!columnValidate(y, x)) {
                        return false;
                    }
                }
                if (rowWall[y][x]) {
                    if (!rowValidate(y, x)) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    boolean columnValidate(final int y, final int x) {
        if (isOnFloor(y) || isOnColumn(y, x) || isOnRowEdge(y, x)) {
            return true;
        }
        
        return false;
    }
    
    boolean rowValidate(final int y, final int x) {
        if (isOnColumnEdge(y, x) || isConnectedBothRow(y, x)) {
            return true;
        }
        return false;
    }
    
    boolean isConnectedBothRow(final int y, final int x) {
        if (x == 0) {
            return false;
        }
        
        final boolean left = rowWall[y][x - 1];
        final boolean right = rowWall[y][x + 1];
        
        if (left && right) {
            return true;
        }
        return false;
    }
    
    boolean isOnColumnEdge(final int y, final int x) {
        final boolean here = columnWall[y - 1][x];
        final boolean right = columnWall[y - 1][x + 1];
        
        if (here || right) {
            return true;
        }
        return false;
    }
    
    boolean isOnRowEdge(final int y, final int x) {
        if (x == 0) {
            final boolean here = rowWall[y][x];
            
            if (here) {
                return true;
            }
            return false;
        }
        
        final boolean here = rowWall[y][x];
        final boolean left = rowWall[y][x - 1];
        
        if (here || left) {
            return true;
        }
        return false;
    }
    
    boolean isOnColumn(final int y, final int x) {
        final boolean below = columnWall[y - 1][x];
        
        if (below) {
            return true;
        }
        return false;
    }
    
    boolean isOnFloor(final int y) {
        if (y == 0) {
            return true;
        }
        return false;
    }
    
    static class Node {
        int y;
        int x;
        int a;
        Node(int y, int x, int a) {
            this.y = y;
            this.x = x;
            this.a = a;
        }
    }
}