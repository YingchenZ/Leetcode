import java.util.*;

class Solution {
    private static class TestHolder{
        public String s;
        public String t;
        public int maxCost;
        public TestHolder(String s, String t, int maxCost){
            this.s = s;
            this.t = t;
            this.maxCost = maxCost;
        } 
    };
    public static int equalSubstring(String s, String t, int maxCost) {
        int slow = 0, fast = 0;
        int maxLen = 0;
        while(slow < s.length() && fast < s.length()){
            maxCost -= Math.abs(s.charAt(fast) - t.charAt(fast));
            if(maxCost == 0){
                maxLen = Math.max(maxLen, fast - slow + 1);
            }
            if(maxCost < 0){
                maxLen = Math.max(maxLen, fast - 1 - slow + 1);
                maxCost += Math.abs(s.charAt(slow) - t.charAt(slow));
                slow++;
            }
            fast++;
        }
        if(maxCost >= 0){
            maxLen = Math.max(maxLen, fast - 1 - slow + 1);
        }
        return maxLen;
    }

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

    public static void main(String[] args){
        TestHolder[] testSet = new TestHolder[]{
            new TestHolder("abcd","acde", 0),
            new TestHolder("abcd","bcdf", 3),
            new TestHolder("abcd","cdef", 3),
            new TestHolder("jzmhzdq","rymuemg", 17),
            new TestHolder("tyiraojpcfuttwblehv","stbtakjkampohttraky", 119)
        };
        for(TestHolder test : testSet){
            System.out.println("s = \"" + test.s + "\"\tt = \"" + test.t  + "\"\tmaxCost = " + test.maxCost);
            System.out.println( "The Max Length of a Substring of s = " + equalSubstring(test.s, test.t, test.maxCost) +'\n');
        }
    }
}