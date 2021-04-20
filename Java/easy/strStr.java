import java.util.*;

class Solution {
    public static int strStr(String haystack, String needle) {
        if(haystack.length() < needle.length()) return -1;
        if(needle.equals(""))   return 0;
        if(haystack.equals(""))   return -1;
        for(int i = 0; i < haystack.length(); i++){
            boolean equal = true;
            for(int j = 0; j < needle.length(); j++){
                
                if(haystack.charAt((i+j) < haystack.length()? (i+j): i) != needle.charAt(j)){
                    equal = false;
                    break;
                }
            }
            if(equal)   return i;
            if(haystack.length() - i < needle.length()) return -1;
        }
        return -1;
    }

    // haystack = "", needle = "" start at index = 0
    // haystack = "hello", needle = "ll" start at index = 2
    // haystack = "aaaaa", needle = "bba" start at index = -1        
    // haystack = "mississippi", needle = "ippia" start at index = -1

    public static void main(String[] args){
        String[][] testSet = {
            {"",""},
            {"hello","ll"},
            { "aaaaa", "bba"},
            {"mississippi", "ippia"} 
        };
        for(String[] test : testSet){
            System.out.println("haystack = \"" + test[0] + "\", needle = \"" + test[1] + "\" start at index = " + strStr(test[0], test[1]));
        }
    }
}