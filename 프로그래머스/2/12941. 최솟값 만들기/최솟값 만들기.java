import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        int size = A.length;
        
        Integer[] arrA = new Integer[A.length];
        Integer[] arrB = new Integer[B.length];
        
        for (int i = 0; i < size; i++) {
            arrA[i] = A[i];
            arrB[i] = B[i];
        }
        
        Arrays.sort(arrA);
        Arrays.sort(arrB, Collections.reverseOrder());

        int result1 = 0;

        for (int i = 0; i < size; i++) {
            int a = arrA[i];
            int b = arrB[i];

            result1 += a * b;
        }

        Arrays.sort(arrA, Collections.reverseOrder());
        Arrays.sort(arrB);

        int result2 = 0;

        for (int i = 0; i < size; i++) {
            int a = arrA[i];
            int b = arrB[i];

            result2 += a * b;
        }

        answer = Math.min(result1, result2);

        return answer;
    }
}