import java.util.*;
import java.io.*;

/*
    scores 길이 : [1, 100,000] -> O(N log N) 이하의 알고리즘이 필요함
    
    한쪽으로 정렬하고 비교한다면?
    
    입력: [[4, 0], [2, 3], [4, 4], [2, 6]]
    정답: 3
*/

class Solution {
    
    List<Node> list = new ArrayList<>();
    
    public int solution(int[][] scores) {
        
        for (int i = 0; i < scores.length; i++) {
            final int index = i;
            final int work = scores[i][0];
            final int cowork = scores[i][1];
            
            list.add(new Node(index, work, cowork));
        }
        
        Collections.sort(list, (e1, e2) -> {
            if (e1.work < e2.work) {
                return 1;
            } else if (e1.work == e2.work) {
                if (e1.cowork < e2.cowork) {
                    return 1;
                }
                return -1;
            }
            return -1;
        });
        
        List<Node> deleted = delete();
        
        if (!wanhoSurvived(deleted)) {
            return -1;
        }
        
        final List<Score> totalScore = makeScore(deleted);
        
        Collections.sort(totalScore, (e1, e2) -> {
            if (e1.score < e2.score) {
                return 1;
            }
            return -1;
        });
        
        return rank(totalScore);
    }
    
    void printList(final List<Node> temp) {
        temp.stream().forEach(e -> {
            System.out.println(e.index + " : " + e.work + " " + e.cowork);
        });
    }
    
    int rank(final List<Score> total) {
        int rank = 0;
        int cnt = 0;
        Score high = null;
        
        for (final Score present : total) {
            // first
            if (high == null) {
                rank = 1;
                cnt++;
                high = present;
            } else {
                if (high.score == present.score) {
                    cnt++;
                } else {
                    rank += cnt;
                    cnt = 1;
                    high = present;
                }
            }
            
            if (present.index == 0) {
                return rank;
            }
        }
        
        return -1;
    }
    
    List<Score> makeScore(final List<Node> temp) {
        List<Score> results = new ArrayList<>();
        
        temp.stream().forEach(e -> {
            results.add(new Score(e.index, e.work + e.cowork));
        });
        
        return results;
    }
    
    boolean wanhoSurvived(final List<Node> temp) {
        for (final Node node : temp) {
            if (node.index == 0) {
                return true;
            }
        }
        
        return false;
    }
    
    List<Node> delete() {
        List<Node> results = new ArrayList<>();
        
        List<Node> high = new ArrayList<>();
        
        for (final Node node : list) {
            // first
            if (high.isEmpty()) {
                high.add(node);
                results.add(node);
                
                continue;
            }
            
            final Node highest = high.get(high.size() - 1);
            
            if (node.work < highest.work) {
                if (node.cowork < highest.cowork) {
                    continue;
                }
                
                results.add(node);
                if (node.cowork > highest.cowork) {
                    high.add(node);
                }
            } else if (node.work == highest.work) {
                if (validate(high, node)) {
                    results.add(node);
                    
                    if (node.cowork > highest.cowork) {
                        high.add(node);
                    }
                }
            }
        }
        
        return results;
    }
    
    boolean validate(final List<Node> high, final Node present) {
        for (final Node node : high) {
            if (node.work > present.work && node.cowork > present.cowork) {
                return false;
            }
        }
        
        return true;
    }
    
    static class Node {
        int index;
        int work;
        int cowork;
        
        Node(int index, int work, int cowork) {
            this.index = index;
            this.work = work;
            this.cowork = cowork;
        }
    }
    
    static class Score {
        int index;
        int score;
        
        Score(int index, int score) {
            this.index = index;
            this.score = score;
        }
    }
}