import java.util.*;

class Solution {
    public static int findMin(int[] nums) {
        if(nums.length == 1) return nums[0];
        if(nums[0] < nums[nums.length - 1]) return nums[0];

        int left = 0, right = nums.length - 1;
        int mid = 0;
        while(left < right){
            while(left < right && nums[left] == nums[left+1]){
                left++;
            }
            while(left < right && nums[right] == nums[right - 1]){
                right--;
            }

            mid = (left + right) / 2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }

    // Test: {3,1}     Min = 1
    // Test: {1,3,5}   Min = 1
    // Test: {2,2,0,1,1,2}     Min = 0
    // Test: {3,0,1,1,3}       Min = 0
    // Test: {1,2,3,4,5,6,7}   Min = 1
    // Test: {2,2,2,3,4,4,4,5,5,5,6,0,1,1,1,1,1,1}     Min = 0

    public static void main(String args[]){
        List<int[]> testSet = new ArrayList<int[]>();
        testSet.add(new int[]{3,1});
        testSet.add(new int[]{1,3,5});
        testSet.add(new int[]{2,2,0,1,1,2});
        testSet.add(new int[]{3,0,1,1,3});
        testSet.add(new int[]{1,2,3,4,5,6,7});
        testSet.add(new int[]{2,2,2,3,4,4,4,5,5,5,6,0,1,1,1,1,1,1});

        for(int[] test : testSet){
            System.out.print("Test: {");
            for(int i = 0; i < test.length; i++){
                System.out.print(test[i] + (i == (test.length - 1)? "}":","));
            }
            int min = findMin(test);
            System.out.println("\tMin = " + min);
        }
    }
}