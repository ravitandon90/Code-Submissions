/**
 * Problem Link - https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int num1Ind = m-1;
        int num2Ind = n-1;
        int i = m+n-1;    
        
        while(num1Ind >= 0 && num2Ind >= 0){
            if(nums1[num1Ind]>nums2[num2Ind]) {  
                nums1[i--]=nums1[num1Ind--];
            } else {
                nums1[i--]=nums2[num2Ind--];
            }   
        }
        
        while(num2Ind >= 0) {        
            nums1[i--]=nums2[num2Ind--];
        }

    }
};

// Time complexity - O(m+n)
// Space complexity - O(1)