
class Solution {
public:
    
    int firstBadVersion(int n) {
        
        int start = 0;
        int end = n;
        int bad;
        
        while(start<=end) {
            
            int mid = start + (end-start)/2;
            
            // cheking for mid element
            if(isBadVersion(mid)) { // if mid element is bad, then check on left
                bad = mid;
                end = mid-1;
            }
            else // otherwise check on right
                start = mid+1;
            
        }
        return bad;
    }
    
    /*
    // Frute Force : Gives TLE
    
    int firstBadVersion(int n) {
        
        int ans;
        
        for(int i=1; i<=n; i++) {
            
            if(isBadVersion(i)==true) {
                ans = i;
                return ans;
            }
        }
        return -1;
    }
    */
};
