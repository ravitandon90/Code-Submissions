class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {

        int n = nums.size();
        long firstMax = LONG_MIN;
        long secondMax = LONG_MIN;
        long ans = LONG_MIN; // thirdMax Number

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == firstMax || nums[i] == secondMax || nums[i] == ans)
                continue;

            if (nums[i] > firstMax)
            {
                ans = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if (nums[i] > secondMax)
            {
                ans = secondMax;
                secondMax = nums[i];
            }
            else if (nums[i] > ans)
            {
                ans = nums[i];
            }
        }
        return ans == LONG_MIN ? firstMax : ans;
    }
};