class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt(1001, 0);
        for(int i=0;i<nums1.size();i++){
            cnt[nums1[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(cnt[nums2[i]]>0){
                ans.push_back(nums2[i]);
                cnt[nums2[i]]=0;
            }
        }
        return ans;
    }
};