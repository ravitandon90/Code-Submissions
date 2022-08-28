class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // vector<int> primes = {2, 3, 5};
        vector<long> indices(size(primes), 0);
        
        vector<long> uglyNums{1};
        while(uglyNums.size() < n) {
            long nxtNum = INT_MAX;
            for(int i = 0; i < size(primes); i++) {
                long curr = uglyNums[indices[i]] * primes[i];
                nxtNum = min(curr, nxtNum);
            }
            for(int i = 0; i < size(primes); i++) {
                if(uglyNums[indices[i]] * primes[i] == nxtNum) {
                    indices[i]++;
                }
            }
            uglyNums.push_back(nxtNum);
        }
        return uglyNums.back();
    }
};
