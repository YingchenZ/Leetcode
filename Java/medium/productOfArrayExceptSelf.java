import java.util.*;

class Solution {
    public static int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];

        ans[1] = nums[0];
        for(int i = 2; i < nums.length; i++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int postfix = nums[nums.length - 1];
        for(int i = nums.length - 2; i > 0; i--){
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        ans[0] = postfix;

        return ans;
    }

    // nums = [1, 2, 3, 4]
    // Ans = [24, 12, 8, 6]

    // nums = [-1, 1, 0, -3, 3]
    // Ans = [0, 0, 9, 0, 0]

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            new int[]{1,2,3,4},
            new int[]{-1,1,0,-3,3}
        };

        for(int[] test: testSet){
            System.out.println("nums = " + Arrays.toString(test));
            System.out.println("Ans = " + Arrays.toString(productExceptSelf(test)) + '\n');
        }
    }
}