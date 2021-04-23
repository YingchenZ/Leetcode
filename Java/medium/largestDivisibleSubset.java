import java.util.*;

class Solution {
    public static List<Integer> largestDivisibleSubset(int[] nums) {
      
    
        int n = nums.length;
      
        Arrays.sort(nums);
        int[] dp = new int[n];
        int big = 1;
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            big = Math.max(dp[i], big);
        }
        List<Integer> ans = new ArrayList<Integer>();
        int prev = -1, next = big;
        for(int i = n - 1; i >= 0; i--){
            if(prev == -1 && dp[i] == next){
                ans.add(nums[i]);
                prev = nums[i];
                next--;
            }
            if(dp[i] == next && (prev % nums[i] == 0)){
                ans.add(nums[i]);
                prev = nums[i];
                next = dp[i] - 1;
            }
        }

        return ans;
    }

    // Array = [3, 17] Largest Divisible Subset = [17]
    // Array = [1, 2, 3]       Largest Divisible Subset = [3, 1]
    // Array = [2, 3, 4, 9, 8] Largest Divisible Subset = [8, 4, 2]
    // Array = [3, 4, 16, 8]   Largest Divisible Subset = [16, 8, 4]
    // Array = [1, 2, 4, 7, 8, 9, 10, 11, 12, 13, 14, 5, 20]   Largest Divisible Subset = [20, 10, 5, 1]

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            {3, 17},
            {1,2,3},
            {2,3,4,9,8},
            {3,4,16,8},
            {1,2,4,7,8,9,10,11,12,13,14,5,20}
        };
        for(int[] test : testSet){
            System.out.println("Array = " + Arrays.toString(test) + "\tLargest Divisible Subset = " + largestDivisibleSubset(test));
        }
    }
}