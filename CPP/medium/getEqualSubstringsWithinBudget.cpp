#include <string>
#include <iostream>

int equalSubstring(std::string s, std::string t, int maxCost) {
    int slow = 0, fast = 0;
    int maxLen = 0;

    while(slow < s.size() && fast < s.size()){

        maxCost -= std::abs(s[fast] - t[fast]);
        // if maxCost == 0
        // update the maxLen (if the next char in s and t are the same, it will still be updated)
        if(maxCost == 0){
            maxLen = std::max(maxLen , fast - slow + 1);
        }
        // if maxCost < 0
        // use the previous fast pointer to update the maxLen
        if(maxCost < 0){
            maxLen = std::max(maxLen , (fast - 1 - slow) + 1);
            maxCost += std::abs(s[slow] - t[slow]);
            slow++;
        }
        
        fast++;
    }
    // if maxCost >= 0
    // update the maxLen again to make sure the answer of the last sliding window is covered
    // using fast - 1 to avoid "index out of the range"
    if(maxCost >= 0){
        maxLen = std::max(maxLen , fast - 1 - slow + 1);
    }
    return maxLen;
}

struct TestHolder{
    std::string s;
    std::string t;
    int maxCost;

    TestHolder(std::string str1, std::string str2, int cost) : s(str1), t(str2), maxCost(cost){};
};

// s = "abcd"      t = "acde"      maxCost = 0
// The Max Length of a Substring of s = 1

// s = "abcd"      t = "bcdf"      maxCost = 3
// The Max Length of a Substring of s = 3

// s = "abcd"      t = "cdef"      maxCost = 3
// The Max Length of a Substring of s = 1

// s = "jzmhzdq"   t = "rymuemg"   maxCost = 17
// The Max Length of a Substring of s = 3

// s = "tyiraojpcfuttwblehv"       t = "stbtakjkampohttraky"       maxCost = 119
// The Max Length of a Substring of s = 19

int main(){
    TestHolder* testSet[] = {
        new TestHolder("abcd","acde", 0),
        new TestHolder("abcd","bcdf", 3),
        new TestHolder("abcd","cdef", 3),
        new TestHolder("jzmhzdq","rymuemg", 17),
        new TestHolder("tyiraojpcfuttwblehv","stbtakjkampohttraky", 119)
    };

    for(TestHolder* test : testSet){
        std::cout << "s = \""<< test->s << "\"\tt = \""<< test->t << "\"\tmaxCost = "<< test->maxCost << std::endl;
        std::cout << "The Max Length of a Substring of s = "<< equalSubstring(test->s, test->t, test->maxCost) << std::endl << std::endl;
    }
    return 0;
}