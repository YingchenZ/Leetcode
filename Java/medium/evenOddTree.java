import java.util.*;

import jdk.nashorn.api.tree.Tree;

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
    private static class Pair {
        int dep;
        TreeNode node;
        Pair(int dep, TreeNode node){
            this.dep = dep;
            this.node = node;
        }
    }

    public static boolean isEvenOddTree(TreeNode root) {
        if(root == null)    return false;
        int preVal = 0, currentDep = 0, depth = 0;
        LinkedList<Pair> nodeQ = new LinkedList<>() ;
        nodeQ.add(new Pair(0, root));

        while(nodeQ.size() != 0){
            Pair front = nodeQ.poll();
            depth = front.dep;
            TreeNode node = front.node;
            if(depth % 2 == 0 && node.val % 2 == 0) return false;
            if(depth % 2 != 0 && node.val % 2 != 0) return false;

            if(currentDep < depth){
                currentDep = depth;
                preVal = node.val;
            } 
            else if(currentDep > 0 && currentDep == depth && depth % 2 == 0){
                if(preVal >= node.val)  return false;
                preVal = node.val;
            }
            else if(currentDep > 0 && currentDep == depth && depth % 2 != 0){
                if(preVal <= node.val)  return false;
                preVal = node.val;
            }

            if(node.left != null)   nodeQ.add(new Pair(depth + 1, node.left));
            if(node.right != null)   nodeQ.add(new Pair(depth + 1, node.right));
        }
        return true;
    }

    private static void inorder(TreeNode node){
        if(node == null)    return;
        inorder(node.left);
        System.out.print(" " + node.val);
        inorder(node.right);
    }

    // Tree = 12 3 8 10 1 6 7 4 9 2 
    // Is Even-Odd Tree?       True 

    // Tree = 3 4 3 5 7 2
    // Is Even-Odd Tree?       False

    // Tree = 3 9 5 5 7 1
    // Is Even-Odd Tree?       False

    public static void main(String[] args){
        TreeNode root1 = new TreeNode(1, 
                new TreeNode(10, new TreeNode(3, new TreeNode(12), new TreeNode(8)), null),
                new TreeNode(4, new TreeNode(7, new TreeNode(6), null), new TreeNode(9, null, new TreeNode(2)))
            );
        TreeNode root2 = new TreeNode(5, 
            new TreeNode(4, new TreeNode(3), new TreeNode(3)),
            new TreeNode(2, new TreeNode(7), null)
        );
        TreeNode root3 = new TreeNode(5, 
            new TreeNode(9, new TreeNode(3), new TreeNode(5)),
            new TreeNode(1, new TreeNode(7), null)
       );

       TreeNode[] testSet = new TreeNode[]{root1, root2, root3};
       for(TreeNode test : testSet){
           System.out.print("Tree =");
           inorder(test);
           System.out.println("\nIs Even-Odd Tree?\t" + (isEvenOddTree(test)? "True":"False") + '\n');
       }
    }
}