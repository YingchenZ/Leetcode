import java.util.*;



class Solution {
    private static int sum = 0;
    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public static void helper(TreeNode node, int low, int high){
        if(node == null)    return;

        helper(node.left, low, high);
        if(node.val >= low && node.val <= high)   sum += node.val;
        helper(node.right, low, high);
    }

    public static int rangeSumBST(TreeNode root, int low, int high) {
        helper(root, low, high);
        return sum;
    }

    // Tree = [10,5,15,3,7,13,18,1,null,6]
    // Low = 7 High = 15       Sum = 45
    
    // Low = 6 High = 10       Sum = 23
    
    // Low = 1 High = 18       Sum = 78


    public static void main(String[] args){
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(5);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(7);
        root.left.left.left = new TreeNode(1);
        root.left.right.left = new TreeNode(6);

        root.right = new TreeNode(15);
        root.right.left = new TreeNode(13);
        root.right.right = new TreeNode(18);

        System.out.println("Tree = [10,5,15,3,7,13,18,1,null,6]");
        int[][] testSet = { {7,15}, {6,10}, {1,18}};
        for(int[] test : testSet){
            sum = 0;
            System.out.println("Low = " + test[0] + "\tHigh = " + test[1] + "\tSum = " + rangeSumBST(root, test[0], test[1]) + '\n');
        }
    }
}