import java.io.*;
import java.util.StringTokenizer;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;
    int a, b, c, d, e, f;

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    public void solve() throws IOException {
        st = new StringTokenizer(reader.readLine(), " ");

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
        f = Integer.parseInt(st.nextToken());

        Answer answer = findAnswer();

        writer.write(answer.x + " " + answer.y);
        writer.flush();

        close();
    }

    public void close() throws IOException {
        reader.close();
        writer.close();
    }

    public Answer findAnswer() {
        for (int x = -999; x <= 999; x++) {
            for (int y = -999; y <= 999; y++) {
                int first = a * x + b * y;

                if (first != c) {
                    continue;
                }

                int second = d * x + e * y;

                if (second != f) {
                    continue;
                }

                return new Answer(x, y);
            }
        }
        return new Answer(-1, -1);
    }

    static class Answer {
        int x;
        int y;

        public Answer(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
