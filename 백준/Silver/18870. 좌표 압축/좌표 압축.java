import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    int[] numbers;
    List<Integer> answers = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        N = Integer.parseInt(reader.readLine());
        numbers = new int[N];

        Set<Integer> set = new HashSet<>();
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
            set.add(numbers[i]);
        }

        Object[] temp = set.toArray();
        int[] sortedNumbers = new int[temp.length];

        for (int i = 0; i < temp.length; i++) {
            Integer num = (Integer)temp[i];

            sortedNumbers[i] = num;
        }

        Arrays.sort(sortedNumbers);

        for (int i = 0; i < N; i++) {
            final int index = lowerBound(sortedNumbers, numbers[i]);

            answers.add(index);
        }

        final List<String> output = new ArrayList<>();

        answers.stream().forEach(e -> {
            output.add(String.valueOf(e));
        });

        final String result = String.join(" ", output);

        writer.write(result);
        writer.newLine();
        writer.flush();

        close();
    }

    int lowerBound(final int[] arr, final int num) {
        int left = 0;
        int right = arr.length - 1;
        int result = arr.length;

        while (left <= right) {
            final int mid = (left + right) / 2;

            if (arr[mid] >= num) {
                result = mid;

                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}