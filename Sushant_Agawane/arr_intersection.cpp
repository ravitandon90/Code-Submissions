class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //store two arrays in the set 
        // then iterate the lower size one and check if ele present in set 2
        // if present add it to the vector and return vector 
        // this is applicable for unsorted arrays
        
        set<int> s1;
        set<int> s2;
        for(auto i:nums1) {
            s1.insert(i);
        }
        for(auto j:nums2) {
            s2.insert(j);
        }
        
        //iterate over set1 and check if that element present in set 2;
        nums1.clear();
        for(auto itr: s1) {
            auto pos = s2.find(itr);
            if(pos != s2.end()) {
                nums1.push_back(itr);
            }
        }
        return nums1;
    }
};