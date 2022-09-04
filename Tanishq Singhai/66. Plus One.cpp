class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size(), carry = 1, i = n-1;
        
        // First solution :
        // while(i>=0 && carry!=0)
        // {
        //     digits[i] += carry;
        //     carry = digits[i]/10;
        //     digits[i] %= 10;
        //     i--;
        // }
        // if(carry == 1)
        //     digits.insert(digits.begin(),1);
        
        // Second solution :
        // Time complexity - O(n)
        // Space Complexity - O(1)
        while(i>=0)
        { 
            // traverse digits from the last element (least significant)
            // since we begin with the last digit, increasing that digit by one
            // results in overflow.  Therefore, all elements PRIOR to digits[0]
            // need to be considered since there may be additional nines between
            // digits[0], ... , digits[n].
            if (digits[i] == 9)  
                digits[i] = 0;
            else 
            {  
                // current digit is not 9 so we can safely increment by one
                digits[i] += 1;
                return digits;
            }
            i--;
        }

        // if the program runs to this point, each 9 is now a 0.
        // to get a correct solution, we need to add one more element with 
        // a value of zero AND set digits[0] to 1 (in the most significant position)
        // to account for the carry digit.
        digits.push_back(0);
        digits[0] = 1;

        return digits;
    }
};