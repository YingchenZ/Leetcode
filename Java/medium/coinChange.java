import java.util.*;

class Solution {

    public static int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);

        dp[0] = 0;
        for(int subSum = 1; subSum <= amount; subSum++){ 
            for(int coin : coins){
                if(subSum - coin >= 0){
                    dp[subSum] = Math.min(1 + dp[subSum - coin], dp[subSum]);
                }
                else{
                    break;
                }
            }
        }
        return dp[amount] == (amount + 1)? -1 : dp[amount];
    }

    // coins = [2]     amount = 3
    // The fewest number of coins that you need to make up that amount = -1

    // coins = [1]     amount = 0
    // The fewest number of coins that you need to make up that amount = 0

    // coins = [1]     amount = 1
    // The fewest number of coins that you need to make up that amount = 1

    // coins = [1]     amount = 2
    // The fewest number of coins that you need to make up that amount = 2

    // coins = [1, 2, 5]       amount = 11
    // The fewest number of coins that you need to make up that amount = 3

    public static void main(String[] args){
        List<int[]> coinsSet = Arrays.asList(
            new int[]{2},
            new int[]{1},
            new int[]{1},
            new int[]{1},
            new int[]{1,2,5}
        );

        int[] amountSet = {3,0,1,2,11};

        for(int i = 0; i < coinsSet.size(); i++){
            System.out.println("coins = " + Arrays.toString(coinsSet.get(i)) + "\tamount = " + amountSet[i]);
            System.out.println("The fewest number of coins that you need to make up that amount = "+ coinChange(coinsSet.get(i), amountSet[i]) + '\n');
        }
    }
}