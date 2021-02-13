#include <iostream>

double myMul(double x, int n){
    double current = (n == 0)? 1.0: myMul(x, n / 2);
    return current * current * (n % 2 == 0 ? 1: x);
}

double myPow(double x, int n) {
    if(n == 0){
        return 1.0;
    }
    if(n == 1){
        return x;
    }
    return n < 0? myMul(1/x, -n):myMul(x, n);
}
int main(){
    std::cout << "2^10 = " << myPow(2, 10) << std::endl;
    std::cout << "2^-10 = " << myPow(2, -10) << std::endl;
    std::cout << "2.1^3 = " << myPow(2.10000, 3) << std::endl;
    std::cout << "0.00000001^222222 = " << myPow(0.00000001, 222222) << std::endl;
    return 0;
}