#include <vector>
#include <queue>
#include <string>
#include <iostream>

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> table = {"","","abc","def","ghi","jkl","mno", "pqrs","tuv", "wxyz"};
    std::vector<std::string> result = {};
    std::queue<std::string> combList = {};
    combList.push("");
    for(int i = 0; i < digits.size(); i++){
        std::string possibleComb = table[digits[i] - '0'];
        while(combList.front().size() == i){
            std::string current = combList.front();

            combList.pop();
            for(char c : possibleComb){
                if(current.size() + 1 == digits.size()){
                    result.push_back(current + c);
                }
                combList.push(current + c);
            }
        }
    }
    return result;
}

// Digits = 2
// Possible Letter Combinations = {a,b,c}

// Digits = 23
// Possible Letter Combinations = {ad,ae,af,bd,be,bf,cd,ce,cf}

// Digits = 34
// Possible Letter Combinations = {dg,dh,di,eg,eh,ei,fg,fh,fi}

int main(){
    std::vector<std::string> testSet = {"2", "23", "34"};

    for(std::string test : testSet){
        std::cout << "Digits = " << test << std::endl;
        std::cout << "Possible Letter Combinations = {";
        std::vector<std::string> ans = letterCombinations(test);
        for(int i = 0; i < ans.size(); i++){
            std::cout << ans[i] << (i == (ans.size() - 1)? "}\n":",");
        }
        std::cout << std::endl;
    }

    return 0;
}