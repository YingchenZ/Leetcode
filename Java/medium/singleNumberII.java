import java.util.*;

class Solution {
    public static int singleNumber(int[] nums) {
        if(nums.length == 1) return nums[0];

        Arrays.sort(nums);

        for(int i = 0; i < nums.length; i+= 3){
            if(i == nums.length - 1 || nums[i] != nums[i + 1]){
                return nums[i];
            }
        }
        return nums[nums.length - 1];
    }

    // nums = [2, 2, 3, 2]
    // The single element = 3
    
    // nums = [-2, -2, 1, 1, 4, 1, 4, 4, -4, -2]        
    // The single element = -4
    
    // nums = [0, 1, 0, 1, 0, 1, 2, 2, 2, 3, 99, 99, 99]
    // The single element = 3

    public static void main(String[] args){
        List<int[]> testSet = Arrays.asList(
            new int[]{2,2,3,2},
            new int[]{-2,-2,1,1,4,1,4,4,-4,-2},
            new int[]{0,1,0,1,0,1,2,2,2,3,99,99,99}
        );

        for(int[] test : testSet){
            System.out.println("nums = " + Arrays.toString(test));
            System.out.println("The single element = " + singleNumber(test) + '\n');
        }
    }
}