import java.util.*;

class Solution {
    public static boolean canJump(int[] nums) {
        int maxPos = 0;
        for(int i = 0; i < nums.length; i++){
            if(i <= maxPos){
                maxPos = Math.max(i + nums[i], maxPos);
                if(maxPos >= nums.length - 1)   return true;
            }
        }
        return false;
    }

    // nums = [2, 3, 1, 1, 4]
    // Can reach the end? true 
    
    // nums = [3, 2, 1, 0, 4]  
    // Can reach the end? false

    public static void main(String[] args){
        int[][] testSet = new int[][]{new int[]{2,3,1,1,4}, new int[]{3,2,1,0,4}};
        for(int[] test : testSet){
            System.out.println("nums = " + Arrays.toString(test));
            System.out.println("Can reach the end? " + canJump(test) + '\n');
        }
    }
}