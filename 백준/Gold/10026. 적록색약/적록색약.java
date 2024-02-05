import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    char[][] grid;
    boolean[][] visited;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void init() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                visited[y][x] = false;

                if (grid[y][x] == 'G') {
                    grid[y][x] = 'R';
                }
            }
        }
    }

    void solution() throws Exception {
        N = Integer.parseInt(reader.readLine());
        grid = new char[N][N];
        visited = new boolean[N][N];

        for (int y = 0; y < N; y++) {
            final String line = reader.readLine();

            for (int x = 0; x < N; x++) {
                final char c = line.charAt(x);

                grid[y][x] = c;
            }
        }

        int nonBlind = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[y][x]) {
                    nonBlind++;
                    bfs(new Pair(y, x));
                }
            }
        }

        init();
        int blind = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[y][x]) {
                    blind++;
                    bfs(new Pair(y, x));
                }
            }
        }

        final StringBuilder sb = new StringBuilder();
        sb.append(nonBlind);
        sb.append(" ");
        sb.append(blind);

        writer.write(sb.toString());
        writer.newLine();

        writer.flush();

        close();
    }

    boolean inRange(final int y, final int x) {
        if (0 <= y && y < N && 0 <= x & x < N) {
            return true;
        }
        return false;
    }

    void bfs(final Pair start) {
        final Queue<Pair> q = new LinkedList<>();
        final char color = grid[start.y][start.x];

        visited[start.y][start.x] = true;

        q.add(start);

        while (!q.isEmpty()) {
            final Pair present = q.poll();

            for (int i = 0; i < 4; i++) {
                final int ny = present.y + dy[i];
                final int nx = present.x + dx[i];

                if (inRange(ny, nx) && !visited[ny][nx] && grid[ny][nx] == color) {
                    visited[ny][nx] = true;
                    q.add(new Pair(ny, nx));
                }
            }
        }
    }

    static class Pair {
        int y;
        int x;
        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}