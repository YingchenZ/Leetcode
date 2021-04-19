#include <vector>
#include <iostream>

int removeElement(std::vector<int>& nums, int val) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1 && nums[0] == val) return 0;

    int slow = 0, fast = 0, n = nums.size();
    while(fast < n){
        if(nums[fast] == val){
            fast++;
            continue;
        }

        nums[slow] = nums[fast];
        slow++;
        fast++;
    }
    return slow;
}

struct TestHolder{
    std::vector<int> nums;
    int val;
    TestHolder(std::vector<int> nums, int val){
        this->nums = nums;
        this->val = val;
    }
};

// Before = {3,2,2,3}      Want to delete 3
// After  = {2,2}

// Before = {0,1,2,2,3,0,4,2}      Want to delete 0
// After  = {1,2,2,3,4,2}

// Before = {0,1,2,2,3,0,4,2}      Want to delete 1
// After  = {0,2,2,3,0,4,2}

// Before = {0,1,2,2,3,0,4,2}      Want to delete 2
// After  = {0,1,3,0,4}

// Before = {0,1,2,2,3,0,4,2}      Want to delete 4
// After  = {0,1,2,2,3,0,2}

int main(){
    TestHolder test({3,2,2,3}, 3);
    std::vector<TestHolder> testSet = {
        TestHolder ({3,2,2,3}, 3),
        TestHolder ({0,1,2,2,3,0,4,2}, 0),
        TestHolder ({0,1,2,2,3,0,4,2}, 1),
        TestHolder ({0,1,2,2,3,0,4,2}, 2),
        TestHolder ({0,1,2,2,3,0,4,2}, 4)
    };
    for(TestHolder test : testSet){
        std::cout << "Before = {";
        for(int i = 0; i < test.nums.size(); i++){
            std::cout << test.nums[i] << (i == (test.nums.size() - 1)? "}\t":",");
        }
        std::cout << "Want to delete " << test.val << std::endl;
        int s = removeElement(test.nums, test.val);
        std::cout << "After  = {";
        for(int i = 0; i < s; i++){
            std::cout << test.nums[i] << (i == (s - 1)? "}\n\n":",");
        }
    }
    return 0;
}