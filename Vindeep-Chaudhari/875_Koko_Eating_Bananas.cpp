/**
 * Problem Link - https://leetcode.com/problems/koko-eating-bananas/
 */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxVal = *max_element(piles.begin(), piles.end());
        if(piles.size() == h) {
            return maxVal;
        }
        
        long minK = 0;
        long start = 1, end = maxVal;
        
        while(start <= end) {
            long hoursTaken = 0;
            long mid = start + (end-start)/2;

            for(int i = 0; i < piles.size();i++) {
                if(piles[i] < mid) {
                    hoursTaken++;
                } else if(piles[i] % mid == 0) {
                    hoursTaken += piles[i]/mid;
                } else {
                    hoursTaken += piles[i]/mid + 1;
                }
            }
            
            if(hoursTaken > h) {
                    start = mid +1;
                } else {
                 minK = mid;
                    end = mid -1;
                }
            
            
        }
        
        return minK;
        
    }
};
