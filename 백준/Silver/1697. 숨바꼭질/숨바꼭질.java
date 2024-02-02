import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int n;
    int k;
    static final int MAX = 100000;
    int[] dist = new int[MAX + 1];

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();

        final int answer = bfs();

        output(answer);

        close();
    }

    boolean inRange(final int i) {
        if (0 <= i && i <= MAX) {
            return true;
        }
        return false;
    }

    int bfs() {
        Queue<Integer> queue = new LinkedList<>();

        dist[n] = 1;
        queue.add(n);

        while (!queue.isEmpty()) {
            final int present = queue.poll();

            if (present == k) {
                return dist[present] - 1;
            }

            final int left = present - 1;
            if (inRange(left) && dist[left] == 0) {
                dist[left] = dist[present] + 1;
                queue.add(left);
            }

            final int right = present + 1;
            if (inRange(right) && dist[right] == 0) {
                dist[right] = dist[present] + 1;
                queue.add(right);
            }

            final int jump = present * 2;
            if (inRange(jump) && dist[jump] == 0) {
                dist[jump] = dist[present] + 1;
                queue.add(jump);
            }
        }

        return -1;
    }

    void input() throws Exception {
        final String line = reader.readLine();

        final StringTokenizer tk = new StringTokenizer(line);

        n = Integer.valueOf(tk.nextToken());
        k = Integer.valueOf(tk.nextToken());
    }

    void output(final int answer) throws Exception {
        writer.write(Integer.toString(answer));
        writer.newLine();
        writer.flush();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}