import java.util.*;
import java.io.*;

class Solution {
    
    static final int INF = 1000000000;
    
    int[] timeTable;
    int interval;
    int allTime;
    
    public String solution(String play_time, String adv_time, String[] logs) {
        allTime = toSecond(play_time);
        interval = toSecond(adv_time);
        timeTable = new int[allTime + 3];
        
        for (final String log : logs) {
            final StringTokenizer st = new StringTokenizer(log, "-");
            
            final int start = toSecond(st.nextToken());
            final int end = toSecond(st.nextToken());
            
            timeTable[start]++;
            timeTable[end]--;
        }
        
        bulk();
        
        final int result = findAnswer();
        
        final String answer = toTime(result);
        
        return answer;
    }
    
    void bulk() {
        for (int i = 0; i <= allTime; i++) {
            timeTable[i + 1] += timeTable[i];
        }
    }
    
    int findAnswer() {
        int start = 0;
        int end = interval - 1;
        
        int index = 0;
        long temp = calculate(start, end);
        long dist = temp;
        
        while (end <= allTime - 1) {
            dist -= timeTable[start];
            start++;
            
            end++;
            dist += timeTable[end];
            
            if (end <= allTime - 1) {
                if (dist > temp) {
                    index = start;
                    temp = dist;
                }
            }
        }
        
        return index;
    }
    
    long calculate(final int start, final int end) {
        long result = 0;
        
        for (int i = start; i <= end; i++) {
            result += timeTable[i];
        }
        
        return result;
    }
    
    int toSecond(final String time) {
        final StringTokenizer st = new StringTokenizer(time, ":");
        
        final int hour = Integer.parseInt(st.nextToken());
        final int minute = Integer.parseInt(st.nextToken());
        final int second = Integer.parseInt(st.nextToken());
        
        return hour * 3600 + minute * 60 + second;
    }
    
    String toTime(final int second) {
        StringBuilder sb = new StringBuilder();
        int temp = second;
        
        final int hour = temp / 3600;
        temp %= 3600;
        sb.append(format(hour));
        
        sb.append(":");
        
        final int minute = temp / 60;
        temp %= 60;
        sb.append(format(minute));
        
        sb.append(":");
        
        final int sec = temp;
        sb.append(format(sec));
        
        return sb.toString();
    }
    
    String format(final int temp) {
        final String result = String.valueOf(temp);
        
        if (result.length() == 1) {
            return "0" + result;
        }
        return result;
    }
}