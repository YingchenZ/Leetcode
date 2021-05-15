class Solution {
    public static int getVal(char n){
        if(n == 'I')    return 1;
        if(n == 'V')    return 5;
        if(n == 'X')    return 10;
        if(n == 'L')    return 50;
        if(n == 'C')    return 100;
        if(n == 'D')    return 500;
        if(n == 'M')    return 1000;
        return 0;
    }

    public static int romanToInt(String s) {
        int number = getVal(s.charAt(s.length() - 1));
        int preVal = number;

        for(int i = s.length() - 2; i >= 0; i--){
            int current = getVal(s.charAt(i));
            if(current < preVal){
                number -= current;
            }
            else{
                number += current;
                preVal = current;
            }
        }
        return number;
    }

    // Roman = "MCMXCIV" => Integer = 1994
    // Roman = "LVIII" => Integer = 58
    // Roman = "CD" => Integer = 40

    public static void main(String[] args){
        String[] testSet = new String[]{"MCMXCIV", "LVIII", "CD"};
        for(String test : testSet){
            System.out.println("Roman = \""+ test + "\" => Integer = " + romanToInt(test));
        }
    }
}