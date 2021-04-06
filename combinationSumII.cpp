#include <vector>
#include <algorithm>
#include <iostream>
void combineHelper(int target, int start, std::vector<int>candidates, std::vector<int> choice, std::vector<std::vector<int>>& result){
    if(target == 0){
        result.push_back(choice);
        return;
    }
    if(target < 0){
        return;
    }
    
    for(int i = start; i < candidates.size(); i++){
        if(i != start && candidates[i] == candidates[i - 1]) continue;
    
        choice.push_back(candidates[i]);
        combineHelper(target - candidates[i], i + 1, candidates, choice, result);
        
        choice.pop_back();
    
        if(i != candidates.size() - 1 && target < candidates[i + 1]){
            return;
        }  
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<int> temp = {};
    std::vector<std::vector<int>> result = {};
    std::sort(candidates.begin(), candidates.end());
    combineHelper(target,0, candidates, temp, result);
    return result;
}

// Test array   => {2,5,2,1,2}  Target = 5
// Combinations => {1,2,2}, {5}

// Test array   => {10,1,2,7,6,1,5}  Target = 8
// Combinations => {1,1,6}, {1,2,5}, {1,7}, {2,6}

int main(){
    std::vector<std::pair<std::vector<int>, int>> testSet = {
        {{2,5,2,1,2},5},  {{10,1,2,7,6,1,5},8}
    };
    for(auto test : testSet){
        std::cout << "Test array   => {";
        for(int i = 0; i < test.first.size(); i++){
            std::cout << test.first[i] << (i == (test.first.size() - 1)? "}":",");
        }
        std::cout << "  Target = "<< test.second << std::endl;
        std::vector<std::vector<int>> answerSet = combinationSum2(test.first, test.second);
        std::cout << "Combinations =>";
        if(answerSet.size() == 0) std::cout << " {}";
        for(int i = 0; i < answerSet.size(); i++){
            std::cout << " {";
            for(int j = 0; j < answerSet[i].size(); j++){
                std::cout << answerSet[i][j] << (j == (answerSet[i].size() - 1)? "}":",");
            }
            std::cout << (i == (answerSet.size() - 1)? "":",");
        }
        std::cout << std::endl <<std::endl; 
    }
    return 0;
}