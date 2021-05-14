#include <string>
#include <vector>
#include <iostream>

std::string intToRoman(int num) {
    std::string roman = "";
    std::vector<std::string> one = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    std::vector<std::string> ten = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    std::vector<std::string> hundred = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    std::vector<std::string> thousand = {"", "M", "MM", "MMM"};

    int o = num % 10;
    num /= 10;
    int t = num % 10;
    num /= 10;
    int h = num % 10;
    num /= 10;
    int th = num % 10;
    return thousand[th] + hundred[h] + ten[t] + one[o];
}

// num = 3 Roman = III
// num = 4 Roman = IV
// num = 9 Roman = IX
// num = 1994      Roman = MCMXCIV
// num = 2030      Roman = MMXXX
// num = 3985      Roman = MMMCMLXXXV

int main(){
    std::vector<int> testSet = {3,4,9, 1994, 2030, 3985};
    for(int test : testSet){
        std::cout << "num = " << test << "\tRoman = " << intToRoman(test) << std::endl;
    }
    return 0;
}