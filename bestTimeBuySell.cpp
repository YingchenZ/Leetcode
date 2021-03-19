#include <vector>
#include <iostream>

int maxProfit(std::vector<int>& prices) {
    int profit = 0, buy = 0, sell = 0, temp = 0;
    while(sell < prices.size() && buy < prices.size()){
        temp = prices[sell] - prices[buy];
        if(profit < temp) profit = temp;
        
        if(prices[sell] < prices[buy]){
            buy = sell;
        }
        sell++;

    }
    return profit;
}

// Test is  7 1 5 3 6 4
// MaxProfit = 5
// Test is  7 6 4 3 1
// MaxProfit = 0

int main(){
    std::vector<std::vector<int>> testSet = {
        {7,1,5,3,6,4},
        {7,6,4,3,1}
    };
    for(std::vector<int> test : testSet){
        std::cout << "Test is ";
        for(auto price : test){
            std::cout << " "<<price; 
        }
        std::cout << "\nMaxProfit = " << maxProfit(test) << std::endl;
    }
    return 0;
}