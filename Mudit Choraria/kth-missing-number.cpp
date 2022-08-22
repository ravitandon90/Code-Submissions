class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // a number N if placed correctly should be at index N - 1
        // if that is not the case, it is off by arr[N] - (N + 1)
        // this makes a simple binary search sequence as follows:
        // for arr -> [1, 3, 5, 7, 8]
        // the off sequence will be [0, 1, 2, 3, 3]
        
        int l = 0, r = size(arr) - 1;
        int ans = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(arr[mid] - (mid + 1) < k) {
                ans = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return k + ans;
    }
};

// TC: O(log N), where N is the size of array
// SC: O(1)