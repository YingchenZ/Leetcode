import java.util.*;

class Solution {
    private static class TestHolder{
        public int[] nums;
        public int target;
        public TestHolder(int[] nums, int target){
            this.nums = nums;
            this.target = target;
        }
    }
    private static HashMap<String, Integer> dp = new HashMap<>();
    private static int helper(int[] nums, int target, int current, int tempSum){
        if(current == nums.length)  return target == tempSum? 1: 0;
        String key = String.valueOf(current) + ":" + String.valueOf(tempSum);
        if(!dp.containsKey(key)){
            dp.put(key, helper(nums, target, current+1, tempSum - nums[current]) +  helper(nums, target, current+1, tempSum + nums[current]));
        }
        return dp.get(key);
    }   

    public static int findTargetSumWays(int[] nums, int target) {
        return helper(nums, target, 0, 0);
    }

    // nums = [1]      target = 1
    // Number of different expressions = 1

    // nums = [1, 1, 1, 1, 1]  target = 3
    // Number of different expressions = 5

    public static void main(String[] args){
        TestHolder[] testSet = new TestHolder[]{
            new TestHolder(new int[]{1}, 1),
            new TestHolder(new int[]{1,1,1,1,1},3)
        };
    
        for(TestHolder test : testSet){
            dp = new HashMap<>();
            System.out.println("nums = " + Arrays.toString(test.nums) + "\ttarget = " + test.target);
            System.out.println("Number of different expressions = "+ String.valueOf(findTargetSumWays(test.nums, test.target)) + '\n');
        }
    }
}