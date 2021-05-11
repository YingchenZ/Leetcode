import java.util.*;

class Solution {
    private static void produce(int[] nums,List<List<Integer>> ans, List<Integer> temp){
        if(temp.size() == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i = 0; i < nums.length; i++){
            if(nums[i] >= -10){
                temp.add(nums[i]);
                nums[i] -= 21;
                produce(nums, ans, temp);
                nums[i] += 21;
                temp.remove(temp.size() - 1);
            }
        }
    }

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<Integer>();
        produce(nums, ans, temp);
        return ans;
    }

    // nums = [1]
    // Possible Permutations = [[1]]
    
    // nums = [0, 1]
    // Possible Permutations = [[0, 1],[1, 0]]
    
    // nums = [1, 2, 3]
    // Possible Permutations = [[1, 2, 3],[1, 3, 2],[2, 1, 3],[2, 3, 1],[3, 1, 2],[3, 2, 1]]

    public static void main(String[] args){
        int[][] testSet = new int[][]{{1},{0,1},{1,2,3}};

        for(int[] test : testSet){
            System.out.println("nums = " + Arrays.toString(test));
            List<List<Integer>> ans = permute(test);
            System.out.print("Possible Permutations = [");
            for(int i = 0; i < ans.size(); i++){
                System.out.print(Arrays.toString(ans.get(i).toArray()));
                System.out.print((i == ans.size() - 1)? "]\n\n":",");
            }

        }
    }
}