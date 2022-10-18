class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {

        vector<vector<int>> ans;
        vector<int> d(k, 0); // size 'k' and Intilize it to '0'

        int i = 0;
        while (i >= 0)
        {

            d[i]++;

            if (d[i] > n)
            {
                --i;
            }
            else if (i == k - 1)
            {
                ans.push_back(d);
            }
            else
            {
                ++i;
                d[i] = d[i - 1];
            }
        }
        return ans;
    }
};
