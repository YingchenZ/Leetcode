#include <vector>
#include <iostream>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> ans(2, 0);
    int left, right, mid;
    for(int i = 0; i < numbers.size(); i++){
        ans[0] = i + 1;
        int second = target - numbers[i];
        if(second >= numbers[i]){
            left = (numbers.size() - 1) == i? (numbers.size() - 1):(i + 1);
            right = numbers.size() - 1;
        }
        else{
            left = 0;
            right = std::max(0, i - 1);
        }
        
        while(left <= right){
            mid = (left + right) / 2;
            if(numbers[mid] == second){
                ans[1] = mid + 1;
                return ans;
            }
            else if(numbers[mid] > second){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
    }
    return ans;
}

struct TestHolder{
    int target; 
    std::vector<int> numbers;
    TestHolder(int x, std::vector<int> a) : target(x), numbers(a){};
};

// numbers = {2,7,11,15}   Target = 9
// Result = {1, 2}

// numbers = {2,3,4}       Target = 6
// Result = {1, 3}

// numbers = {-1,0}        Target = -1
// Result = {1, 2}

// numbers = {0,0,3,4}     Target = 0
// Result = {1, 2}

int main(){
    TestHolder* testSet[] = {
        new TestHolder(9, {2,7,11,15}),
        new TestHolder(6, {2,3,4}),
        new TestHolder(-1, {-1, 0}),
        new TestHolder(0, {0,0,3,4})
    };

    for(auto test : testSet){
        std::cout << "numbers = {";
        for(int i = 0; i < test->numbers.size(); i++){
            std::cout << test->numbers[i] << (i == (test->numbers.size() - 1)? "":",");
        }
        std::cout << "}\tTarget = " << test->target << std::endl;

        std::vector<int> ans = twoSum(test->numbers, test->target);
        std::cout << "Result = {" << ans[0]<< ", "<< ans[1] << "}"<< std::endl << std::endl;
    }
    return 0;
}