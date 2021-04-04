#include <vector>
#include <cmath>
#include <string>
#include <iostream>
int myAtoi(std::string s) {
    if(s.size() == 0) return 0;
    int startIndex = 0;
    while(s[startIndex] && s[startIndex] == ' '){
        startIndex++;
    }
    long long num = 0;
    if(startIndex > s.size() - 1) return 0;
    bool negative = false;
    if(s[startIndex] == '-'){
        negative = true;
        startIndex++;
    }
    else if(s[startIndex] == '+'){
        startIndex++;
    }

    int firstNonZero = -1;        
    int numLength = 0;
    for(int i = startIndex; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            if(firstNonZero == -1 && s[i] != '0') firstNonZero= i;
            numLength++;
        }
        else{
            break;
        }
    }
    if(firstNonZero != -1 && (numLength - firstNonZero) > 10){
        return negative? INT_MIN : INT_MAX;
    } 

    for(int i = 0; i < numLength; i++){
        num += (s[i + startIndex] - '0') * std::pow(10, numLength - i - 1);
    }
    
    if(num > INT_MAX && negative) return INT_MIN;
    if(num > INT_MAX && !negative) return INT_MAX;
    return negative? (-1 * num) : num;
}

// Test String = "1" => After myAtoi = 1
// Test String = "-9128347233222222222222222222222222222222222222222" => After myAtoi = -2147483648
// Test String = "-2147483648" => After myAtoi = -2147483648
// Test String = "-2147483647" => After myAtoi = -2147483647
// Test String = "+-12" => After myAtoi = 0
// Test String = "-42 with words" => After myAtoi = -42
// Test String = "-444444444" => After myAtoi = -444444444
// Test String = "               +42" => After myAtoi = 42
// Test String = "   -42" => After myAtoi = -42
// Test String = "  0000000000012345678" => After myAtoi = 12345678
// Test String = "00000-42a1234" => After myAtoi = 0
// Test String = "3.1416" => After myAtoi = 3
// Test String = "  -0012a42" => After myAtoi = -12
// Test String = "   +0 123" => After myAtoi = 0

int main(){
    std::vector<std::string> testSet = {
        "1","-9128347233222222222222222222222222222222222222222","-2147483648",
        "-2147483647","+-12","-42 with words","-444444444","               +42",
        "   -42","  0000000000012345678","00000-42a1234","3.1416","  -0012a42","   +0 123"
    };

    for(std::string test : testSet){
        std::cout << "Test String = \"" << test << "\" => After myAtoi = "<< myAtoi(test)<< std::endl;
    }
    return 0;
}