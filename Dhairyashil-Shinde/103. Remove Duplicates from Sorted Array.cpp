class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        int temp = 1; //Pointer At index '1'
        for(int i=1; i<n; i++) {

            // Array is sorted so if we encountered new element
            // that means we found next unique element

            if(nums[i] != maxi) {
                maxi = nums[i]; // update maxi
                nums[temp] = nums[i]; // change value- 'in-place'
                temp++; // Increment Pointer
            }

        }

        // after the end of loop
        // temp is present at the index of last unique element
        // so return temp

        return temp;
    }
};
