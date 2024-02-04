import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    int[] numbers;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        N = Integer.parseInt(reader.readLine());

        numbers = new int[N];
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");

        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(numbers);

        int answer = 0;
        int acc = 0;
        for (int num : numbers) {
            acc += num;
            answer += acc;
        }

        writer.write(String.valueOf(answer));
        writer.newLine();
        writer.flush();

        close();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}