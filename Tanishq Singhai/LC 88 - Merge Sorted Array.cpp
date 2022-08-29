class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Approach:1
        // Time complexity - O(m+n)
        // Space Complexity - O(1)
        //This code relies on the simple observation that once all of the numbers from nums2 have been merged into nums1, the rest of the numbers in nums1 that were not moved are already in the correct place.
        int i=m-1, j=n-1, tar=m+n-1;
        while(j>=0)
            nums1[tar--]= ( i>=0 && nums1[i]>nums2[j] ) ? nums1[i--] : nums2[j--] ;
        
        // Approach:2
        // Time complexity - O(m+n)
        // Space Complexity - O(1)
        // Set p1 and p2 to point to the end of their respective arrays.
        // int p1 = m - 1;
        // int p2 = n - 1;
        // And move p backwards through the array, each time writing
        // the smallest value pointed at by p1 or p2.
        // for (int p = m + n - 1; p >= 0; p--) {
        //     if (p2 < 0) 
        //         break;
        //     if (p1 >= 0 && nums1[p1] > nums2[p2]) 
        //         nums1[p] = nums1[p1--];
        //     else 
        //         nums1[p] = nums2[p2--];
        // }
        
        
        // Approach:3
        // Time complexity - O(m+n)
        // Space Complexity - O(1)
        // int total=m+n-1;
        // while(m-1>=0 && n-1>=0)
        // {
        //     if(nums1[m-1]<=nums2[n-1])
        //     {
        //         swap(nums1[total],nums2[n-1]);
        //         n--; 
        //         total--;
        //     }
        //     else
        //     {
        //         swap(nums1[total],nums1[m-1]);
        //         m--;
        //         total--;
        //     }
        // }
        // while(n-1>=0)
        // {
        //     swap(nums1[total],nums2[n-1]);
        //     n--; total--;
        // }
    }
};