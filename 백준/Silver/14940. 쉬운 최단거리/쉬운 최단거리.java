import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int n;
    int m;
    int startY;
    int startX;
    static final int MAX = 1000;
    int[][] map = new int[MAX][MAX];
    int[][] dist = new int[MAX][MAX];
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();

        bfs();

        output();

        close();
    }

    boolean inRange(final int y, final int x) {
        if (0 <= y && y < n && 0 <= x && x < m) {
            return true;
        }
        return false;
    }

    void bfs() {
        Queue<Pair> queue = new LinkedList<>();
        dist[startY][startX] = 1;

        queue.add(new Pair(startY, startX));

        while (!queue.isEmpty()) {
            Pair present = queue.poll();

            for (int i = 0; i < 4; i++) {
                final int ny = present.y + dy[i];
                final int nx = present.x + dx[i];

                if (inRange(ny, nx) && map[ny][nx] != 0 && dist[ny][nx] == 0) {
                    dist[ny][nx] = dist[present.y][present.x] + 1;
                    queue.add(new Pair(ny, nx));
                }
            }
        }
    }

    void input() throws Exception {
        final String nm = reader.readLine();
        StringTokenizer tk = new StringTokenizer(nm, " ");

        n = Integer.valueOf(tk.nextToken());
        m = Integer.valueOf(tk.nextToken());

        for (int y = 0; y < n; y++) {
            final String line = reader.readLine();
            final StringTokenizer tokenizer = new StringTokenizer(line, " ");

            for (int x = 0; x < m; x++) {
                final int num = Integer.valueOf(tokenizer.nextToken());

                if (num == 2) {
                    startY = y;
                    startX = x;
                }
                map[y][x] = num;
            }
        }
    }

    private static class Pair {
        int y;
        int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    void output() throws Exception {
        for (int y = 0; y < n; y++) {
            StringBuilder sb = new StringBuilder();

            for (int x = 0; x < m; x++) {
                if (map[y][x] == 0) {
                    sb.append("0 ");
                }
                else {
                    sb.append(dist[y][x] - 1 + " ");
                }
            }
            sb.append("\n");
            writer.write(sb.toString());
        }
        writer.flush();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}