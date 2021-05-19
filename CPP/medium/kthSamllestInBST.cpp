#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TestHolder{
    TreeNode* root;
    int k;
    TestHolder(TreeNode* root, int k) : root(root), k(k){}
};
 
class Solution {
private:
    int ans = -1, count = 0;
public:
    void inorder(TreeNode* node, int k){
        if(!node)   return;
        
        inorder(node->left, k);
        if(ans <= node->val)    count++;
        if(count <= k){
            ans = node->val;
        }
        else{
            return;
        }

        inorder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};

void inorder(TreeNode* node){
    if(!node)   return;
    inorder(node->left);
    std::cout << " " << node->val;
    inorder(node->right);
}

// Tree = 1 2 3 4          k = 1
// Ans = 1

// Tree = 1 2 3 4 5 6              k = 3
// Ans = 3

int main(){
    TreeNode* root1 = new TreeNode(3,
        new TreeNode(1, nullptr, new TreeNode(2)),
        new TreeNode(4)
    );
    TreeNode* root2 = new TreeNode(5,
        new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)),
        new TreeNode(6)
    );

    std::vector<TestHolder*> testSet = {
        new TestHolder(root1, 1),
        new TestHolder(root2, 3)
    };

    for(TestHolder* test : testSet){
        Solution* sol = new Solution();
        std::cout << "Tree =";
        inorder(test->root);
        std::cout << "\t\tk = " << test->k << std::endl;
        std::cout << "Ans = " << sol->kthSmallest(test->root, test->k) << std::endl << std::endl;
    }

    return 0;
}
