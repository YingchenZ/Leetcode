import java.util.*;
class findMinInRotatedSortedAarry {
    public static int findMin(int[] nums) {
        if(nums.length == 1) return nums[0];

        int left = 0, right = nums.length - 1;
        int mid = 0, smallest = nums[0];
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] < smallest) smallest = nums[mid];
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return smallest;
    }

    // Test: {3,4,5,1,2}       Min = 1 
    // Test: {4,5,6,7,0,1,2}   Min = 0 
    // Test: {11,13,15,17}     Min = 11
    // Test: {3,1,2}   Min = 1

    public static void main(String args[]) {
        List<int[]> testSet = new ArrayList<int[]>();
        testSet.add(new int[]{3,4,5,1,2});
        testSet.add(new int[]{4,5,6,7,0,1,2});
        testSet.add(new int[]{11,13,15,17});
        testSet.add(new int[]{3,1,2});

        for(int[] test : testSet){
            System.out.print("Test: {");
            for(int i = 0; i < test.length; i++){
                System.out.print(test[i] + (i == (test.length - 1)? "}":","));
            }
            int min = findMin(test);
            System.out.println("\tMin = " + min);
        }
    // c
    }
}
