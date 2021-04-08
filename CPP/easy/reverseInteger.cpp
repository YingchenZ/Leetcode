#include <vector>
#include <iostream>

int reverse(int x) {
    double ans = 0;
    if(x < -2147483648 || x > 2147483648)
        return 0;

    while(x != 0){
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return (ans <= -2147483648 || ans >= 2147483648) ? 0 : ans;
}

int main(){
    std::vector<int> test = {123, -123, 0};
    for(int num : test){
        std::cout<< num << " => " << reverse(num) << std::endl;
    }
    return 0;    
}