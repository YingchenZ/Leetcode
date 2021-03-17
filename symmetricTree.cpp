/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* leftNode, TreeNode* rightNode){
        // if both node is null, then it should be true
        if(!leftNode && !rightNode){
            return true;
        }

        // if either node is null, then it's not symmetric
        if(!leftNode || !rightNode){
            return false;
        }

        // if neither of them is null then we check
        // leftnode goes to right, rightnode goes to left
        // leftNode goes to left, rightnode goes to right
        return (leftNode->val == rightNode->val) && helper(leftNode->right, rightNode->left) && helper(leftNode->left, rightNode->right);
    }

    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};