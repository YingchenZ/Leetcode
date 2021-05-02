import java.util.*;

class Solution {    
    public static void helper(int start, int[] candidates, int target, List<Integer> temp, List<List<Integer>> ans){
        if(target == 0){
            ans.add(new ArrayList<Integer>(temp));
        }
        if(target < 0){
            return;
        }

        for(int i = start; i < candidates.length; i++){
            temp.add(candidates[i]);
            helper(i, candidates, target - candidates[i], temp, ans);
            temp.remove(temp.size() - 1);
        }
    }

    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(0,candidates, target, temp, ans);

        return ans;
    }

    public static void printResult(List<List<Integer>> matrix){
        for(int i = 0; i < matrix.size(); i++){
            System.out.print(Arrays.toString( matrix.get(i).toArray()));
            if(i != matrix.size() - 1){
                System.out.print(",");
            } 
        }
    }

    // candidates = [2, 3, 6, 7], target = 7
    // Combination = [2, 2, 3],[7]

    // candidates = [2, 3, 5], target = 8
    // Combination = [2, 2, 2, 2],[2, 3, 3],[3, 5]

    // candidates = [2], target = 1
    // Combination =

    // candidates = [1], target = 1
    // Combination = [1]

    public static void main(String[] args){
        int[] targetSet = new int[]{7,8,1,1};
        int[][] testSet = new int[][]{{2,3,6,7}, {2,3,5}, {2}, {1}};
        for(int i = 0; i < testSet.length; i++){
            System.out.println("candidates = " + Arrays.toString(testSet[i]) + ", target = " + targetSet[i]);
            System.out.print("Combination = ");
            printResult(combinationSum(testSet[i], targetSet[i]));
            System.out.println('\n');
        }
    }
}