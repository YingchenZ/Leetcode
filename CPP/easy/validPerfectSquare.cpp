#include <vector>
#include <iostream>

bool isPerfectSquare(int num) {
    long long left = 1, right = num;
    long long mid = 1;
    while(left <= right){
        mid = (left + right) / 2;
        if(mid * mid == num){
            return true;
        }
        else if(mid * mid > num){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return false;
}

// 1       Perfect Square
// 14      Not Perfect Square
// 15      Not Perfect Square
// 16      Perfect Square
// 20      Not Perfect Square
// 100     Perfect Square
// 2147483647      Not Perfect Square

int main(){
    std::vector<int> testSet = {1,14,15,16,20,100,2147483647};
    for(int test : testSet){
        std::cout << test << '\t' << (isPerfectSquare(test)?"Perfect Square":"Not Perfect Square") << std::endl;
    }
    return 0;
}