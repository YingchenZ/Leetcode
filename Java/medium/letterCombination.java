import java.util.*;

class Solution {
    public static List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        LinkedList<String> comb = new LinkedList<>();
        String[] table = new String[]{"","","abc","def","ghi","jkl","mno", "pqrs","tuv", "wxyz"};
        comb.add("");

        for(int i = 0; i < digits.length(); i++){
            while(comb.peek().length() == i){
                String top = comb.poll();
                int index = Character.getNumericValue(digits.charAt(i));
                for(char c : table[index].toCharArray()){
                    comb.add(top + c);
                    if(top.length() + 1 == digits.length()){
                        ans.add(top + c);
                    }
                }

            }
        }
        return ans;
    }

    // Digits = 2
    // Possible Letter Combinations = [a, b, c]

    // Digits = 23
    // Possible Letter Combinations = [ad, ae, af, bd, be, bf, cd, ce, cf]

    // Digits = 34
    // Possible Letter Combinations = [dg, dh, di, eg, eh, ei, fg, fh, fi]

    public static void main(String[] args){
        String[] testSet = new String[]{"2", "23", "34"};

        for(String test : testSet){
            System.out.println("Digits = "  + test);
            System.out.println("Possible Letter Combinations = " + Arrays.toString(letterCombinations(test).toArray()) + '\n');
        }
    }
}