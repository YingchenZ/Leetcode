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
    private static void similar(TreeNode node, List<Integer> seq){
        if(node == null) return;
        if(node != null && node.left == null && node.right == null){
            seq.add(node.val);
            return;
        }
        similar(node.left, seq);
        similar(node.right, seq);
    }

    public static boolean leafSimilar(TreeNode root1, TreeNode root2) {
        if(root1 == null || root2 == null) return false;
        List<Integer> r1 = new ArrayList<>();
        List<Integer> r2 = new ArrayList<>();
        similar(root1, r1);
        similar(root2, r2);
        return r1.equals(r2);
    }
    // root1 = [3,5,1,6,2,9,8,null,null,7,4]
    // root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
    // Equals? true
    
    // root1 = [1,2,3]
    // root2 = [1,3,2]
    // Equals? false

    public static void main(String[] args){
        TreeNode r1 = new TreeNode(3, 
                new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))),
                new TreeNode(1, new TreeNode(9), new TreeNode(8)));
        TreeNode r2 = new TreeNode(3, 
        new TreeNode(5, new TreeNode(6), new TreeNode(7)),
        new TreeNode(1, new TreeNode(4), new TreeNode(2, new TreeNode(9), new TreeNode(8))));
        System.out.println("root1 = [3,5,1,6,2,9,8,null,null,7,4]");
        System.out.println("root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]");
        System.out.println("Equals? " + leafSimilar(r1, r2) + '\n');
        r1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        r2 = new TreeNode(1, new TreeNode(3), new TreeNode(2));
        System.out.println("root1 = [1,2,3]");
        System.out.println("root2 = [1,3,2]");
        System.out.println("Equals? " + leafSimilar(r1, r2));
    }
}