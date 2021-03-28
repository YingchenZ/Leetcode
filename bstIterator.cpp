#include <iostream>
#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    std::vector<int> inorderTree = {};
    int currentIndex = 0;
public:

    void makeItInorder(TreeNode* node, std::vector<int>& vec){
        if(!node) return;
        // left
        makeItInorder(node->left, vec);
        // root
        vec.push_back(node->val);
        // right
        makeItInorder(node->right, vec);
    }

    BSTIterator(TreeNode* root) {
        makeItInorder(root, inorderTree);
    }

    int next() {
        return inorderTree[currentIndex++];
    }
    
    bool hasNext() {
        return currentIndex < inorderTree.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

TreeNode* makeBST(TreeNode* root, std::queue<int>& testSet){
    if(!root){
        if(testSet.size() == 0) return nullptr;
        int value = testSet.front();
        testSet.pop();
        if(value == -1){
            return nullptr;
        }
        root = new TreeNode(value, nullptr, nullptr);
    }
    if(testSet.size() >= 1){
        int value = testSet.front();
        testSet.pop();
        if(value != -1){
            root->left = new TreeNode(value, nullptr, nullptr);
            // std::cout <<"root = "<< root->val <<  "Left = " << root->left->val << std::endl;
        }
    }
    if(testSet.size() >= 1){
        int value = testSet.front();
        testSet.pop();
        if(value != -1){
            root->right = new TreeNode(value, nullptr, nullptr);
            // std::cout << "root = "<< root->val << "Right = " << root->right->val << std::endl;
        }
    }
    if(root->left)
        makeBST(root->left, testSet);
    if(root->right)
        makeBST(root->right, testSet);
    return root;
}

// output
// 3
// 7
// True
// 9
// True
// 15
// True
// 20
// false


int main(){
    // -1 is null
    std::vector<int> test = {7, 3, 15, -1, -1, 9, 20};
    std::queue<int> testSet = {};
    for(int num: test){
        testSet.push(num);
    }
    TreeNode* root = makeBST(nullptr, testSet);
    BSTIterator* bSTIterator = new BSTIterator(root);
    std::cout << bSTIterator->next() << std::endl;
    std::cout << bSTIterator->next() << std::endl;
    std::cout << (bSTIterator->hasNext()? "True":"false") << std::endl;
    std::cout << bSTIterator->next() << std::endl;
    std::cout << (bSTIterator->hasNext()? "True":"false") << std::endl;
    std::cout << bSTIterator->next() << std::endl;
    std::cout << (bSTIterator->hasNext()? "True":"false") << std::endl;
    std::cout << bSTIterator->next() << std::endl;
    std::cout << (bSTIterator->hasNext()? "True":"false") << std::endl;
    return 0;
}