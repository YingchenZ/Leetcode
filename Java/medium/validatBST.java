import java.util.*;

class Solution {
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

    private static boolean ans = true;
    private static TreeNode prev = null;

    private static void solve(TreeNode node){
        if(node == null) return;

        solve(node.left);

        if(prev == null){
            prev = node;
        }
        else{
            ans = ans && (prev.val < node.val);
            prev = node;
        }
        if(!ans) return;

        solve(node.right);
    }

    public static boolean isValidBST(TreeNode root) {
        if(root == null)    return false;
        solve(root);
        return ans;
    }

    private static void printTree(TreeNode node){
        if(node == null) return;
        printTree(node.left);
        System.out.print(node.val + " ");
        printTree(node.right);
    }

    // Tree = 1 5 3 4 6 
    // Valid?  No       
    
    // Tree = 1 2 3     
    // Valid?  Yes
    
    public static void main(String[] args){
        TreeNode root1 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
        TreeNode root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));

        TreeNode testSet[] = new TreeNode[]{root1, root2};
        for(TreeNode test : testSet){
            ans = true;
            prev = null;
            System.out.print("Tree = ");
            printTree(test);
            boolean result = isValidBST(test);
            System.out.println("\nValid?\t" + (result? "Yes": "No") + '\n');
        }

    }
}