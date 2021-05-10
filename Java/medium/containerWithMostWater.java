import java.util.*;

class Solution {
    public static int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int maxVol = 0;
        while(left <= right){
            int currentVol = Math.min(height[left], height[right]) * (right - left);
            maxVol = Math.max(maxVol, currentVol);
            if(height[left] <= height[right])   left++;
            else    right--;
        }
        return maxVol;
    }

    // height = [1, 1]
    // Max Area = 1
    
    // height = [1, 2, 1]
    // Max Area = 2
    
    // height = [4, 3, 2, 1, 4]
    // Max Area = 16
    
    // height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    // Max Area = 49

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            {1,1},
            {1,2,1},
            {4,3,2,1,4},
            {1,8,6,2,5,4,8,3,7}
        };

        for(int[] test : testSet){
            System.out.println("height = " + Arrays.toString(test));
            System.out.println("Max Area = " + maxArea(test) + '\n');
        }
    }
}