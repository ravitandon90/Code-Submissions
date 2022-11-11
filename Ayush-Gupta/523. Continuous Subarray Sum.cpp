class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int i, n=a.size(), sum=0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        for(i=0;i<n;i++) {
            sum+=a[i];
            if(k) sum%=k;
            if(mp.find(sum) != mp.end() && abs(i-mp[sum])>1) return 1;
            if(mp.find(sum) == mp.end()) mp[sum]=i;
        }
        return 0;
    }
};