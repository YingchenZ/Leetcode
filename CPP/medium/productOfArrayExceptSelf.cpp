#include <vector>
#include <iostream>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> ans(nums.size(),1);

    // get prefix for each block
    ans[1] = nums[0];
    for(int i = 2; i < nums.size(); i++){
        // prefix for i = the prefix of i - 1 * the num of i - 1
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int postfix = nums[nums.size() - 1];
    for(int i = nums.size() - 2; i >= 0; i--){
        ans[i] *= postfix;
        // update the postfix by including the current num
        // it will become i - 1's postfix
        postfix *= nums[i];
    }
    return ans;

}

void printArray(std::vector<int>& arr){
    std::cout << "{";
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << (i == arr.size() - 1? "}":", ");
    }
    std::cout << std::endl;
}

// nums = {1, 2, 3, 4}
// Ans = {24, 12, 8, 6}

// nums = {-1, 1, 0, -3, 3}
// Ans = {0, 0, 9, 0, 0}

int main(){
    std::vector<std::vector<int>> testSet = {
        {1,2,3,4},
        {-1,1,0,-3,3}
    };
    
    for(auto& test : testSet){
        std::cout << "nums = ";
        printArray(test);
        std::vector<int> ans = productExceptSelf(test);
        std::cout << "Ans = ";
        printArray(ans);
        std::cout << std::endl;
    }


    return 0;
}