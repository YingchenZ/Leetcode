import java.util.*;

class Solution {
    public static int uniquePaths(int m, int n) {
        if(m == 1) return 1;

        int[][] dp = new int[m + 1][n + 1];
        for(int i = 2; i < m + 1; i++){
            dp[i][1] = 1;
        }
        for(int i = 2; i < n + 1; i++){
            dp[1][i] = 1;
        }

        for(int i = 2; i < m + 1; i++){
            for(int j = 2; j < n + 1; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }

    // 3 * 2 Grid      Unique Paths = 3
    // 3 * 7 Grid      Unique Paths = 28  
    // 6 * 5 Grid      Unique Paths = 126 
    // 7 * 8 Grid      Unique Paths = 1716

    public static void main(String[] args){
        int[][] testSet = {
            {3,2}, {3,7},
            {6,5}, {7,8}
        };

        for(int i = 0; i < testSet.length; i++){
            System.out.println(testSet[i][0] + " * " + testSet[i][1] + " Grid\tUnique Paths = " + uniquePaths(testSet[i][0], testSet[i][1]));
        }
    }
}