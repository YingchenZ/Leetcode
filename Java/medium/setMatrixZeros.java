import java.util.*;

class Solution {
    public static void setZeroes(int[][] matrix) {
        boolean firstRowZero = false;

        for(int block : matrix[0]){
            if(block == 0){
                firstRowZero = true;
                break;
            }
        }
        int row = matrix.length, col = matrix[0].length;
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        
        for(int i = 1; i < row; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < col; j++){
                    matrix[i][j] = 0;
                }
            }
        }


        for(int i = 0; i < col; i++){
            if(matrix[0][i] == 0){
                for(int j = 1; j < row; j++){
                    matrix[j][i] = 0;
                }
            }
        }

        if(firstRowZero){
            for(int i = 0; i < col; i++){
                matrix[0][i] = 0;
            }
        }
    }

    public static void printMatrix(int[][] matrix){
        for(int row = 0; row < matrix.length; row++){
            for(int col = 0; col < matrix[row].length; col++){
                System.out.print((matrix[row][col] < 10?" ":"") + " " + matrix[row][col]);
            }

            System.out.println();
        }
        System.out.println();
    }

//     ============ Test ============
//     Before
//     1  1  1
//     1  0  1
//     1  1  1
  
//     After
//     1  0  1
//     0  0  0
//     1  0  1
  
//   ============ Test ============
//     Before
//     0  1  2  0
//     3  4  5  2
//     1  3  1  5
  
//     After
//     0  0  0  0
//     0  4  5  0
//     0  3  1  0

    public static void main(String[] args){
        List<int[][]> testSet = Arrays.asList(
            new int[][]{
                {1,1,1},
                {1,0,1},
                {1,1,1}
            },
            new int[][]{
                {0,1,2,0},
                {3,4,5,2},
                {1,3,1,5}
            }
        );

        for(int i = 0; i < testSet.size(); i++){
            System.out.println("============ Test ============");
            System.out.println("  Before");
            printMatrix(testSet.get(i));
            setZeroes(testSet.get(i));
            System.out.println("  After");
            printMatrix(testSet.get(i));
        }
    }
}