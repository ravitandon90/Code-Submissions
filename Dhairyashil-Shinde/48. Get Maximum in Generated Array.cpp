class Solution {
public:
    int getMaximumGenerated(int n) {

        if (n == 0 || n == 1) 
            return n;
        
        vector<int> vec(n+1);
        
        vec[0] = 0; // For nums[0] = 0
        vec[1] = 1; // For nums[1] = 1
        
        int maxi = 1; // here we are initializing maxi by 1 bcoz, till now max value is 1 (Max value between 0 and 1 is 1)
        
        for (int i=2; i<=n; i++) {
            
            if(i%2 == 0) { // For nums[2 * i] = nums[i] when 2 <= 2 * i <= n
                vec[i] = vec[i/2];
            }
            else { // nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
                vec[i] = vec[i/2] + vec[i/2 + 1];
            }
            
            maxi = max(maxi, vec[i]);  // Update Max Element
        }
        return maxi;
    }
};
