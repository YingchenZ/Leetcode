import java.util.*;

class Solution {
    public static int lengthOfLIS(int[] nums) {
        int maxLength = 1;
        int[] dp = new int[nums.length + 1];

        for(int i = 0; i < dp.length; i++){
            dp[i] = 1;
        }

        for(int i = 1; i < nums.length; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
            maxLength = Math.max(dp[i], maxLength);
        }
        return maxLength;
    }
    // nums = [0, 1, 0, 3, 2, 3]       Length of the Longest Increasing Subsequence = 4
    // nums = [4, 10, 4, 3, 8, 9]      Length of the Longest Increasing Subsequence = 3        
    // nums = [10, 9, 2, 5, 3, 7, 101, 18]     Length of the Longest Increasing Subsequence = 4

    public static void main(String[] args){
        List<int[]> testSet = Arrays.asList(
            new int[]{0,1,0,3,2,3},
            new int[]{4,10,4,3,8,9},
            new int[]{10,9,2,5,3,7,101,18}
        );

        for(int[] test : testSet){
            System.out.println("nums = " + Arrays.toString(test) + "\tLength of the Longest Increasing Subsequence = " + lengthOfLIS(test));
        }
    }
}