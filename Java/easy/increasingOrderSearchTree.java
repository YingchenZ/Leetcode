import java.util.*;

class Solution {
    public class TreeNode {
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
    private TreeNode parent;
    private void inorder(TreeNode root){
        if(root == null){
            return;
        }

        inorder(root.left);
        parent.right = root;
        root.left = null;
        parent = parent.right;

        inorder(root.right);
    }

    public TreeNode increasingBST(TreeNode root) {
        TreeNode ansRoot = new TreeNode(-1);
        parent = ansRoot;
        inorder(root);
        return ansRoot.right;
    }
}