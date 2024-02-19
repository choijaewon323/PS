import java.util.*;
import java.io.*;

/*
입력값 〉 [["a", "09:00", "30"], ["b", "09:20", "10"], ["c", "09:40", "10"]]
기댓값 〉 ["b", "a", "c"]
*/

class Solution {
    
    static final int MAX = 2000;
    
    Stack<Node> stopped = new Stack<>();
    Queue<Node> tasks = new LinkedList<>();
    
    public String[] solution(String[][] plans) {
        List<Node> temp = new ArrayList<>();
        
        for (final String[] plan : plans) {
            final String name = plan[0];
            final int start = timeToInt(plan[1]);
            final int playTime = Integer.parseInt(plan[2]);
            
            temp.add(new Node(name, start, playTime));
        }
        
        Collections.sort(temp, (o1, o2) -> {
            if (o1.start < o2.start) {
                return -1;
            }
            return 1;
        });
        
        temp.stream().forEach(e -> {
            tasks.add(e);
        });
        
        final String[] answer = solve();
        
        return answer;
    }
    
    String[] solve() {
        List<String> results = new ArrayList<>();
        
        while (!tasks.isEmpty()) {
            final Node present = tasks.poll();
            
            // isLast
            if (tasks.isEmpty()) {
                results.add(present.name);
                
                break;
            }
            
            final Node next = tasks.peek();
            
            int distance = next.start - present.start;
            final int presentDist = present.playTime;
            
            if (distance == presentDist) {
                results.add(present.name);
            } else if (distance < presentDist) {
                present.playTime -= distance;
                stopped.push(present);
            } else {
                stopped.push(present);
                
                while (!stopped.isEmpty() && distance > 0) {
                    final Node temp = stopped.pop();
                    
                    if (distance < temp.playTime) {
                        temp.playTime -= distance;
                        stopped.push(temp);
                        break;
                    } else if (distance == temp.playTime) {
                        results.add(temp.name);
                        break;
                    } else {
                        results.add(temp.name);
                        distance -= temp.playTime;
                    }
                }
            }
        }
        
        while (!stopped.isEmpty()) {
            final Node temp = stopped.pop();
            results.add(temp.name);
        }
        
        return results.toArray(String[]::new);
    }
    
    int timeToInt(final String time) {
        StringTokenizer st = new StringTokenizer(time, ":");
        
        final int hour = Integer.parseInt(st.nextToken());
        final int minute = Integer.parseInt(st.nextToken());
        
        return hour * 60 + minute;
    }
    
    static class Node {
        String name;
        int start;
        int playTime;
        
        Node(String name, int start, int playTime) {
            this.name = name;
            this.start = start;
            this.playTime = playTime;
        }
    }
}