#include <iostream>
#include <unordered_map>
int lengthOfLongestSubstring(std::string s) {
    if(s.size() == 0 || s.size() == 1){
        return s.size();
    }
    std::unordered_map<char, int> table;
    int start = 0, big = 0, sofar = 0;
    for(int end = 0; end < s.size(); end++){
        if(!table.count(s[end])){
            table.insert(std::make_pair(s[end], 1));
            sofar++;
        }
        else if(!table[s[end]]){
            table[s[end]] = 1;
            sofar++;
        }
        else{
            sofar = end - start;
            big = sofar > big? sofar : big;
            while(table[s[end]]){
                table[s[start]] = 0;
                sofar--;
                start++;
            }
            table[s[end]] = 1;
            sofar++;
        }
    }
    big = sofar > big? sofar : big;

    return big;
}


// "uqinntq"    4
// "dvdf"       3
// "pwwkew"     3
// "au"         2
// "abba"       2
// "abcadcbb"   4
int main(){
    std::cout <<"uqinntq =>"<< lengthOfLongestSubstring("uqinntq")<< std::endl;
    std::cout <<"dvdf =>"<< lengthOfLongestSubstring("dvdf")<< std::endl;
    std::cout <<"pwwkew =>"<< lengthOfLongestSubstring("pwwkew")<< std::endl;
    std::cout <<"au =>"<< lengthOfLongestSubstring("au")<< std::endl;
    std::cout <<"abba =>"<< lengthOfLongestSubstring("abba")<< std::endl;
    std::cout <<"abcadcbb =>"<< lengthOfLongestSubstring("abcadcbb")<< std::endl;
    return 0;
}