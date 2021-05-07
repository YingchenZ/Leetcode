#include <vector>
#include <algorithm>
#include <iostream>

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    std::sort(coins.begin(), coins.end());
    dp[0] = 0;
    for(int i = 1; i <= amount; i++){
        for(int coin : coins){
            if(coin > i){
                break;
            }
            dp[i] = std::min(dp[i], 1 + dp[i - coin]);
        }
    }

    return dp[amount] > amount? -1 : dp[amount];
}

// The fewest number of coins that you need to make up that amount = -1

// coins = {1}     amount = 0
// The fewest number of coins that you need to make up that amount = 0

// coins = {1}     amount = 1
// The fewest number of coins that you need to make up that amount = 1

// coins = {1}     amount = 2
// The fewest number of coins that you need to make up that amount = 2

// coins = {1,2,5} amount = 11
// The fewest number of coins that you need to make up that amount = 3

int main(){
    std::vector<std::pair<std::vector<int>, int>> testSet = {
        {{2},3},
        {{1},0},
        {{1},1},
        {{1},2},
        {{1,2,5},11}
    };

    for(auto test : testSet){
        std::vector<int> coins = test.first;
        int amount = test.second;
        std::cout << "coins = {";
        for(int i = 0; i < coins.size(); i++){
            std::cout << coins[i] << (i == (coins.size() - 1)? "}\t":",");
        }
        std::cout << "amount = " << amount << std::endl;
        std::cout << "The fewest number of coins that you need to make up that amount = " << coinChange(coins, amount) << std::endl << std::endl;
    }

    return 0;
}