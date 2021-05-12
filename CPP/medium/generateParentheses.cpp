#include <string>
#include <vector>
#include <iostream>

void generate(std::vector<std::string>& ans, int open, int close, std::string current, int n){
    if(open == n && close == n){
        ans.push_back(current);
        return;
    }
    if(open < n){
        current += '(';
        generate(ans, open + 1, close, current, n);
        current.pop_back();
    }
    if(close < open){
        current += ')';
        generate(ans, open, close + 1, current, n);
        current.pop_back();
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans = {};
    generate(ans, 0, 0,"",n);
    return ans;
}

// Combinations of Well-formed Parentheses When n = 1
// {()}

// Combinations of Well-formed Parentheses When n = 2
// {(()),()()}

// Combinations of Well-formed Parentheses When n = 3
// {((())),(()()),(())(),()(()),()()()}

int main(){
    std::vector<int> testSet = {1,2,3};
    for(int test : testSet){
        std::cout << "Combinations of Well-formed Parentheses When n = " << test<< std::endl;
        std::vector<std::string> ans = generateParenthesis(test);
        std::cout << "{";
        for(int i = 0; i < ans.size(); i++){
            std::cout << ans[i] << (i == ans.size() - 1? "}\n":",");
        }
        std::cout << std::endl;
    }
    return 0;
}