class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int count=31;count>=0;count--) {
            int i=n&1;
            res=res*2+i;
            n=n>>1;
        }
        return res;
    }
};