#include <vector>
#include <set>
#include <utility>
#include <iostream>

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
    std::set<int> temp = {};
    for(int i = 0; i < nums.size(); i++){
        // if nums[i] >= INT_MIN, then target will be INT_MIN
        // Otherwise target = nums[i] - t
        int target = std::max(nums[i], INT_MIN + t) - t;
        auto lower = temp.lower_bound(target);

        // if t == INT_MAX, then lower should be less than INT_MAX
        // Otherwise lower should be less than nums[i] + t since lower - nums[i] <= t
        if(lower != temp.end() && *lower <= (std::min(nums[i], INT_MAX-t) + t)) return true;

        temp.insert(nums[i]);

        if(i >= k){
            temp.erase(nums[i - k]);
        }

    }
    return false;
}

class testHolder{
public:
    testHolder(std::vector<int> nums, int k, int t){
        this->nums = nums;
        this->k = k;
        this->t = t;
    }

    std::vector<int> getNums(){
        return nums;
    }

    int getK(){
        return k;
    }
    int getT(){
        return t;
    }
private:
    std::vector<int> nums;
    int k;
    int t;
};

// nums = {-2147483648,2147483647} k = 1 t = 1     Result: not found
// nums = {2147483640,2147483641}  k = 1 t = 100   Result: found
// nums = {-2147483640,-2147483641}        k = 1 t = 100   Result: found
// nums = {1,2,3,1}        k = 3 t = 0     Result: found
// nums = {1,0,1,1}        k = 1 t = 2     Result: found
// nums = {1,5,9,1,5,9}    k = 2 t = 3     Result: not found

int main(){

    std::vector<testHolder> testSet = {
        testHolder(std::vector<int>{-2147483648,2147483647},1,1),
        testHolder(std::vector<int>{2147483640,2147483641},1,100),
        testHolder(std::vector<int>{-2147483640,-2147483641},1,100),
        testHolder(std::vector<int>{1,2,3,1},3,0),
        testHolder(std::vector<int>{1,0,1,1},1,2),
        testHolder(std::vector<int>{1,5,9,1,5,9},2,3)
    };

    for(auto test : testSet){
        std::vector<int> nums = test.getNums();
        int k = test.getK();
        int t = test.getT();
        std::cout << "nums = {";
        for(int i = 0; i < nums.size(); i++){
            std::cout << nums[i] << (i == (nums.size() - 1)? "}\t": ",");
        }
        std::cout << "k = " << k << " t = "<< t << "\tResult: "<<(containsNearbyAlmostDuplicate(nums,k,t)?"":"not ")<<"found"<< std::endl;
    }
    return 0;
}