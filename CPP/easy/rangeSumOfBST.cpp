#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode* node, int low, int high, int &sum){
    if(!node) return;

    helper(node->left, low, high, sum);
    if(node->val >= low && node->val <= high){
        sum += node->val;
    }
    helper(node->right, low, high, sum);

}
int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    helper(root, low, high, sum);
    return sum;
}


// Tree = [10,5,15,3,7,13,18,1,null,6]
// Low = 7 Hight = 15      Sum = 45

// Low = 6 Hight = 10      Sum = 23

// Low = 1 Hight = 18      Sum = 78

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    int testSet[][2] = {
        {7,15}, {6,10}, {1,18}
    };
    std::cout << "Tree = [10,5,15,3,7,13,18,1,null,6]"<<std::endl;
    for(auto test : testSet){
        std::cout << "Low = " << test[0] << "\tHight = "<< test[1]<< "\tSum = "<< rangeSumBST(root, test[0], test[1])<< std::endl<< std::endl;

    }
    return 0;
}