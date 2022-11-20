class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        
        int n = arr.size(); 
        vector<int> prefix(n); // to store prefix sum
        prefix[0] = arr[0]; // for element at index = 0, it is same
        
        // make prefix array
        for(int i = 1; i < n; i++) { 
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; 
        int ans = 0; 
        
        // traverse prefix array
        for(int i = 0; i < n; i++) {
            
            // if it already becomes equal to k, then increment ans
            if(prefix[i] == k) 
                ans++;
            
            // now, as we discussed find whether (prefix[i] - k)
            // present in map or not
            if(mp.find(prefix[i] - k) != mp.end()) {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }

            mp[prefix[i]]++; // put prefix sum into our map
        }
        return ans; 
    }
};
