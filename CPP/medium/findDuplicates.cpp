#include <vector>
#include <iostream>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> ans = {};
    const unsigned N = nums.size();
    for(const int& curr : nums){
        if(nums[std::abs(curr) - 1] > 0){
            nums[std::abs(curr) - 1] = -nums[std::abs(curr) - 1];
        }
        else{
            ans.push_back(std::abs(curr));
        }
    }
    return ans;
}

void print(const std::vector<int>& arr){
    std::cout << "{";
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << (i == arr.size() - 1? "}":",");
    }
}

// test = {10,2,5,10,9,1,1,4,3,7}
// Duplicate Numbers = {10,1}

// test = {4,3,2,7,8,2,3,1}
// Duplicate Numbers = {2,3}

int main(){
	std::vector<std::vector<int>> testSuite = {
		{10,2,5,10,9,1,1,4,3,7},
		{4,3,2,7,8,2,3,1}
	};

	for(std::vector<int>& test : testSuite){
		std::cout << "test = ";
		print(test);
		std::cout << "\nDuplicate Numbers = ";
		std::vector<int> ans = findDuplicates(test);
		print(ans);
		std::cout << "\n\n";
	}

	return 0;
}
