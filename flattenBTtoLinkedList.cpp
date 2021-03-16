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
#include<vector>
class Solution {
public:
    void preorder(TreeNode* node, std::vector<TreeNode*>& list){
        if(node){
            list.push_back(node);
            preorder(node->left, list);
            preorder(node->right, list);
        }
    }

    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        std::vector<TreeNode*> list = {};
        preorder(root, list);
        for(int i = 0; i < list.size() - 1; i++){
            list[i]->left = nullptr;
            list[i]->right = list[i + 1];
        }
    }
};