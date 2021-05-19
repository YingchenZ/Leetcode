import java.util.*;

class TreeNode {
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

class TestHolder{
    TreeNode root;
    int k;
    TestHolder(TreeNode root, int k){
        this.root = root;
        this.k = k;
    }
}

class Solution {
    private static int count = 0;
    private static int ans = 0;
    private static void solve(TreeNode node, int k){
        if(node == null)    return;

        solve(node.left, k);
        if(count < k){
            ans = node.val;
            count++;
        }
        else{
            return;
        }
        solve(node.right, k);
    }

    public static int kthSmallest(TreeNode root, int k) {
        solve(root, k);
        return ans;
    }

    private static void inorder(TreeNode node){
        if(node == null)    return;
        inorder(node.left);
        System.out.print(" " + node.val);
        inorder(node.right);
    }
    
    // root =  1 2 3 4         k = 1        
    // Ans = 1
    
    // root =  1 2 3 4 5 6             k = 3
    // Ans = 3

    public static void main(String[] args){
        TreeNode root1 = new TreeNode(3,
            new TreeNode(1, null, new TreeNode(2)),
            new TreeNode(4)
        );
        TreeNode root2 = new TreeNode(5,
            new TreeNode(3, new TreeNode(2, new TreeNode(1), null), new TreeNode(4)),
            new TreeNode(6)
        );


        TestHolder[] testSet = new TestHolder[]{
            new TestHolder(root1, 1),
            new TestHolder(root2, 3)
        };

        for(TestHolder test : testSet){
            count = 0;
            ans = 0;
            System.out.print("root = ");
            inorder(test.root);
            System.out.println("\t\tk = " + test.k);
            System.out.println("Ans = " + kthSmallest(test.root, test.k) + '\n');
        }
    }
}