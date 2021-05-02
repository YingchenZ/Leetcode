import java.util.*;

class Solution {
    private static List<List<Integer>> ans = new ArrayList<>();

    public static void helper(int start, int n, int k, List<Integer> temp){
        if(temp.size() == k){       
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i = start; i <= n; i++){
            temp.add(i);
            helper(i + 1, n, k, temp);
            temp.remove(temp.size() - 1);
        }
    }

    public static List<List<Integer>> combine(int n, int k) {
        helper(1,n, k, new ArrayList<>());
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

    // n = 1, k = 1
    // [[1]]

    // n = 4, k = 3
    // [[1, 2, 3],[1, 2, 4],[1, 3, 4],[2, 3, 4]]  

    // n = 4, k = 2
    // [[1, 2],[1, 3],[1, 4],[2, 3],[2, 4],[3, 4]]

    public static void main(String[] args){
        int[][] testSet = new int[][]{{1,1}, {4,3}, {4,2}};

        for(int[] test : testSet){
            System.out.println("n = " + test[0] + ", k = " + test[1]);
            System.out.print("[");
            List<List<Integer>> result = combine(test[0], test[1]);
            printResult(result);
            System.out.println("]\n");
            ans.clear();
        }
    }
}