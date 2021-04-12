import java.util.*;

class Solution {
    public static String largestNumber(int[] nums) {
        if(nums.length == 1) return String.valueOf(nums[0]);
        List<String> strNum = new ArrayList<String>();

        for(int num : nums){
            strNum.add(String.valueOf(num));
        }
        Collections.sort(strNum,(a, b)->{
            return (int)(Long.parseLong(b + a) - Long.parseLong(a + b));
        });
        String ans = "";
        for(String str : strNum){
            if(ans.length() == 0 && str.equals("0")) continue;
            ans += str;
        }
        return ans.length() == 0?"0":ans;
    }

    // List = [0]       => Largest Number = 0
    // List = [1]       => Largest Number = 1 
    // List = [10]      => Largest Number = 10
    // List = [999999991, 9]    => Largest Number = 9999999991
    // List = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]    => Largest Number = 9876543210
    
    public static void main(String args[]){
        int [][] testSet = {
            {0},{1},{10},{999999991,9},{1,2,3,4,5,6,7,8,9,0}
        };

        for(int[] test : testSet){
            System.out.println("List = " + Arrays.toString(test) + "\t => Largest Number = " + largestNumber(test));
        }
    }
}