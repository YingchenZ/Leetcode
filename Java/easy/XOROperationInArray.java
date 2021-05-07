import java.util.*;

class Solution {
    public static int xorOperation(int n, int start) {
        int ans = start;
        for(int i = 1; i < n; i++){
            ans ^= (start += 2);
        }
        return ans;
    }

    // n = 5   start = 0       Bitwise XOR = 8
    // n = 4   start = 3       Bitwise XOR = 8
    // n = 10  start = 5       Bitwise XOR = 2
    // n = 1000        start = 10      Bitwise XOR = 2000

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            {5,0}, {4,3},
            {10,5}, {1000, 10}
        };
    
        for(int[] test : testSet){
            System.out.println("n = " + test[0] + "\tstart = " + test[1] + "\tBitwise XOR = " + xorOperation(test[0], test[1]));
        }
    }
}