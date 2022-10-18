class Solution {
public:
/*

Approach 1
Iterate the bits of an unsigned integer from right by using right shift, and at each iteration check the parity of the first bit from right.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;  // count of set bit
        while(n>0){  // iterate until all bits are traversed
            if((n&1)>0) // check the parity of first bit from right
                ++cnt;
            n=n>>1; //n=n/2, shift one bit to right
        }
        return cnt;
    }
};

*/
    
    
    
/*
Approach 2:
More optimized solution, no. of iteration will be equal to no. of set bits.
*/
    
    int hammingWeight(uint32_t n) {
        int cnt=0;  // count of set bit
        while(n>0){  // iterate until all bits are traversed
			++cnt;
            n=n&(n-1); // change the first set bit from right to 0
        }
        return cnt;
    }

};
