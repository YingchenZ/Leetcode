import java.util.*;

class Solution {
    private static class TestHolder {
        int[] numbers;
        int target;
        TestHolder(int target, int[] numbers){
            this.numbers = numbers;
            this.target = target;
        }
    }

    public static int[] twoSum(int[] numbers, int target) {
        int[] ans = new int[2];
        int left, right, mid;
        for(int i = 0; i < numbers.length; i++){
            int second = target - numbers[i];
            ans[0] = i + 1;
            if(second >= numbers[i]){
                left = Math.min(numbers.length - 1, i + 1);
                right = numbers.length - 1;
            }
            else{
                left = 0;
                right = Math.max(0, i - 1);
            }

            while(left <= right){
                mid = (left + right) / 2;
                if(numbers[mid] == second){
                    ans[1] = mid + 1;
                    return ans;
                }
                else if(numbers[mid] < second){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return ans;
    }

    // numbers = [2, 7, 11, 15]
    // Result = [1, 2]
    
    // numbers = [2, 3, 4]
    // Result = [1, 3]
    
    // numbers = [-1, 0]
    // Result = [1, 2]
    
    // numbers = [0, 0, 3, 4]
    // Result = [1, 2]

    public static void main(String[] args){
        TestHolder[] testSet = {
            new TestHolder(9, new int[]{2,7,11,15}),
            new TestHolder(6, new int[]{2,3,4}),
            new TestHolder(-1, new int[]{-1, 0}),
            new TestHolder(0, new int[]{0,0,3,4})
        };

        for(TestHolder test : testSet){
            System.out.println("numbers = " + Arrays.toString(test.numbers));;
            System.out.println("Result = " + Arrays.toString(twoSum(test.numbers, test.target)) + '\n');
        }
    }
}