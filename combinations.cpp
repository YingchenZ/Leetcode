#include <vector>
#include <iostream>

void combineHelper(int k, int num, int n, std::vector<int> choice, std::vector<std::vector<int>>& result){
    if(choice.size() == k){
        result.push_back(choice);
        choice = {};
        return;
    }
    for(int i = num; i <= n; i++){
        choice.push_back(i);
        combineHelper(k, i + 1, n, choice, result);
        choice.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<int> temp = {};
    std::vector<std::vector<int>> result = {};
    combineHelper(k, 1, n, temp, result);
    return result;
}

// n = 4 k = 2
// 1, 2
// 1, 3
// 1, 4
// 2, 3
// 2, 4
// 3, 4

// n = 1 k = 1
// 1

// n = 4 k = 3
// 1, 2, 3
// 1, 2, 4
// 1, 3, 4
// 2, 3, 4

int main(){
    std::vector<std::pair<int, int>> testSet = {{4,2}, {1,1}, {4,3}};
    for(auto test : testSet){
        std::vector<std::vector<int>> answerSet = combine(test.first, test.second);
        std::cout << "n = " << test.first << " k = " << test.second << std::endl;
        for(auto ans : answerSet){
            std::cout << ans[0];
            for(int i = 1; i < test.second; i++){
                std::cout << ", " << ans[i];
            }
            std::cout << std::endl;  
        }
        std::cout << std::endl; 
    }
    return 0;
}
