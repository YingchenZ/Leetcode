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
 
void similar(TreeNode* node, std::vector<int> &seq){
    if(!node) return;
    if(node && !node->left && !node->right){
        seq.push_back(node->val);
        return;
    }

    similar(node->left, seq);
    similar(node->right, seq);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    std::vector<int> r1 = {};
    std::vector<int> r2 = {};

    similar(root1, r1);
    similar(root2, r2);
    return r1 == r2;
}

// root1 = [3,5,1,6,2,9,8,null,null,7,4]
// root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Equals? True

// root1 = [1,2,3]
// root2 = [1,3,2]
// Equals? False

int main(){
    TreeNode* r1 = new TreeNode(3, 
                new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))),
                new TreeNode(1, new TreeNode(9), new TreeNode(8)));
    TreeNode* r2 = new TreeNode(3, 
        new TreeNode(5, new TreeNode(6), new TreeNode(7)),
        new TreeNode(1, new TreeNode(4), new TreeNode(2, new TreeNode(9), new TreeNode(8))));
    std::cout << "root1 = [3,5,1,6,2,9,8,null,null,7,4]"<<std::endl;
    std::cout << "root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]"<<std::endl;
    std::cout << "Equals? " << (leafSimilar(r1, r2)? "True" : "false")<< std::endl << std::endl;

    r1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    r2 = new TreeNode(1, new TreeNode(3), new TreeNode(2));
    std::cout << "root1 = [1,2,3]"<<std::endl;
    std::cout << "root2 = [1,3,2]"<<std::endl;
    std::cout << "Equals? " << (leafSimilar(r1, r2)? "True" : "False")<< std::endl << std::endl;
    return 0;
}