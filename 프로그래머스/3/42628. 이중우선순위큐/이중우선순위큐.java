import java.util.*;

class Solution {
    PriorityQueue<Integer> minPQ = new PriorityQueue<>();
    PriorityQueue<Integer> maxPQ = new PriorityQueue<>(Collections.reverseOrder());
    StringTokenizer st;

    public int[] solution(String[] operations) {
        for (String operation : operations) {
            st = new StringTokenizer(operation, " ");

            char command = st.nextToken().charAt(0);
            int data = Integer.valueOf(st.nextToken());

            if (command == 'I') {
                insert(data);
            }
            else if (command == 'D') {
                delete(data);
            }
        }

        int[] answer = getResult();

        return answer;
    }

    int[] getResult() {
        int[] result = {0, 0};

        if (maxPQ.isEmpty()) {
            return result;
        }

        result[0] = maxPQ.peek();
        result[1] = minPQ.peek();

        return result;
    }

    void insert(final int data) {
        minPQ.add(data);
        maxPQ.add(data);
    }

    void delete(final int number) {
        if (maxPQ.isEmpty()) {
            return;
        }

        if (number > 0) {
            deleteMax();

            return;
        }

        deleteMin();
    }

    void deleteMax() {
        int maxValue = maxPQ.poll();
        ArrayList<Integer> tempArray = new ArrayList<>();

        while (!minPQ.isEmpty()) {
            int temp = minPQ.poll();

            if (temp == maxValue) {
                break;
            }

            tempArray.add(temp);
        }

        for (int temp : tempArray) {
            minPQ.add(temp);
        }
    }

    void deleteMin() {
        int minValue = minPQ.poll();
        ArrayList<Integer> tempArray = new ArrayList<>();

        while (!maxPQ.isEmpty()) {
            int temp = maxPQ.poll();

            if (temp == minValue) {
                break;
            }

            tempArray.add(temp);
        }

        for (int temp : tempArray) {
            maxPQ.add(temp);
        }
    }
}