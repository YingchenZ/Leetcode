import java.util.*;

class Solution {
    public static int findDuplicate(int[] nums) {
        for(int num : nums){
            int index = num;
            if(index < 0)   index = -num;
            if(nums[index] < 0) return index;
            nums[index] *= -1;
        }

        return nums[0];
    }
    
    // Test: {1,1}
    // Duplicate Number = 1

    // Test: {1,2,1}       
    // Duplicate Number = 1

    // Test: {1,3,4,2,2}   
    // Duplicate Number = 2

    // Test: {3,1,3,4,2}   
    // Duplicate Number = 3
    
    public static void main(String[] args){
        List<int[]> testSet = Arrays.asList(
            new int[]{1,1},
            new int[]{1,2,1},
            new int[]{1,3,4,2,2},
            new int[]{3,1,3,4,2}
        );

        for(int[] test : testSet){
            System.out.print("Test: {");
            for(int i = 0; i < test.length; i++){
                System.out.print(test[i] + (i == (test.length - 1)? "}\n":","));
            }
            System.out.println("Duplicate Number = " + findDuplicate(test) + '\n');
        }
    }
}