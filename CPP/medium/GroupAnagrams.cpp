#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    if(strs.empty())
        return {};
    if(strs.size() == 1){
        return {strs};
    }
    std::map<std::string, std::vector<std::string>> table = {};
    for(std::string str : strs){
        std::string copy = str;
        std::sort(copy.begin(), copy.end());
        if(table.count(copy) != 0)
            table[copy].push_back(str);
        else{
            table.insert(std::make_pair(copy, std::vector<std::string>{str}));
        }
    }
    std::vector<std::vector<std::string>> ans = {};
    std::map<std::string,std::vector<std::string>>::iterator strmap_iter2 = table.begin();
    for(;strmap_iter2 !=table.end();strmap_iter2++) {
        ans.push_back(strmap_iter2->second);
    }
    return ans;
}