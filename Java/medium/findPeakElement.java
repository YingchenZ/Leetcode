import java.util.*;

class Solution {
    public static int findPeakElement(int[] nums) {
        if(nums.length == 1)    return 0;
        if(nums.length == 2)    return nums[0] < nums[1] ? 1: 0;
        int left = 0, right = nums.length - 1;
        int mid = -1;
        while(left <= right){
            mid = (left + right) / 2;
            if(mid == 0 && nums[mid + 1] < nums[mid])   return mid;
            else if(mid == nums.length - 1 && nums[mid] > nums[mid - 1])    return mid;
            else if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) return mid;
            else if(nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }
            else{
                right = mid;
            }

        }
        return mid;
    }

    // nums = [1, 2]
    // Index of one of the peak numbers = 1
    
    // nums = [3, 1, 2]
    // Index of one of the peak numbers = 2
    
    // nums = [1, 2, 3, 1]
    // Index of one of the peak numbers = 2
    
    // nums = [3, 4, 3, 2, 1]
    // Index of one of the peak numbers = 1
    
    // nums = [1, 2, 1, 3, 5, 6, 4]        
    // Index of one of the peak numbers = 5
    
    public static void main(String[] args){
        int[][] testSet = new int[][]{
            new int[]{1,2},
            new int[]{3,1,2},
            new int[]{1,2,3,1},
            new int[]{3,4,3,2,1},
            new int[]{1,2,1,3,5,6,4}
        };

        for(int[] test : testSet){
            System.out.println("nums = " + Arrays.toString(test));
            System.out.println("Index of one of the peak numbers = " + findPeakElement(test) + '\n');
        }
    }
}