/**
 * Problem Link - https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
 */

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1000000007;
        
        if(arr.size() == 0) return 0;
        
       long long prefixSum = 0;
        int even_sum_count = 0;
        int odd_sum_count = 0;
        
        even_sum_count = 1;
        
        int ans = 0;
        for(int i = 0;  i < arr.size(); i++) {
            prefixSum += arr[i];
            
            if(prefixSum % 2 == 0) {
                even_sum_count++;
                ans += odd_sum_count;
            } else {
                odd_sum_count++;
                ans += even_sum_count;
            }
            
            ans = ans%mod;
        }
        
        return ans;
    }
};