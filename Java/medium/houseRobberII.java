import java.util.*;

class Solution {
    public static int rob(int[] nums) {
        if(nums.length == 1) return nums[0];

        int[] dp =  new int[nums.length + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        // if we rob the first one;
        for(int i = 1; i < nums.length - 1;i++){
            dp[i + 1] = Math.max(dp[i], nums[i] + dp[i - 1]);
        }
        dp[nums.length] = dp[nums.length - 1];
 

        // if we don't rob the first one;
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2; i < nums.length;i++){
            dp[i] = Math.max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[nums.length-1] > dp[nums.length]? dp[nums.length-1] : dp[nums.length];
    }

    // For list = [4, 1, 2]    => Max = 4
    // For list = [1, 2, 1, 1] => Max = 3
    // For list = [1, 1, 1, 0] => Max = 2


    public static void main(String[] args){

        List<int[]> testSet = Arrays.asList(new int[]{4,1,2},new int[]{1,2,1,1}, new int[]{1,1,1,0});

        for(int[] test: testSet){
            System.out.println("For list = " + Arrays.toString(test) + "\t=> Max = " + rob(test));
        }
       
    }
}