#include <iostream>
#include <vector>

int hammingWeight(uint32_t n) {
    int result = 0;
    while(n){
        result += (n & 1);
        n >>= 1;
    }
    return result;
}

// 521     Num of 1 Bits = 3
// 2097152 Num of 1 Bits = 1

int main(){
    std::vector<uint32_t> testSet = {
        00000000000000000000000000001011,
        00000000000000000000000010000000
    };

    for(auto test : testSet){
        std::cout << test << "\tNum of 1 Bits = " << hammingWeight(test) << std::endl;
    }

    return 0;
}