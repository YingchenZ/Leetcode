import java.util.*;

class Solution {
    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        if(nums.length < 3) return ans;
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(nums);
        int left, right;
        for(int i = 0; i < nums.length; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            left = i + 1;
            right = nums.length - 1;
            int tempSum;
            while(left < right){
                tempSum = nums[i] + nums[left] + nums[right];
                if(tempSum > 0){
                    right--;
                } 
                else if(tempSum < 0){
                    left++;
                }
                else{
                    temp = Arrays.asList(nums[i], nums[left], nums[right]);
                    ans.add(new ArrayList<>(temp));
                    temp = new ArrayList<>();
                    left++;   
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
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

    // Test = [-1, 0, 1, 2, -1, -4]
    // Result = [-1, -1, 2],[-1, 0, 1]

    // Test = [1, -1, -1, 0]
    // Result = [-1, 0, 1]

    // Test = []
    // Result = []

    // Test = [0]
    // Result = []

    // Test = [1, 2, 3, 4, 5, -3]
    // Result = [-3, 1, 2]

    // Test = [0, 0, 0, 0, 0, 0]
    // Result = [0, 0, 0]

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            {-1,0,1,2,-1,-4},
            {1,-1,-1,0},
            {}, {0},
            {1,2,3,4,5,-3},
            {0,0,0, 0,0,0}
        };

        for(int[] test : testSet){
            System.out.println("Test = " + Arrays.toString(test));
            System.out.print("Result = ");
            printResult(threeSum(test));
            System.out.println('\n');
        }
    }

    
}