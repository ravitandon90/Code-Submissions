class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n>0){
            cnt=cnt + (n&1);
            n=n>>1;
        }
        return cnt;
    }
};