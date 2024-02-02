import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    Set<String> names = new HashSet<>();
    List<String> answers = new ArrayList<>();
    int N;
    int M;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();

        output();

        close();
    }

    void output() throws Exception {
        writer.write(String.valueOf(answers.size()));
        writer.newLine();

        Collections.sort(answers);
        
        for (String name : answers) {
            writer.write(name);
            writer.newLine();
        }
    }

    void input() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            final String name = reader.readLine();

            names.add(name);
        }

        for (int i = 0; i < M; i++) {
            final String name = reader.readLine();

            if (names.contains(name)) {
                answers.add(name);
            }
        }
    }


    void close() throws Exception {
        reader.close();
        writer.close();
    }
}