import java.util.*;

class Solution {
    public static int removeDuplicates(int[] nums) {
        if(nums.length == 1) return 1;
        int fast = 1, slow = 0;
        int n = nums.length;
        while(fast < n){
            if(nums[fast] == nums[slow]){
                fast++;
            }
            else{
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

    // Original Array = [1, 1, 2]      After removing duplicates = [1,2]
    // Original Array = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4] After removing duplicates = [0,1,2,3,4]

    public static void main(String[] args){
        ArrayList<int[]> testSet = new ArrayList<int[]>();
        testSet.add(new int[]{1,1,2});
        testSet.add(new int[]{0,0,1,1,1,2,2,3,3,4});

        for(int[] test : testSet){
            System.out.print("Original Array = " + Arrays.toString(test) + "\tAfter removing duplicates = [");
            int stop = removeDuplicates(test);
            for(int i = 0; i < stop; i++){
                System.out.print(test[i] + (i == (stop - 1)?"]\n":","));
            }
        }
    }
}