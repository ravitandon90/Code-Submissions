class Solution
{
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int>> &ans)
    {

        if (i == j - 1)
        {
            ans.push_back(num);
            return;
        }

        for (int k = i; k < j; k++)
        {

            if (i != k && num[i] == num[k])
                continue;

            swap(num[i], num[k]);

            recursion(num, i + 1, j, ans);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &num)
    {

        sort(num.begin(), num.end());

        vector<vector<int>> ans;

        recursion(num, 0, num.size(), ans);

        return ans;
    }
};