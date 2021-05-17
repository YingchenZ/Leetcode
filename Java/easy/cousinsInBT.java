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
    private static class TestHolder{
        TreeNode root;
        int x, y;
        TestHolder(TreeNode root, int x, int y){
            this.root = root;
            this.x = x;
            this.y = y;
        }
    }
    private static TreeNode xParent = null, yParent = null;
    private static int xDepth = -1, yDepth = -1;

    private static void findVal(TreeNode node, TreeNode parent, int x, int y, int currentDepth){
        if(node == null)    return;
        if(yParent != null && xParent != null)  return;
        findVal(node.left, node, x, y, currentDepth + 1);
        if(node.val == x){
            xDepth = currentDepth;
            xParent = parent;
        }
        if(node.val == y){
            yDepth = currentDepth;
            yParent = parent;
        }
        if(yParent != null && xParent != null)  return;
        findVal(node.right, node, x, y, currentDepth + 1);
    }

    public static boolean isCousins(TreeNode root, int x, int y) {
        findVal(root, root, x, y, 0);
        return xDepth == yDepth && xParent != yParent;
    }

    public static void inorder(TreeNode node){
        if(node == null)    return;
        inorder(node.left);
        System.out.print(" " + node.val);
        inorder(node.right);
    }

    // Tree = 4 2 1 3
    // x = 4 and y = 3 are not cousins
    
    // Tree = 2 4 1 3 5
    // x = 5 and y = 4 are cousins
    
    // Tree = 2 4 1 3
    // x = 2 and y = 3 are not cousins

    public static void main(String[] args){
        TreeNode root1 = new TreeNode(1, new TreeNode(2, new TreeNode(4),null), new TreeNode(3));
        TreeNode root2 = new TreeNode(1, new TreeNode(2, null, new TreeNode(4)), new TreeNode(3, null, new TreeNode(5)));
        TreeNode root3 = new TreeNode(1, new TreeNode(2, null, new TreeNode(4)), new TreeNode(3));

        TestHolder[] testSet = new TestHolder[]{
            new TestHolder(root1, 4, 3),
            new TestHolder(root2, 5, 4),
            new TestHolder(root3, 2, 3)
        };

        for(TestHolder test : testSet){
            xDepth = -1;
            yDepth = -1;
            xParent = null;
            yParent = null;
            System.out.print("Tree =");
            inorder(test.root);
            System.out.println("\nx = " + test.x + " and y = " + test.y + " are" + (isCousins(test.root, test.x, test.y)? "":" not") + " cousins\n");
        }
    }
}