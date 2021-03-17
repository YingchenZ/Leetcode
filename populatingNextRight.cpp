/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* helper(Node* node){
        // if a node doesn't have left or right child, then it means we reach the bottom of the tree
        // we return nullptr
        if(!node){
            return nullptr;
        }
        
        // the next of node->left should be node->right
        if(node->left){
            node->left->next = node->right;
            helper(node->left);
        }  
        else{
            return nullptr;
        }
        // the next of node->right should be 
        //      if node->next is not null then it should be next->next->left
        if(node->right){
            node->right->next = node->next ? node->next->left : nullptr;
            helper(node->right);
        }
        else{
            return nullptr;
        }
        
        
        return node;
    }

    Node* connect(Node* root) {
        if(!root || !root->left || !root->right){
            return root;
        }
        return helper(root);
    }
};