import java.util.*;

class Solution {
    private static int rob(int[] vec){
        int[] dp = new int[vec.length + 1];

        dp[0] = 0;
        dp[1] = vec[0];

        for(int i = 1; i < vec.length; i++){
            dp[i + 1] = Math.max(vec[i] + dp[i - 1], dp[i]);
        }

        return dp[vec.length];
    }

    public static int deleteAndEarn(int[] nums) {
        Arrays.sort(nums);
        int[] dp = new int[nums[nums.length - 1] + 1];

        for(int num : nums){
            dp[num] += num;
        }

        return rob(dp);
    }

    // For list = [3, 4, 2]    Max = 6
    // For list = [2, 2, 3, 3, 3, 4]   Max = 9
    // For list = [1, 1, 1, 2, 4, 5, 5, 5, 6]  Max = 18

    public static void main(String args[]){
        List<int[]> testSet = Arrays.asList(
            new int[]{3,4,2},
            new int[]{2,2,3,3,3,4},
            new int[]{1,1,1,2,4,5,5,5,6});
  

        for(int[] test: testSet){
            System.out.println("For list = " + Arrays.toString(test) + "\tMax = " + deleteAndEarn(test));
        }
    }
}