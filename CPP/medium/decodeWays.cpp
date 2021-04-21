#include <string>
#include <vector>
#include <iostream>

int numDecodings(std::string s) {
    if(s.size() != 0 && s[0] == '0') return 0;
    if(s.size() == 1) return 1;

    int dp[s.size() + 1];
    dp[0] = 1;
    dp[1] = 1;
    int zero = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '0'){
            if(s[i - 1] == '0' || s[i - 1] > '2') return 0;
            //   1 1 1 0 6
            // 1 1 2 3 2 2
            if(s[i - 1] <= '2') dp[i + 1] = dp[i - 1];
        }
        else{
            if(s[i] <= '6' && s[i - 1] > '0' && s[i - 1] <='2'){
                dp[i + 1] = dp[i] + dp[i - 1];
            }
            else if(s[i] > '6' && s[i - 1] == '1'){
                dp[i + 1] = dp[i] + dp[i - 1];
            }
            else{
                dp[i + 1] = dp[i];
            }
        }
    }

    return dp[s.size()];
}

// Code = "12"      Ways to decode = 2
// Code = "27"      Ways to decode = 1
// Code = "111"     Ways to decode = 3
// Code = "1000"    Ways to decode = 0
// Code = "1001"    Ways to decode = 0
// Code = "111026"  Ways to decode = 4
// Code = "2611055971756562"        Ways to decode = 4

int main(){
    std::vector<std::string> testSet = {
        "12", "27",
        "111",
        "1000", "1001",
        "111026",
        "2611055971756562"
    };

    for(std::string test : testSet){
        std::cout << "Code = \""<< test << "\"\t Ways to decode = " << numDecodings(test) << std::endl;
    }
    return 0;
}