import java.util.*;
import java.io.*;

class Solution {
    
    Map<String, List<Integer>> table = new HashMap<>();
    List<Integer> answers = new ArrayList<>();
    
    public int[] solution(String[] info, String[] query) {
        makeAllKey();
        
        input(info);
        
        for (String key : table.keySet()) {
            final List<Integer> nums = table.get(key);
            
            Collections.sort(nums, Comparator.naturalOrder());
        }
        
        solve(query);
        
        final int[] answer = answers.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
    
    void makeAllKey() {
        String[] languages = {"-", "cpp", "java", "python"};
        String[] jobs = {"-", "backend", "frontend"};
        String[] olds = {"-", "junior", "senior"};
        String[] foods = {"-", "chicken", "pizza"};
        
        for (String lang : languages) {
            for (String job : jobs) {
                for (String old : olds) {
                    for (String food : foods) {
                        StringBuilder sb = new StringBuilder();
                        
                        sb.append(lang);
                        sb.append(job);
                        sb.append(old);
                        sb.append(food);
                        
                        final String key = sb.toString();
                        
                        table.put(key, new ArrayList<>());
                    }
                }
            }
        }
    }
    
    void input(String[] info) {
        for (int i = 0; i < info.length; i++) {
            final String inf = info[i];
            StringTokenizer st = new StringTokenizer(inf, " ");
            
            final String language = st.nextToken();
            final String job = st.nextToken();
            final String old = st.nextToken();
            final String food = st.nextToken();
            final int score = Integer.parseInt(st.nextToken());
            
            makePossibleKey(language, job, old, food, score);
        }
    }
    
    void makePossibleKey(String language, String job, String old, String food, int score) {
        String[] languages = {"-", language};
        String[] jobs = {"-", job};
        String[] olds = {"-", old};
        String[] foods = {"-", food};
        
        for (String lang : languages) {
            for (String j : jobs) {
                for (String o : olds) {
                    for (String f : foods) {
                        StringBuilder sb = new StringBuilder();
                        
                        sb.append(lang);
                        sb.append(j);
                        sb.append(o);
                        sb.append(f);
                        
                        final String key = sb.toString();
                        
                        table.get(key).add(score);
                    }
                }
            }
        }
    }
    
    String makeKey(String language, String job, String old, String food) {
        StringBuilder sb = new StringBuilder();
        
        sb.append(language);
        sb.append(job);
        sb.append(old);
        sb.append(food);
        
        return sb.toString();
    }
    
    void solve(final String[] query) {
        for (final String q : query) {
            StringTokenizer st = new StringTokenizer(q, " ");
            
            final String language = st.nextToken();
            st.nextToken();
            final String job = st.nextToken();
            st.nextToken();
            final String old = st.nextToken();
            st.nextToken();
            final String food = st.nextToken();
            final int score = Integer.parseInt(st.nextToken());
            
            final String key = makeKey(language, job, old, food);
            
            final List<Integer> presentList = table.get(key);
            
            final int index = lowerBound(presentList, score);
            
            if (index == -1) {
                answers.add(0);
            } else {
                answers.add(presentList.size() - index);
            }
        }
    }
    
    int lowerBound(final List<Integer> list, final int score) {
        int left = 0;
        int right = list.size() - 1;
        int result = -1;
        
        while (left <= right) {
            final int mid = (left + right) / 2;
            
            if (list.get(mid) >= score) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    static class Node {
        String language;
        String job;
        String old;
        String food;
        int score;
        
        Node(String language, String job, String old, String food, int score) {
            this.language = language;
            this.job = job;
            this.old = old;
            this.food = food;
            this.score = score;
        }
    }
    
}