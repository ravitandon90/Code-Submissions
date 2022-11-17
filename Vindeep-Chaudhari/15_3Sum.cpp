/**
 * Problem Link - https://leetcode.com/problems/3sum/
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        if(nums[0] > 0) {
            return {};
        }


        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                break;
            }

            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int sum = 0;
            int low = i+1;
            int high = nums.size()-1;

            while(low < high) {
                sum = nums[i] + nums[low] + nums[high];

                if(sum > 0) {
                    high--;
                } else if(sum < 0) {
                    low++;
                } else {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int lastLow = nums[low];
                    int lastHigh = nums[high];
                    while(low < high && nums[low] == lastLow) {
                        low++;
                    }

                    while(low < high && nums[high] == lastHigh) {
                        high--;
                    }
                }
            }
        }

        return ans;
    }
};