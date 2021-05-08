#include <vector>
#include <string>
#include <iostream>

std::vector<int> getPalindrome(std::string s, int start, int end){
    while(start >= 0 && end < s.size() && s[start] == s[end]){
        start--;
        end++;
    }
    
    return {start + 1, end - 1};
}

std::string longestPalindrome(std::string s) {
    if(s.size() <= 1) return s;

    int start = 0, end = 0;

    for(int i = 0; i < s.size(); i++){
        // for palindrom with odd length
        std::vector<int> oddLen = getPalindrome(s, i, i);
        // for palindrom with an even length
        std::vector<int> evenLen = getPalindrome(s, i, i+1);
    
        if(oddLen[1] - oddLen[0] > (end - start)){
            start = oddLen[0];
            end = oddLen[1];
        }
        if(evenLen[1] - evenLen[0] > (end - start)){
            start = evenLen[0];
            end = evenLen[1];
        }
    }

    return s.substr(start, end - start + 1);
}

// s = a   Longest Palindromic Substring = a
// s = ac  Longest Palindromic Substring = a
// s = cbbd        Longest Palindromic Substring = bb
// s = babad       Longest Palindromic Substring = bab

int main(){
    std::vector<std::string> testSet = {"a", "ac", "cbbd","babad"};
    for(std::string test : testSet){
        std::cout << "s = " << test << "\tLongest Palindromic Substring = " << longestPalindrome(test)<< std::endl;
    }

    return 0;
}