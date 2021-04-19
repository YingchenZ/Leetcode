import java.util.*;

class Solution {
    public static int removeElement(int[] nums, int val) {
        if(nums.length == 0) return 0;
        if(nums.length == 1 && nums[0] == val) return 0;

        int slow = 0, fast = 0;
        int n = nums.length;
        while(fast < n){
            if(nums[fast] == val){
                fast++;
                continue;
            }

            nums[slow++] = nums[fast++];
        }

        return slow;
    }

    // Original Array = [3, 2, 2, 3]   Target = 3
    // After = [2,2]
    // Original Array = [0, 1, 2, 2, 3, 0, 4, 2]       Target = 0
    // After = [1,2,2,3,4,2]
    // Original Array = [0, 1, 2, 2, 3, 0, 4, 2]       Target = 1
    // After = [0,2,2,3,0,4,2]
    // Original Array = [0, 1, 2, 2, 3, 0, 4, 2]       Target = 2
    // After = [0,1,3,0,4]
    // Original Array = [0, 1, 2, 2, 3, 0, 4, 2]       Target = 4
    // After = [0,1,2,2,3,0,2]

    public static void main(String[] args){
       
        List<int[]> testSet1 = new ArrayList<int[]>();
        testSet1.add(new int[]{3,2,2,3});
        testSet1.add(new int[]{0,1,2,2,3,0,4,2});
        testSet1.add(new int[]{0,1,2,2,3,0,4,2});
        testSet1.add(new int[]{0,1,2,2,3,0,4,2});
        testSet1.add(new int[]{0,1,2,2,3,0,4,2});
        
        int testSet2[] = {3,0,1,2,4};

        for(int i = 0; i < testSet1.size();i++){
            System.out.println("Original Array = " + Arrays.toString(testSet1.get(i)) + "\tTarget = "+testSet2[i]);
            int stop = removeElement(testSet1.get(i), testSet2[i]);
            System.out.print("After = [");
            for(int j = 0; j < stop; j++){
                System.out.print(testSet1.get(i)[j] + (j == (stop - 1)?"]\n":","));
            }
        }
    }

}