vector<int> runningSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    int current = 0;
    int prev = 0;

    for (int i = 0; i < n; i++)
    {
        current = nums[i];

        ans.push_back(current + prev);

        prev = ans[i];
    }
    return ans;
}