class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {

        int n = nums.size();

        int index = 0;
        int temp;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                index++;
            }
        }
        return nums;
    }
};