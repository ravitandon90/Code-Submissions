/**
 * Problem Link - https://leetcode.com/problems/first-bad-version/
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int start = 0, end = n, mid, ans;
        
        while(start <= end) {
            mid = start + (end -start)/2;
            int bad = isBadVersion(mid);
            if(bad) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    
};