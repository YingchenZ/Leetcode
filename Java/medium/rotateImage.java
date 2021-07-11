import java.util.*;

class Solution {
    public static void rotate(int[][] matrix) {
        int N = matrix.length;

        for(int row = 0; row < N; row++){
            for(int col = row + 1; col < N; col++){
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }

        for(int row = 0; row < N; row++){
            for(int start = 0, end = N - 1; start < end; start++, end--){
                int temp = matrix[row][start];
                matrix[row][start] = matrix[row][end];
                matrix[row][end] = temp;
            }
        }

        System.out.println("===== After =====");
        printMatrix(matrix);
    }

    public static void printMatrix(int[][] matrix){
        for(int[] row : matrix){
            System.out.println(Arrays.toString(row));
        }
    }

    // ===== Before =====
    // [1, 2, 3]
    // [4, 5, 6]
    // [7, 8, 9]
    // ===== After =====
    // [7, 4, 1]
    // [8, 5, 2]
    // [9, 6, 3]

    // ===== Before =====
    // [5, 1, 9, 11]
    // [2, 4, 8, 10]
    // [13, 3, 6, 7]
    // [15, 14, 12, 16]
    // ===== After =====
    // [15, 13, 2, 5]
    // [14, 3, 4, 1]
    // [12, 6, 8, 9]
    // [16, 7, 10, 11]

    public static void main(String[] args){
        int[][][] testSet = new int[][][]{
            new int[][]{
                new int[]{1,2,3},
                new int[]{4,5,6},
                new int[]{7,8,9}
            },
            new int[][]{
                new int[]{5,1,9,11},
                new int[]{2,4,8,10},
                new int[]{13,3,6,7},
                new int[]{15,14,12,16}
            }

        };

        for(int[][] test : testSet){
            System.out.println("===== Before =====");
            printMatrix(test);
            rotate(test);
            System.out.println();
        }
    }
}