#include <string>
#include <vector>
#include <iostream>

int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
    int row = text1.size(), col = text2.size();
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(text1[i] == text2[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else{
                dp[i + 1][j + 1] = std::max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    
    return dp[row][col];
}

// text1 = abcde   text2 = ace     Length of the longest common subsequence = 3
// text1 = abc     text2 = abc     Length of the longest common subsequence = 3
// text1 = abc     text2 = de      Length of the longest common subsequence = 0
// text1 = bsbininm        text2 = jmjkbkjkv       Length of the longest common subsequence = 1

int main(){
    std::vector<std::vector<std::string>> testSet = {
        {"abcde","ace"},
        {"abc","abc"},
        {"abc", "de"},
        {"bsbininm", "jmjkbkjkv"}
    };

    for(auto test : testSet){
        std::cout << "text1 = " << test[0] << "\ttext2 = " << test[1] << "\tLength of the longest common subsequence = " << longestCommonSubsequence(test[0],test[1]) << std::endl;
    }
    return 0;
}