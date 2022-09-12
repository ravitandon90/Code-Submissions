class Solution {
public:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &powerSet) {
        //See carefully here we are sending powerSet vector by referance
        
        int n = nums.size();
        
        //Base Case
        if(index >= n) {
            powerSet.push_back(output);
            return;
        }
        
        //Exclude (Dont take the element)
        //left recursion part in love babbar explanation
        solve(nums, output, index+1, powerSet);
        
        //Include (Take the element)
        //Right recursion part in love babbar explanation
        int element = nums[index];
        output.push_back(element);        
        
        solve(nums, output, index+1, powerSet);        
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> powerSet; //ans array to store all possible subsets i.e. right side array (love babbar explanation)
        
        vector<int> output; //right side array
        
        int index = 0;
        
        solve(nums, output, index, powerSet);
        
        return powerSet;        
    }
};
