/**
 * Problem Link - https://leetcode.com/problems/h-index/
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end(), greater<int>());
        
        int start = 0;
        int end = citations.size()-1;
        while (start < end-1) {
            int mid = start + (end-start)/2;
            
            if(citations[mid] < mid+1) {
                end = mid;
            } else if (citations[mid] == mid+1) {
                return mid+1;
            } else {
                start = mid;
            }
        }
                
        if(citations[end] >= end + 1)
            return end + 1;
        else if(citations[start] < start + 1)
            return 0;

        return start + 1;
    }
};

// Time complexity - O(NlogN)
