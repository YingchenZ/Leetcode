import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        if(len <= 1)    return len;
        HashMap<Character, Integer> table = new HashMap<>();
        int start = 0, end = 0, longest = 0;

        for(; start < len && end < len; end++){
            if(table.containsKey(s.charAt(end))){
                longest = Math.max(longest, end - start);
                while(table.containsKey(s.charAt(end))){
                    table.remove(s.charAt(start));
                    start++;
                }
                table.put(s.charAt(end), 1);
            }
            else{
                table.put(s.charAt(end), 1);
            }
        }


        return Math.max(longest, end - start);
    }
}