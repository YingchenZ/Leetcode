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
 
class Solution {
private:
    int xDepth = 0, yDepth = 0;
    TreeNode* xParent = nullptr, *yParent = nullptr;

public:
    void found(int x, int y, TreeNode* node, TreeNode* parent, int currentDepth){
        if(!node)   return;
        if(xParent && yParent)  return;
        found(x, y, node->left, node, currentDepth + 1);
        if(node->val == x){
            xParent = parent;
            xDepth = currentDepth;
        }
        if(node->val == y){
            yParent = parent;
            yDepth = currentDepth;
        }
        found(x, y, node->right, node, currentDepth + 1);
        if(xParent && yParent)  return;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        found(x, y, root, root, 0);
        return xParent != yParent && xDepth == yDepth;
    }
};

void inorder(TreeNode* node){
    if(!node)   return;
    inorder(node->left);
    std::cout << " " << node->val ;
    inorder(node->right); 
}

struct TestHolder{
    TreeNode* root;
    int x, y;
    TestHolder(TreeNode* r, int xVal, int yVal) : root(r), x(xVal), y(yVal){}
};

// Tree = 4 2 1 3
// x = 4 and y = 3 are not cousins

// Tree = 2 4 1 3 5
// x = 5 and y = 4 are cousins

// Tree = 2 4 1 3
// x = 2 and y = 3 are not cousins

int main(){
    TreeNode* root1 = new TreeNode(1, new TreeNode(2, new TreeNode(4),nullptr), new TreeNode(3));
    TreeNode* root2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3, nullptr, new TreeNode(5)));
    TreeNode* root3 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3));

    std::vector<TestHolder*> testSet = {
        new TestHolder(root1, 4, 3),
        new TestHolder(root2, 5, 4),
        new TestHolder(root3, 2, 3)
    };

    for(TestHolder* test : testSet){
        Solution* sol = new Solution();
        std::cout << "Tree =";
        inorder(test->root);
        std::cout << "\nx = " << test->x << " and y = " << test->y << " are" << (sol->isCousins(test->root, test->x, test->y)? "":" not") << " cousins\n" << std::endl;
    }
    return 0;
}