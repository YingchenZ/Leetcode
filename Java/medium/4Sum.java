import java.util.*;

class Solution {
    private static class TestHolder{
        int[] nums;
        int target;
        TestHolder(int[] nums, int target){
            this.nums = nums;
            this.target = target;
        }
    }

    public static List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        if(nums.length <= 3)    return ans;
        Arrays.sort(nums);

        for(int i = 0; i < nums.length; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.length; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.length - 1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        ans.add(new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[left], nums[right])));
                        left++;
                        while(left < right && nums[left] == nums[left - 1])
                            left++;
                    }
                    else if(sum > target){
                        right--;
                        while(left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else{
                        left++;
                        while(left < right && nums[left] == nums[left - 1])
                            left++;
                    }
                }
            }
        }
        return ans;
    }

    public static void printResult(List<List<Integer>> matrix){
        if(matrix.size() == 0) System.out.print("[]");
        for(int i = 0; i < matrix.size(); i++){
            System.out.print(Arrays.toString( matrix.get(i).toArray()));
            if(i != matrix.size() - 1){
                System.out.print(",");
            } 
        }
    }

    // Test = [2, 2, 2, 2, 2], target = 8
    // Result = [2, 2, 2, 2]
    
    // Test = [1, 0, -1, 0, -2, 2],    target = 0
    // Result = [-2, -1, 1, 2],[-2, 0, 0, 2],[-1, 0, 0, 1]

    public static void main(String[] args){
        TestHolder[] testSet = new TestHolder[]{
            new TestHolder(new int[]{2,2,2,2,2}, 8),
            new TestHolder(new int[]{1,0,-1,0,-2,2}, 0)
        };

        for(TestHolder test : testSet){
            System.out.println("Test = " + Arrays.toString(test.nums) + ",\ttarget = " + test.target);
            System.out.print("Result = ");
            printResult(fourSum(test.nums, test.target));
            System.out.println('\n');
        }
    }
}