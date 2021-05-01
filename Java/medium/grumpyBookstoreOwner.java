import java.util.*;

class Solution {
    public static int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int currentBoost = 0;
        int ans = 0;
        for(int i = 0; i < customers.length; i++){
            if(grumpy[i] == 0){
                ans += customers[i];
            }
            else{
                if(i < X){
                    currentBoost += customers[i];
                }
            }
        }

        int maxBoost = currentBoost;

        for(int i = 1, j = X; i < customers.length - (X - 1) && j < customers.length; i++, j++){
            if(grumpy[i - 1] == 1){
                currentBoost -= customers[i - 1];
            }
            if(grumpy[j] == 1){
                currentBoost += customers[j];
            }
            if(maxBoost < currentBoost){
                maxBoost = currentBoost;
            }
        }

        return ans + maxBoost;
    }

    // customers = [1, 0, 1, 2, 1, 1, 7, 5]
    // grumpy = [0, 1, 0, 1, 0, 1, 0, 1]
    // X = 3
    // Maximum Number of Customers That Can Be Satisfied Throughout The Day = 16

    public static void main(String[] args){
        int[] customers = new int[]{1,0,1,2,1,1,7,5};
        int[] grumpy = new int[]{0,1,0,1,0,1,0,1};
        int X = 3;

        System.out.println("customers = " + Arrays.toString(customers));
        System.out.println("grumpy = " + Arrays.toString(grumpy));
        System.out.println("X = " + X);
        System.out.println("Maximum Number of Customers That Can Be Satisfied Throughout The Day = " + maxSatisfied(customers, grumpy, X));
    }
}