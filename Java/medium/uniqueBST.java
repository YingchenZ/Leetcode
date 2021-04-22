import java.util.*;

class Solution {
    public static int numTrees(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }

    // n = 2   Num of Unique Binary Search Trees = 2
    // n = 3   Num of Unique Binary Search Trees = 5
    // n = 5   Num of Unique Binary Search Trees = 42        
    // n = 7   Num of Unique Binary Search Trees = 429       
    // n = 19  Num of Unique Binary Search Trees = 1767263190

    public static void main(String[] args){
        int[] testSet = {2,3,5,7,19};

        for(int test: testSet){
            System.out.println("n = " + test + "\tNum of Unique Binary Search Trees = " + numTrees(test));
        }
    }
}