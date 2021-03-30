#include <string>
#include <vector>
#include <iostream>

std::string longestCommonPrefix(std::vector<std::string> strs) {
    if(strs.size() == 0) return "";
    if(strs.size() == 1) return strs[0];
    int index = 0;
    int minStr = 999;
    int shortest = 0;
    for(int i = 0; i < strs.size(); i++){
        if(strs.size() < minStr){
            shortest = i;
            minStr = strs.size();
        }
    }
    
    if(shortest != -1 && strs[shortest].size() == 0){
        return strs[shortest];
    } 

    std::string prefix = "";

    
    while(index < strs[shortest].size()){
        int counter = 1;
        for(int i = 1; i < strs.size(); i++){
            if(strs[0][index] == strs[i][index]){
                counter++;
            }
        }
        if(counter != strs.size()) return prefix;
        prefix += strs[0][index];
        index++;
    }
    return prefix;
}

// The longest common prefix for"flower,flower,flower,flower" => flower
// The longest common prefix for"flower,flow,flight" => fl
// The longest common prefix for"dog,racecar,car" =>

int main(){
    std::vector<std::vector<std::string>> testSet = {
        {"flower","flower","flower","flower"},
        {"flower","flow","flight"},
        {"dog","racecar","car"}
    };
    for(auto test : testSet){
        std::cout << "The longest common prefix for\"";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() -1) ? "\" => ":",");
        }
        std::cout << longestCommonPrefix(test)<< std::endl;
    }
    return 0;
}