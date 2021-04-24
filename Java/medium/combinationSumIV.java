import java.util.*;

class Solution {
    public static int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];

        dp[0] = 1;

        for(int i = 1; i <= target; i++){
            for(int num : nums){
                if(num <= i && (dp[i] + dp[i - num]) < Integer.MAX_VALUE){
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }

    // Test Array = [3, 2, 1]  Target = 4
    // Number of Possible Combinations = 7

    // Test Array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 19, 40, 50, 560]       Target = 7
    // Number of Possible Combinations = 64

    
    public static void main(String[] args){
        int[][] testSet = {
            {3,2,1},
            {1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,19,40,50,560}
        };
        int[] targetSet = {4,7};

        for(int i = 0; i < testSet.length; i++){
            System.out.println("Test Array = " + Arrays.toString(testSet[i]) + "\tTarget = " + targetSet[i]);
            System.out.println("Number of Possible Combinations = " + combinationSum4(testSet[i], targetSet[i]) + "\n");
        }

    }


}