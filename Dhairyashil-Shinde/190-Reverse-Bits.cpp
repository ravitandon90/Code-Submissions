class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bs(n);
        int l(0), r(31);
        
        while(l<r){
            bool temp = bs[l];
            bs[l++] = bs[r];
            bs[r--] = temp;
        }
        return bs.to_ulong();
    }
};
