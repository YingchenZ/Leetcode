import java.util.*;

class HouseRobber {
    public static int rob(int[] nums) {
        if(nums.length == 1) return nums[0];
      
        int dp[] = new int[nums.length + 1];

        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i < nums.length; i++){
            dp[i + 1] = Math.max(nums[i] + dp[i - 1], dp[i]);
        }
        return dp[nums.length];
    }

    // For list = [1, 2, 3, 1] Max = 4
    // For list = [2, 7, 9, 3, 1]      Max = 12


    public static void main(String args[]){
        List<int[]> testSet = Arrays.asList(new int[]{1,2,3,1},new int[]{2,7,9,3,1});
  

        for(int[] test: testSet){
            System.out.println("For list = " + Arrays.toString(test) + "\tMax = " + rob(test));
        }
    }
}