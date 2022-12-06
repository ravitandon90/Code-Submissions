class Solution {
public:
    
    /*
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++) 
            if(nums[i] != i) 
                return i;

        return n;
    }
    */

    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int start = 0;
        int end = n-1;
        while(start <= end) {
            
            int mid = start + (end-start)/2;

            if(nums[mid] > mid) {
                end = mid-1;
            }
            else {
                start = mid+1; 
            }
        }
        return start;
    }

};
