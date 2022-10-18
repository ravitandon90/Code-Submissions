class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] < b[0])
            return true;
        if (a[0] == b[0])
            return a[1] > b[1];

        return false;
    }

    vector<int> frequencySort(vector<int> &nums)
    {

        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        vector<vector<int>> v;
        for (auto a : m)
        {
            v.push_back({a.second, a.first});
        }

        sort(v.begin(), v.end(), cmp);

        vector<int> ans;

        for (auto a : v)
        {
            int x = a[0];
            while (x--)
            {
                ans.push_back(a[1]);
            }
        }
        return ans;
    }
};