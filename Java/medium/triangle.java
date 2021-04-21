import java.util.*;

class Solution {
    public static int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size() == 1 && triangle.get(0).size() == 1) return triangle.get(0).get(0);

        int[][] dp = new int[triangle.size() + 1][triangle.get(triangle.size() - 1).size() + 1];

        dp[1][1] = triangle.get(0).get(0);
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < triangle.size() - 1; i++){
            min = Integer.MAX_VALUE;
            for(int j = 0; j < triangle.get(i).size(); j++){
                dp[i + 2][j + 2] = dp[i + 1][j + 1] + triangle.get(i + 1).get(j + 1);
                if(j == 0){
                    dp[i + 2][j + 1] = dp[i + 1][j + 1] + triangle.get(i+1).get(j);
                }
                else{
                    dp[i + 2][j + 1] = Math.min(dp[i + 2][j + 1], dp[i + 1][j + 1] + triangle.get(i+1).get(j)); 
                }
                min = Math.min(min, Math.min(dp[i+2][j + 1], dp[i + 2][j + 2]));
            }
        }
        return min;
    }

    public static void printMatrix(int[][] matrix){
        for(int[] row : matrix){
            for (int is : row) {
                System.out.print(is + " ");
            }
            System.out.println();
        }
    }

    // ===== Test Matrix =====
    // -10 
    // Minimum Path Sum from Top to Bottom = -10
    
    // ===== Test Matrix =====
    // 1 
    // 2 3 
    // Minimum Path Sum from Top to Bottom = 3
    
    // ===== Test Matrix =====
    // -1
    // 3 2
    // 1 -2 -1
    // Minimum Path Sum from Top to Bottom = -1

    public static void main(String[] args) {
        List<int[][]> testSet = new ArrayList<>();
        testSet.add(new int[][]{{-10}});
        testSet.add(new int[][]{{1},{2,3}});
        testSet.add(new int[][]{{-1},{3,2},{1,-2,-1}});

        for(int[][] test : testSet){
            System.out.println("===== Test Matrix =====");
            printMatrix(test);
            List<List<Integer>> list = new ArrayList<List<Integer>>();
            for(int i = 0; i < test.length; i++){
                List<Integer> columnList = new ArrayList<Integer>();
                for (int j = 0; j < test[i].length; j++) {
                    columnList.add(j, test[i][j]);
                }
                list.add(i, columnList);
            }
            System.out.println("Minimum Path Sum from Top to Bottom = " + minimumTotal(list) + '\n');
        }
    }
}