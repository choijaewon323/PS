import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    Pair[] meetings;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();

        Arrays.sort(meetings, (o1, o2) -> {
            if (o1.end < o2.end) {
                return -1;
            } else if (o1.end == o2.end) {
                if (o1.start < o2.start) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return 1;
        });

        final int answer = solve();

        writer.write(String.valueOf(answer));
        writer.newLine();
        writer.flush();

        close();
    }

    int solve() {
        int result = 0;
        int present = 0;

        for (Pair meeting : meetings) {
            if (meeting.start >= present) {
                result++;
                present = meeting.end;
            }
        }

        return result;
    }

    void input() throws Exception {
        N = Integer.parseInt(reader.readLine());

        meetings = new Pair[N];
        for (int i = 0; i < N; i++) {
            int start, end;

            StringTokenizer st = new StringTokenizer(reader.readLine(), " ");
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());

            meetings[i] = new Pair(start, end);
        }
    }

    static class Pair {
        final int start;
        final int end;
        Pair(final int start, final int end) {
            this.start = start;
            this.end = end;
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}