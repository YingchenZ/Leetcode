import java.util.*;

class Solution {
    public static int jump(int[] nums) {
        int maxPos = 0;
        int boundary = 0;
        int step = 0;
        for(int i = 0; i < nums.length - 1; i++){
            maxPos = Math.max(maxPos, nums[i] + i);
            if(i == boundary){
                boundary = maxPos;
                step++;
            }
        }
        return step;
    }

    // nums = [2, 3, 1, 1, 4]
    // Minimum Number of Jumps = 2
    
    // nums = [2, 3, 0, 1, 4]     
    // Minimum Number of Jumps = 2

    public static void main(String[] args){
        int[][] testSet = new int[][]{new int[]{2,3,1,1,4}, new int[]{2,3,0,1,4}};
        for(int[] test : testSet){
            System.out.println("nums = " + Arrays.toString(test));
            System.out.println("Minimum Number of Jumps = " + jump(test) + '\n');
        }
    }
}