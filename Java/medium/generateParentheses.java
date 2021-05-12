import java.util.*;

class Solution {
    private static void produce(List<String> ans, int n, String current, int open, int close){
        if(open == n && close == n){
            ans.add(current);
            return;
        }
        if(open < n){
            current += "(";
            produce(ans, n, current, open + 1, close);
            current = current.substring(0, current.length() - 1);
        }
        if(close < open){
            current += ")";
            produce(ans, n, current, open, close + 1);
            current = current.substring(0, current.length() - 1);
        }
    }

    public static List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        produce(ans, n, new String(), 0, 0);
        return ans;
    }

    // Combinations of Well-formed Parentheses When n = 1
    // [()]

    // Combinations of Well-formed Parentheses When n = 2
    // [(()), ()()]

    // Combinations of Well-formed Parentheses When n = 3
    // [((())), (()()), (())(), ()(()), ()()()]

    public static void main(String[] args){
        int[] testSet = new int[]{1,2,3};
        for(int test : testSet){
            System.out.println("Combinations of Well-formed Parentheses When n = " + test);
            List<String> ans = generateParenthesis(test);
            System.out.println(Arrays.toString(ans.toArray()) + '\n');
        }
    }
}