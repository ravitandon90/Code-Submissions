class Solution {
public:
    string intToRoman(int num) {
        string m[] = {"", "M", "MM", "MMM"};
        string c[] = {"", "C", "CC", "CCC", "CD", "D", 
                            "DC", "DCC", "DCCC", "CM"};
        string x[] = {"", "X", "XX", "XXX", "XL", "L", 
                            "LX", "LXX", "LXXX", "XC"};
        string i[] = {"", "I", "II", "III", "IV", "V", 
                            "VI", "VII", "VIII", "IX"};
        return m[num/1000] + c[(num%1000)/100] + x[(num%100)/10] + i[num%10];
    }
};