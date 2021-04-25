#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* parent;
public:
    void inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        
        inorder(root->left);
        parent->right = root;
        root->left = nullptr;

        parent = parent->right;

        inorder(root->right);

    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ansRoot = new TreeNode(-1);
        parent = ansRoot;
        inorder(root);
        return ansRoot->right;
    }
};

// [5,3,6,2,4,null,8,1,null,null,null,7,9]
// Increasing Order Search Tree => 1->2->3->4->5->6->7->8->9

int main(){
    TreeNode* ansRoot = new TreeNode(5);
    ansRoot->left = new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4));
    ansRoot->right = new TreeNode(6, nullptr, new TreeNode(8, new TreeNode(7), new TreeNode(9)));

    std::cout << "[5,3,6,2,4,null,8,1,null,null,null,7,9]" << std::endl;
    std::cout << "Increasing Order Search Tree => ";
    Solution* test = new Solution();
    TreeNode* ans = test->increasingBST(ansRoot);
    std::cout << ans->val;
    ans = ans->right;
    for(TreeNode* temp = ans; temp; temp = temp->right){
        std::cout << "->" << temp->val;
    }
    std::cout << std::endl;
    return 0;
}
// [5,3,6,2,4,null,8,1,null,null,null,7,9]
// [5,1,7]