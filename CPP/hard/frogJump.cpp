#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iostream>

bool canCross(std::vector<int> stones) {
    if(stones.size() == 2) return stones[1] == 1;
    std::unordered_map<int, int> rock = {};
    for(int i = 0; i < stones.size(); i++){
        rock[stones[i]] = i;
    }
    
    std::vector<std::unordered_set<int>> dp(stones.size(), std::unordered_set<int>{});
    dp[0].insert(0);
    if(stones[1] != 1) return false;
    for(int i = 0; i < stones.size() - 1; i++){
        for(auto j = dp[i].begin(); j != dp[i].end(); j++){
            int stoneP = stones[i];
            int index = 0;
            for(int nextMove = *j - 1; nextMove <= *j + 1; nextMove++){
                index = rock[nextMove + stoneP];
                if(index == stones.size() - 1) return true;
                if(nextMove != 0){
                    dp[index].insert(nextMove);
                }
            }
        }
    }
    return false;
}

// stones  = {0,1,3,6,7}
// Can cross the river?    No

// stones  = {0,1,2,3,4,8,9,11}
// Can cross the river?    No

// stones  = {0,1,3,5,6,8,12,17}
// Can cross the river?    Yes

// stones  = {0,2,4,5,6,8,9,11,14,17,18,19,20,22,23,24,25,27,30}
// Can cross the river?    No

int main(){
    std::vector<std::vector<int>> testSet = {
        {0,1,3,6,7},
        {0,1,2,3,4,8,9,11},
        {0,1,3,5,6,8,12,17},
        {0,2,4,5,6,8,9,11,14,17,18,19,20,22,23,24,25,27,30}
    };

    for(std::vector<int> test : testSet){
        std::cout << "stones  = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << ((i == (test.size() -1)) ? "}\n": ",");
        }
        std::cout << "Can cross the river?\t"<< (canCross(test)? "Yes" : "No") << std::endl<< std::endl; 
    }
    return 0;
}