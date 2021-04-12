#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

static bool cmp( std::string& lhs,  std::string& rhs){
    return lhs+rhs > rhs + lhs;
}

std::string largestNumber(std::vector<int>& nums) {
    if(nums.size() == 1) return std::to_string(nums[0]);
    std::vector<std::string> strNum = {};
    for(int num : nums){
        strNum.push_back(std::to_string(num));
    }
    std::string ans = "";
    std::sort(strNum.begin(), strNum.end(), cmp);
    for(std::string str : strNum){
        if(str == "0" && ans.size() == 0) continue;
        ans += str;
    }
    return ans.size() == 0? "0":ans;
}

// List = {0}      => Largest Number = 0
// List = {1}      => Largest Number = 1
// List = {10}     => Largest Number = 10
// List = {999999991,9}    => Largest Number = 9999999991
// List = {1,2,3,4,5,6,7,8,9,0}    => Largest Number = 9876543210

int main(){
    std::vector<std::vector<int>> testSet = {
        {0},{1},{10},{999999991,9},{1,2,3,4,5,6,7,8,9,0}
    };

    for(std::vector<int> test : testSet){
        std::cout << "List = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << ((i == (test.size() -1)) ? "": ",");
        }
        std::cout << "}\t=> Largest Number = " << largestNumber(test)<< std::endl;
    }
    return 0;
}