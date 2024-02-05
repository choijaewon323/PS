import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    int[][] map;
    boolean[][] visited;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};
    List<Integer> answers = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        N = Integer.parseInt(reader.readLine());
        map = new int[N][N];
        visited = new boolean[N][N];

        for (int y = 0; y < N; y++) {
            final String line = reader.readLine();

            for (int x = 0; x < N; x++) {
                final char c = line.charAt(x);

                map[y][x] = c - '0';
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[y][x] && map[y][x] == 1) {
                    answers.add(bfs(new Pair(y, x)));
                }
            }
        }

        Collections.sort(answers);

        writer.write(String.valueOf(answers.size()));
        writer.newLine();
        for (final int ans : answers) {
            writer.write(String.valueOf(ans));
            writer.newLine();
        }

        writer.flush();

        close();
    }

    boolean inRange(final int y, final int x) {
        if (0 <= y && y < N && 0 <= x && x < N) {
            return true;
        }
        return false;
    }

    int bfs(final Pair start) {
        Queue<Pair> q = new LinkedList<>();

        visited[start.y][start.x] = true;
        q.add(start);

        int result = 0;
        while (!q.isEmpty()) {
            final Pair present = q.poll();
            result++;

            for (int i = 0; i < 4; i++) {
                final int ny = present.y + dy[i];
                final int nx = present.x + dx[i];

                if (inRange(ny, nx) && !visited[ny][nx] && map[ny][nx] == 1) {
                    visited[ny][nx] = true;
                    q.add(new Pair(ny, nx));
                }
            }
        }

        return result;
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