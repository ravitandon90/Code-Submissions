/**
 * Problem Link - https://leetcode.com/problems/fizz-buzz/
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> ans (n);
        for(int i = 1; i <= n; i++) {
            bool isDivisibleBy3 = i % 3 == 0;
            bool isDivisibleBy5 = i % 5 == 0;
            
            string a = "";
            if(isDivisibleBy3) {
                a += "Fizz";
            } 
            
            if(isDivisibleBy5) {
                a +="Buzz";
            } 
            
            if (a == ""){
                a = to_string(i);
            }
            
            ans[i-1] = a;
        }
        
        return ans;
    }
};