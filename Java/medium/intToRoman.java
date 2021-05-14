import java.util.*;

class Solution {
    public static String intToRoman(int num) {
        String[] one = new String[]{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        String[] ten = new String[]{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String[] hundred = new String[]{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String[] thousand = new String[]{"", "M", "MM", "MMM"};

        int o = num % 10;
        num /= 10;
        int t = num % 10;
        num /= 10;
        int h = num % 10;
        num /= 10;
        int th = num % 10;
        return thousand[th] + hundred[h] + ten[t] + one[o];
    }

    // num = 3 Roman = III
    // num = 4 Roman = IV
    // num = 9 Roman = IX
    // num = 1994      Roman = MCMXCIV   
    // num = 2030      Roman = MMXXX     
    // num = 3985      Roman = MMMCMLXXXV

    public static void main(String[] args){
        int[] testSet = new int[]{3,4,9, 1994, 2030, 3985};

        for(int test : testSet){
            System.out.println("num = " + test + "\tRoman = " + intToRoman(test));
        }
    }
}