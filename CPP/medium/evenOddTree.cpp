#include <vector>
#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool isEvenOddTree(TreeNode* root) {
    if(!root)   return false;
    std::queue<std::pair<int,TreeNode*>> nodeQ = {};
    nodeQ.push({0, root});
    int currentDepth = 0;
    int prevVal = 0;
    while(!nodeQ.empty()){
        int depth = nodeQ.front().first;
        TreeNode* node = nodeQ.front().second;
        nodeQ.pop();
        if(depth % 2 == 0 && node->val % 2 == 0)    return false;
        if(depth % 2 != 0 && node->val % 2 != 0)    return false;

        if(currentDepth > 0 && currentDepth == depth && depth % 2 == 0){
            if(prevVal >= node->val) return false;
            prevVal = node->val;
        }
        else if(currentDepth > 0 && currentDepth == depth && depth % 2 != 0){
            if(prevVal <= node->val) return false;
            prevVal = node->val;
        }
        else if(currentDepth < depth){
            currentDepth = depth;
            prevVal = node->val;
        }

        if(node->left) nodeQ.push({depth + 1, node->left});
        if(node->right) nodeQ.push({depth + 1, node->right});
    }
    return true;
}

void inorder(TreeNode* node){
    if(!node)   return;
    inorder(node->left);
    std::cout << " " << node->val ;
    inorder(node->right); 
}

// Tree = 12 3 8 10 1 6 7 4 9 2
// Is Even-Odd Tree?       True

// Tree = 3 4 3 5 7 2
// Is Even-Odd Tree?       False

// Tree = 3 9 5 5 7 1
// Is Even-Odd Tree?       False

int main(){
    std::vector<TreeNode*> testSet = {
        new TreeNode(1, 
            new TreeNode(10, new TreeNode(3, new TreeNode(12), new TreeNode(8)), nullptr),
            new TreeNode(4, new TreeNode(7, new TreeNode(6), nullptr), new TreeNode(9, nullptr, new TreeNode(2)))
        ),
        new TreeNode(5, 
            new TreeNode(4, new TreeNode(3), new TreeNode(3)),
            new TreeNode(2, new TreeNode(7), nullptr)
        ),
        new TreeNode(5, 
            new TreeNode(9, new TreeNode(3), new TreeNode(5)),
            new TreeNode(1, new TreeNode(7), nullptr)
        )
    };

    for(TreeNode* test : testSet){
        std::cout << "Tree =";
        inorder(test);
        std::cout << "\nIs Even-Odd Tree?\t"<< (isEvenOddTree(test)? "True\n" : "False\n") << std::endl;
    }
    return 0;
}
