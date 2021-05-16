#include <iostream>

int mySqrt(int x) {
    if(x <= 1)  return x;
    long long left = 1, right = x;
    long long mid = 0, possible = 0, temp = 0;
    while(left <= right){
        // find the medium
        mid = (left + right) / 2;
        temp = mid * mid;
        // the square of mid == x, we found the actual answer
        if(temp == x){
            return mid;
        }
        else if(temp > x){
            // if the square is larger than x
            // it means our mid is too large
            right = mid - 1;
        }
        else{
            // we found a possible answer
            // but the bigger our mid is, the more accurate answer it is
            possible = mid;
            // since it's smaller than x
            // increase the left bound to make mid larger
            left = mid + 1;
        }
    }
    return possible;
}

// Sqrt(1) = 1
// Sqrt(3) = 1
// Sqrt(4) = 2
// Sqrt(8) = 2
// Sqrt(17) = 4
// Sqrt(2147483647) = 46340

int main(){
    int testSet[] = {1,3,4,8,17,2147483647};
    for(int test : testSet){
        std::cout << "Sqrt(" << test << ") = "<< mySqrt(test) << std::endl;
    }
    return 0;
}