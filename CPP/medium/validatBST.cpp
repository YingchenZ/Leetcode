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
    TreeNode* prev = nullptr;
    bool ans = true;
public:
    void solve(TreeNode* node){
        if(!node) return;
        
        solve(node->left);
        if(!prev){
            prev = node;
        }
        else{
            ans = ans &&(prev->val < node->val);
            prev = node;
        }
        if(!ans) return;
        solve(node->right);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return false;
        solve(root);
        return ans;
    }
};

void printTree(TreeNode* node){
    if(!node) return;
    printTree(node->left);
    std::cout << node->val << " ";
    printTree(node->right);
}

// Tree = 1 5 3 4 6
// Valid?   No

// Tree = 1 2 3
// Valid?   Yes

int main(){
    TreeNode* root1 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    TreeNode* root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    TreeNode* testSet[] = {root1, root2};

    for(auto test : testSet){
        Solution* sol = new Solution();
        std::cout << "Tree = ";
        printTree(test);
        std::cout << "\nValid?\t " << (sol->isValidBST(test)? "Yes" : "No") << std::endl << std::endl; 
    }

    return 0;
}