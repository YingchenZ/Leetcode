import java.util.*;

class Solution {
    public static int numWays(int steps, int arrLen) {
        int col = Math.min(steps / 2, arrLen - 1);
        int[] dp = new int[col + 1];

        dp[0] = 1;
     
        for(int i = 1; i <= steps; i++){
            int[] dpNext = new int[col + 1];
            for (int j = 0; j <= col; j++) {
                long ans = dp[j];
                if (j - 1 >= 0) {
                    ans += dp[j - 1];
                }
                if (j + 1 <= col) {
                    ans += dp[j + 1];
                }
                dpNext[j] += ans % 1000000007;
            }
            dp = dpNext;
        }
        return dp[0];
    }

    // steps = 3       arrLen = 2
    // Number of Ways that the pointer will stay at index 0 = 4        
    
    // steps = 2       arrLen = 4
    // Number of Ways that the pointer will stay at index 0 = 2        
    
    // steps = 4       arrLen = 2
    // Number of Ways that the pointer will stay at index 0 = 8        
    
    // steps = 500     arrLen = 1000000
    // Number of Ways that the pointer will stay at index 0 = 374847123

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            new int[]{3,2}, new int[]{2,4}, new int[]{4,2},new int[]{500, 1000000}
        };

        for(int[] test : testSet){
            System.out.println("steps = " + test[0] + "\tarrLen = " + test[1]);
            System.out.println("Number of Ways that the pointer will stay at index 0 = " + numWays(test[0], test[1]) + '\n');
        }
    }
}