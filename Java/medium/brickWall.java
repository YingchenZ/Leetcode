import java.util.*;

class Solution {
    public static int leastBricks(List<List<Integer>> wall) {
        HashMap<Integer, Integer> gap = new HashMap<>();

        int row = wall.size();
        int maxGap = 0;
        for(int i = 0; i < wall.size(); i++){
            List<Integer> currentRow = wall.get(i);
            int currentPosition = 0;
            for(int brick = 0; brick < currentRow.size() - 1; brick++){
                currentPosition += currentRow.get(brick);
                if(gap.get(currentPosition) != null){
                    gap.replace(currentPosition, gap.get(currentPosition) + 1);
                }
                else{
                    gap.put(currentPosition, 1);
                }
                if(maxGap < gap.get(currentPosition)){
                    maxGap = gap.get(currentPosition);
                }
            }
        }

        return row - maxGap;        
    }

    public static void printMatrix(List<List<Integer>> matrix){
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix.get(row).size(); col++){
                System.out.print((matrix.get(row).get(col) < 10?" ":"") + " " + matrix.get(row).get(col));
            }

            System.out.println();
        }
        System.out.println();
    }

//   ============ Test ============
//     1  1
//     2
//     1  1
  
//   The Minimum Number of Crossed Bricks After Drawing a Vertical Line = 1
  
//   ============ Test ============
//     1  2  2  1
//     3  1  2
//     1  3  2
//     2  3
//     3  1  2
//     1  3  1  1
  
//   The Minimum Number of Crossed Bricks After Drawing a Vertical Line = 2

    public static void main(String[] args){
        List<List<List<Integer>>> testSet = Arrays.asList(
            Arrays.asList(
                Arrays.asList(1,1),
                Arrays.asList(2),
                Arrays.asList(1,1)
            ),
            Arrays.asList(
                Arrays.asList(1,2,2,1),
                Arrays.asList(3,1,2),
                Arrays.asList(1,3,2),
                Arrays.asList(2,3),
                Arrays.asList(3,1,2),
                Arrays.asList(1,3,1,1)
            )
        );
        
        for(List<List<Integer>> test : testSet){
            System.out.println("============ Test ============");
            printMatrix(test);
            System.out.println("The Minimum Number of Crossed Bricks After Drawing a Vertical Line = " + leastBricks(test) + '\n');
        }
    
    }
}