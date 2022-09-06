class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // TC - O(N * log(N))
        // SC - O(N)
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        sort(nums.begin(),nums.end(),[&](int &a,int&b){
            if(m[a]==m[b])
                return b<a;
            return m[a]<m[b];
        });
        return nums;
    }
};
