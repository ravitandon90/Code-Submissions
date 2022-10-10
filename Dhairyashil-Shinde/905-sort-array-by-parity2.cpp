vector<int> sortArrayByParity(vector<int> &nums)
{

    int n = nums.size();
    int s = 0;     // start
    int e = n - 1; // end

    while (1)
    {

        if (nums[s] % 2 == 0)
        {
            s++;
        }
        if (nums[e] % 2 == 1)
        {
            e--;
        }
        if (s >= e)
        {
            break;
        }
        swap(nums[s], nums[e]);
    }
    return nums;
}