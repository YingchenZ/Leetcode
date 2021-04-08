#include <iostream>
#include <cmath>
#include <vector>


int divide(int dividend, int divisor) {
    if(dividend == 0) return 0;
    if(dividend == -2147483648 && divisor == -1) return 2147483647;
    
    
    long long nominator = std::llabs(dividend);
    long long denominator = std::llabs(divisor);
    long long answer = 0;
    while(nominator - denominator >= 0){
        int x = 0;
        while(nominator - (denominator << 1 << x) >= 0){
            x++;
        }
        answer += 1 << x;
        nominator -= (denominator << x);
    }
    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        return - 1 * answer;
    return answer;
}

// -2147483648 / -3 = 715827882
// -2147483648 / 1 = -2147483648
// -2147483648 / -1 = 2147483647
// 10 / 3 = 3
// 1 / 1 = 1
// 0 / 1 = 0
// 7 / -3 = -2

int main(){
    std::vector<std::pair<long, long>> testSet = {
        {-2147483648, -3},  {-2147483648, 1},
        {-2147483648, -1},
        {10, 3}, {1, 1}, {0, 1}, {7, -3}
    };
    for(int i = 0; i < testSet.size(); i++){
        std::cout << testSet[i].first << " / "<< testSet[i].second <<" = "<< divide(testSet[i].first, testSet[i].second) << std::endl;
    }
    return 0;
}