#include <string>
#include <vector>
#include <iostream>

int longestPalindromeSubseq(std::string s) {
    std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(s.size() + 1, 0));
    
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp.size(); j++){
            if(s[i - 1] == s[s.size() -j ]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[s.size()][s.size()];
}

// s = bbbab       Length of the Longest Palindromic Subsequence = 4

// s = cbbd        Length of the Longest Palindromic Subsequence = 2

// s = agbdba      Length of the Longest Palindromic Subsequence = 5

int main(){
    std::vector<std::string> testSet = {"bbbab","cbbd","agbdba"};
    for(std::string test : testSet){
        std::cout << "s = " << test << "\tLength of the Longest Palindromic Subsequence = " << longestPalindromeSubseq(test) << std::endl << std::endl;
    }
    return 0;
}