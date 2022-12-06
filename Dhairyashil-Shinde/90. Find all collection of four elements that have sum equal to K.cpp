class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
     {

      vector<vector<int>> v;
      sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
        if(i != 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < nums.size(); j++)
        {
          if(j != i + 1 && nums[j] == nums[j - 1]) continue;
          int k = j + 1;
          int l = nums.size() - 1;
          while(k < l){
            long long int sum = (long long) nums[i] + (long long) nums[j] + (long long) nums[k] + (long long) nums[l];
            if(target - sum == 0)
            {
              v.push_back({nums[i], nums[j], nums[k], nums[l]});
              k++;
              while(k < l && nums[k] == nums[k - 1]) k++;
            }
            else if(sum < target) k++;
            else l--;
          }
          
        }
      }
      
      return v;
}
};
/*

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        vector<int> quadruplets;
        sort(nums.begin(), nums.end());
        int k = 4;
        int sum = 0;

        int n = nums.size();
        for(int i=0; i<n; i++) {

            int j=i;
            while(j<k) {
                sum += nums[j];
                j++;
            }

            if(sum == target) {
                for(int p=i; p<k; p++) {
                    quadruplets.push_back(nums[i]);
                }
                
            }
        }

    }
};

*/
