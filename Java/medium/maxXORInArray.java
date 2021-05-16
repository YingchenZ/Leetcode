import java.util.*;

class TrieNode{
    public TrieNode[] children = new TrieNode[2];
}

class Solution {
    private static TrieNode root = new TrieNode();
    private static void insert(int num){
        TrieNode node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node.children[bit] == null){
                node.children[bit] = new TrieNode();
            }
            node = node.children[bit];
        }
    }

    private static int getMaxXORFor(int num){
        TrieNode node = root;
        int possibleNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            int target = (bit == 0)? 1: 0;
            target = (node.children[target] == null)? bit: target;
            if(i == 0){
                possibleNum += target;
            }
            else{
                possibleNum *= 2;
                possibleNum += (target * 2);
            }
            node = node.children[target];
        }
        return possibleNum ^ num;
    }

    public static int findMaximumXOR(int[] nums) {
        for(int num : nums){
            insert(num);
        }

        int maxXOR = 0;
        for(int num : nums){
            maxXOR = Math.max(maxXOR, getMaxXORFor(num));
        }
        return maxXOR;
    }
    
    // nums = [0]
    // Maximum Result of nums[i] XOR nums[j] = 0
    
    // nums = [2, 4]
    // Maximum Result of nums[i] XOR nums[j] = 6
    
    // nums = [8, 10, 2]
    // Maximum Result of nums[i] XOR nums[j] = 10
    
    // nums = [3, 10, 5, 25, 2, 8]
    // Maximum Result of nums[i] XOR nums[j] = 28
    
    // nums = [14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70]
    // Maximum Result of nums[i] XOR nums[j] = 127

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            new int[]{0}, new int[]{2,4},new int[]{8, 10, 2},
            new int[]{3,10,5,25,2,8},
            new int[]{14,70,53,83,49,91,36,80,92,51,66,70}
        };

        for(int[] test : testSet){
            root = new TrieNode();
            System.out.println("nums = " + Arrays.toString(test));
            System.out.println("Maximum Result of nums[i] XOR nums[j] = " + findMaximumXOR(test) + '\n');
        }
    }
}