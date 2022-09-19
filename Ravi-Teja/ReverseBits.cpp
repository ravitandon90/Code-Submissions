class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a=(1<<31), b=1;
        while(a>b){
            if(((n&a)!=a && (n&b)==b) || ((n&a)==a && (n&b)!=b)){
                n=(n^a);
                n=(n^b);
            }
            a=a>>1;
            b=b<<1;
        }
        return n;
    }
};