import java.util.*;

class Solution {
    private static List<List<Integer>> ans = new ArrayList<>();
    private static void produce(int[] nums, int start, List<Integer> temp){
        ans.add(new ArrayList<>(temp));
        for(int i = start; i < nums.length; i++){
            temp.add(nums[i]);
            produce(nums, i + 1, temp);
            temp.remove(temp.size() - 1);
        }
        return;
    }

    public static List<List<Integer>> subsets(int[] nums) {
        produce(nums, 0, new ArrayList<Integer>());
        return ans;
    }

    private static void printResult(List<List<Integer>> result){
        System.out.print("[");
        for(int i = 0; i < result.size(); i++){
            System.out.print(Arrays.toString(result.get(i).toArray()));
            System.out.print(i == result.size() - 1? "]\n\n":",");
        }
    }

    // nums = [1]
    // Result = [[],[1]]
    
    // nums = [1, 2]
    // Result = [[],[1],[1, 2],[2]]
    
    // nums = [1, 2, 3]
    // Result = [[],[1],[1, 2],[1, 2, 3],[1, 3],[2],[2, 3],[3]]

    public static void main(String[] args){
        int[][] testSet = new int[][]{new int[]{1}, new int[]{1,2}, new int[]{1,2,3}};
        for(int[] test : testSet){
            ans = new ArrayList<>();
            System.out.println("nums = " + Arrays.toString(test));
            List<List<Integer>> result = subsets(test);
            System.out.print("Result = ");
            printResult(result);
        }
    }
}