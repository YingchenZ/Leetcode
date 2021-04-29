import java.util.*;

class Solution {
    public static boolean canCross(int[] stones) {
        if(stones.length == 2) return stones[1] == 1;
        HashMap<Integer, Integer> rock = new HashMap<>();
        for(int i = 0; i < stones.length; i++){
            rock.put(stones[i], i);
        }
        if(stones[1] != 1) return false;

        ArrayList<HashSet<Integer>> dp = new ArrayList<>();
        for(int i = 0; i < stones.length; i++){
            dp.add(new HashSet<Integer>());
        }

        dp.get(0).add(0);

        for(int i = 0; i < stones.length - 1; i++){
            int stoneP = stones[i];
            Object[] temp = dp.get(i).toArray();
            for(Object step : temp){
                for(int nextMove = (int)step - 1; nextMove <= (int)step + 1; nextMove++){
                    if(rock.get(nextMove + stoneP) != null){
                        int index = rock.get(nextMove + stoneP);
                        if(index == stones.length - 1) return true;
                        if(nextMove > 0)
                            dp.get(index).add(nextMove);
                    }
                }
            }
        }

        return false;
    }

    // Stones = [0, 1, 3, 6, 7]
    // Can cross the river?    No
    
    // Stones = [0, 1, 2, 3, 4, 8, 9, 11]
    // Can cross the river?    No
    
    // Stones = [0, 1, 3, 5, 6, 8, 12, 17]
    // Can cross the river?    Yes
    
    // Stones = [0, 2, 4, 5, 6, 8, 9, 11, 14, 17, 18, 19, 20, 22, 23, 24, 25, 27, 30]
    // Can cross the river?    No
    
    public static void main(String args[]){
        List<int[]> testSet = Arrays.asList(
            new int[]{0,1,3,6,7},
            new int[]{0,1,2,3,4,8,9,11},
            new int[]{0,1,3,5,6,8,12,17},
            new int[]{0,2,4,5,6,8,9,11,14,17,18,19,20,22,23,24,25,27,30}    
        );

        for(int[] test: testSet){
            System.out.println("Stones = " + Arrays.toString(test));
            System.out.println("Can cross the river?\t" + (canCross(test)? "Yes": "No")+ '\n');
        }
    }
}