#include <vector>
#include <string>
#include <iostream>

std::string convert(std::string s, int numRows) {
    std::vector<std::string> result = {};
    for(int i = 0; i < numRows; i++){
        std::string temp = "";
        result.push_back(temp);
    }
    int counter = 0, dir = -1;
    for(char c : s){
        result[counter] +=c;
        if(counter == numRows - 1 || counter == 0){
            dir = -dir;
        }
        counter += dir;
        if(counter < 0){
            counter = 0;
        }
        if(counter > numRows - 1){
            counter = numRows - 1;
        }

    }
    std::string ans = "";
    for(std::string str : result){
        ans += str;
    }
    return ans;
}

// Output: PINALSIGYAHRPI
int main(){
    std::string ans = convert("PAYPALISHIRING", 4);
    std::cout << ans << std::endl;
    return 0;
}
