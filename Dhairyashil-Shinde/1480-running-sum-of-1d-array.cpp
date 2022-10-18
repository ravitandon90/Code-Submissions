class Solution
{
public:
    void recursionFunc(vector<int> &nums, int count)
    {

        if (count == nums.size())
        {
            return;
        }

        nums.at(count) = nums.at(count) + nums.at(count - 1);

        recursionFunc(nums, count + 1);
    }

    vector<int> runningSum(vector<int> &nums)
    {

        if (nums.size() <= 1)
        {
            return nums;
        }

        recursionFunc(nums, 1);

        return nums;
    }
};
