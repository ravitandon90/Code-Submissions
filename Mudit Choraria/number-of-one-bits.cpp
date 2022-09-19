class Solution {
public:
    int hammingWeight(uint32_t x) {
      int c = 0;
        while(x) {
          x = x & (x-1);
          c++;
        }
        return c;  
    }
};