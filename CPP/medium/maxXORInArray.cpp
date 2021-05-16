#include <vector>
#include <iostream>

struct TrieNode{
    std::vector<TrieNode*> children;
    TrieNode(){
        for(int i = 0; i < 2; i++)
            children.push_back(nullptr);
    }
};

class Solution {
private:
    TrieNode* root = new TrieNode();
public:
    void insert(int num){
        TrieNode* currentNode = root;
        for(int i = 31; i >= 0; i--){
            // get the bit in that position
            int bit = (num >> i) & 1;
            // if the tree doesn't have this node
            if(!currentNode->children[bit]){
                // create this branch
                currentNode->children[bit] = new TrieNode();
            }
            // we go this branch
            currentNode = currentNode->children[bit];
        }   
    }

    int getMaxXORfor(int num){
        TrieNode* currentNode = root;
        int possibleNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            // the target should be the opposite of the current bit
            int target = (bit == 0)? 1 : 0;
            // if we have the branch (either 1 or 0), we use it
            // otherwise, we will use the existed one
            target = currentNode->children[target]? target : bit;
            // we go this branch
            currentNode = currentNode->children[target];
            if(i == 0){
                // when i == 0, we only add 1 or 0
                possibleNum += target;
            }
            else{
                // we double the sum
                possibleNum *= 2;
                // plus the 2 if target == 1
                possibleNum += (target * 2);
            }   
        }

        return possibleNum ^ num;
    }

    int findMaximumXOR(std::vector<int>& nums) {
        if(nums.size() == 0) return nums[0];
        if(nums.size() == 2) return nums[0] ^ nums[1];
        // add number to the tree
        for(int num : nums){
            insert(num);
        }
        int ans = 0;
        // find the answer
        for(int num : nums){
            ans = std::max(ans, getMaxXORfor(num));
        }
        return ans;
    }
};

// nums = {0}
// Maximum Result of nums[i] XOR nums[j] = 0

// nums = {2, 4}
// Maximum Result of nums[i] XOR nums[j] = 6

// nums = {8, 10, 2}
// Maximum Result of nums[i] XOR nums[j] = 10

// nums = {3, 10, 5, 25, 2, 8}
// Maximum Result of nums[i] XOR nums[j] = 28

// nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70}
// Maximum Result of nums[i] XOR nums[j] = 127

int main(){
    std::vector<std::vector<int>> testSet = {
        {0}, {2,4},{8, 10, 2},
        {3,10,5,25,2,8},
        {14,70,53,83,49,91,36,80,92,51,66,70}
    };

    for(std::vector<int> test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == test.size() - 1 ? "}\n":", ");
        }
        Solution* sol = new Solution();
        std::cout << "Maximum Result of nums[i] XOR nums[j] = " << sol->findMaximumXOR(test) << std::endl << std::endl;
    }
    return 0;
}