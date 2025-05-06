import java.io.*;
import java.util.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;
    int N, K;

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    public void solve() throws IOException {
        N = Integer.parseInt(reader.readLine());
        K = Integer.parseInt(reader.readLine());

        int start = 1;
        int end = K;

        int answer = 0;

        while (start <= end) {
            int mid = (start + end) / 2;

            long cnt = 0;
            for (int i = 1; i <= N; i++) {
                cnt += Math.min(N, mid / i);
            }

            if (cnt >= K) {
                answer = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        writer.write(String.valueOf(answer));
        writer.write("\n");

        close();
    }

    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}
