#include <string>
#include <vector>
#include <iostream>

int getVal(char n){
    if(n == 'I')    return 1;
    if(n == 'V')    return 5;
    if(n == 'X')    return 10;
    if(n == 'L')    return 50;
    if(n == 'C')    return 100;
    if(n == 'D')    return 500;
    if(n == 'M')    return 1000;
    return 0;
}

int romanToInt(std::string s) {
    int number = getVal(s[s.size() - 1]);
    // memorize the previous bigger val
    int preVal = number;
    for(int i = s.size() - 2; i >= 0; i--){
        int current = getVal(s[i]);
        // if the current position is less than the previous val
        // Encountering with case like IV, XC...
        // subtract the correspoinding value
        if(current < preVal){
            number -= current;
        }
        else{
            number += current;
            // this is a brand-new big val
            preVal = current;
        }
        
    }
    
    return number;
}

// Roman = "MCMXCIV" => Integer = 1994
// Roman = "LVIII" => Integer = 58
// Roman = "CD" => Integer = 400

int main(){
    std::vector<std::string> testSet = {"MCMXCIV", "LVIII", "CD"};

    for(auto test : testSet){
        std::cout << "Roman = \""<< test << "\" => Integer = "<< romanToInt(test) << std::endl; 
    }
    return 0;
}