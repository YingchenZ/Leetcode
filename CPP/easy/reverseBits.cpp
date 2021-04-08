#define ll long long
#include <iostream>

uint32_t reverseBits(uint32_t n) {
    int result  = 0;

    for(int i = 0; i < 32; i++){
        int newBit = n & 1;
        n >>= 1;
        result <<= 1;
        result = result | newBit;
    }
    return result;
}

// Test = 43261596 After reversed = 964176192
// Test = 4294967293 After reversed = 3221225471

int main(){
    ll test[] = {43261596, 4294967293};

    for(auto num : test){
        std::cout << "Test = "<< num << " After reversed = "<< reverseBits(num) << std::endl;
    }
    return 0;

}