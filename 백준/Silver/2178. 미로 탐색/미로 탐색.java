import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int n;
    int m;
    static final int MAX = 100;
    int[][] maze = new int[MAX][MAX];
    int[][] dist = new int[MAX][MAX];
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};

    public static void main(String[] args) throws Exception {


        new Main().solution();
    }

    void init() {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                dist[y][x] = 1000000000;
            }
        }
    }

    void solution() throws Exception {
        input();
        init();

        final int answer = bfs(0, 0);

        output(answer);

        close();
    }

    void input() throws Exception {
        final String nm = reader.readLine();
        StringTokenizer tk = new StringTokenizer(nm);

        n = Integer.valueOf(tk.nextToken());
        m = Integer.valueOf(tk.nextToken());

        for (int y = 0; y < n; y++) {
            final String line = reader.readLine();

            for (int x = 0; x < m; x++) {
                final char c = line.charAt(x);

                maze[y][x] = c - '0';
            }
        }
    }

    boolean inRange(final int y, final int x) {
        if (0 <= y && y < n && 0 <= x && x < m) {
            return true;
        }
        return false;
    }

    class CustomCompare implements Comparator<Pair> {
        @Override
        public int compare(Pair o1, Pair o2) {
            if (o1.cost < o2.cost) {
                return -1;
            }
            return 1;
        }
    }

    int bfs(final int startY, final int startX) {
        PriorityQueue<Pair> queue = new PriorityQueue<Pair>(new CustomCompare());

        dist[startY][startX] = 0;

        queue.add(new Pair(startY, startX, 0));

        while (!queue.isEmpty()) {
            Pair present = queue.poll();

            if (present.y == n - 1 && present.x == m - 1) {
                return present.cost + 1;
            }

            for (int i = 0; i < 4; i++) {
                final int ny = present.y + dy[i];
                final int nx = present.x + dx[i];
                final int cost = present.cost + 1;

                if (inRange(ny, nx) && maze[ny][nx] == 1) {
                    if (dist[ny][nx] > cost) {
                        dist[ny][nx] = cost;
                        queue.add(new Pair(ny, nx, cost));
                    }
                }
            }
        }

        return -1;
    }

    void output(final int answer) throws Exception {
        writer.write(String.valueOf(answer));
        writer.newLine();
        writer.flush();
    }

    private static class Pair {
        int y;
        int x;
        int cost;

        Pair(int y, int x, int cost) {
            this.y = y;
            this.x = x;
            this.cost = cost;
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}