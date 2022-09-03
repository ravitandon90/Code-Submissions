class Solution {
    public :
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    void reverse(vector<int>& nums, int i, int j){
        int l = i;
        int r = j;
        while(li < ri)
        {
            int temp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = temp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k < 0)
            k += n;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
};
