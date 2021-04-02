#include <unordered_map>
#include <utility>
#include <string>
#include <vector>
#include <iostream>

int romanToInt(std::string s) {
    int number = 0;
    std::unordered_map<char, int> table = {};
    table.insert(std::make_pair('I', 1));
    table.insert(std::make_pair('V', 5));
    table.insert(std::make_pair('X', 10));
    table.insert(std::make_pair('L', 50));
    table.insert(std::make_pair('C', 100));
    table.insert(std::make_pair('D', 500));
    table.insert(std::make_pair('M', 1000));

    for(int i = s.size() - 1; i >= 0; i--){
        int value = table[s[i]];
        if(i < s.size() - 1){
            int preVal = table[s[i + 1]];
            if(value == 1 && (preVal == 5 || preVal == 10)){
                number =(number - value);
            }
            else if (value == 10 && (preVal == 50 || preVal == 100)){
                number =(number - value);
            }
            else if (value == 100 && (preVal == 500 || preVal == 1000)){
                number =(number - value);
            }
            else{
                number += value;
            }
        }
        else{
            number += value;
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