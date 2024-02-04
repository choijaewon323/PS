import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int N;
    int r;
    int c;
    int answer;
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
    void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        final int size = pow(N);
        solve(0, new Pair(0, 0), new Pair(size, size));
        writer.write(String.valueOf(answer));
        writer.newLine();
        writer.flush();
        close();
    }
    boolean inRange(final Pair start, final Pair end) {
        if (start.y <= r && r < end.y && start.x <= c &&  c < end.x) {
            return true;
        }
        return false;
    }
    void solve(final int num, final Pair start, final Pair end) {
        final int size = end.y - start.y;
        if (size == 1) {
            if (start.y == r && start.x == c) {
                answer = num;
            }
            return;
        }
        int startNum = num;
        for (int y = start.y; y < end.y; y += size / 2) {
            for (int x = start.x; x < end.x; x += size / 2) {
                final Pair presentStart = new Pair(y, x);
                final Pair presentEnd = new Pair(y + size / 2, x + size / 2);
                if (inRange(presentStart, presentEnd)) {
                    solve(startNum, presentStart, presentEnd);
                }
                startNum += (size / 2) * (size / 2);
            }
        }
    }
    int pow(final int up) {
        if (up == 0) {
            return 1;
        }
        return pow(up - 1) * 2;
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