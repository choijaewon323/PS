import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    int M;
    Map<String, String> password = new HashMap<>();

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(reader.readLine(), " ");

            final String url = st.nextToken();
            final String pass = st.nextToken();

            password.put(url, pass);
        }

        for (int i = 0; i < M; i++) {
            final String url = reader.readLine();

            writer.write(password.get(url));
            writer.newLine();
        }

        writer.flush();

        close();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}