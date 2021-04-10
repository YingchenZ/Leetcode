import java.util.*;

import javax.crypto.SealedObject;

class Solution {
    public static int search(int[] nums, int target) {
        if(nums.length == 1) return (nums[0] == target)? 0 : -1;

        int left = 0, right = nums.length - 1;
        int mid = 0;
        while(left <= right){
            mid = (left + right) / 2;

            if(nums[mid] == target) return mid;

            if(nums[mid] > target){
                if(nums[mid] <= nums[right] || target >= nums[left]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(nums[mid] >= nums[left] || target < nums[left]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

    // Test Array = {1}        Target = 0 is at -1        
    // Test Array = {3,1}      Target = 2 is at -1        
    // Test Array = {1,3}      Target = 0 is at -1        
    // Test Array = {4,5,6,7,0,1,2}    Target = 0 is at 4 
    // Test Array = {4,5,6,7,0,1,2}    Target = 3 is at -1
    // Test Array = {4,5,6,7,0,1,2}    Target = 2 is at 6
    
    public static void main(String args[]){
        List<int[]> testSet1 = new ArrayList<>();
        testSet1.add(new int[]{1});
        testSet1.add(new int[]{3,1});
        testSet1.add(new int[]{1,3});
        testSet1.add(new int[]{4,5,6,7,0,1,2});
        testSet1.add(new int[]{4,5,6,7,0,1,2});
        testSet1.add(new int[]{4,5,6,7,0,1,2});
      
        int testSet2[] = {0,2,0,0,3,2};


        for(int i = 0; i < testSet1.size(); i++){
            int[] testArray = testSet1.get(i);
            int target = testSet2[i];
            System.out.print("Test Array = {");
            for(int j = 0; j < testArray.length ; j++){
                System.out.print(testArray[j] + (j == (testArray.length - 1)? "}\t":","));
            }
            System.out.println("Target = " + target + " is at " + search(testArray, target));
        }
    }
}
