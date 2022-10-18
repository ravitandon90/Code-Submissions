class Solution
{
public:
    void dfs(vector<string> &result, int begin, string s)
    {
        // if at last, take one string
        if (begin >= s.size())
        {
            result.push_back(s);
            return;
        }
        // forward until letter
        while (begin < s.size())
        {
            if (isalpha(s[begin]))
                break;
            begin++;
        }
        dfs(result, begin + 1, s);
        // change to lower (or upper) then continue
        if (isalpha(s[begin]))
        {
            if (islower(s[begin]))
                s[begin] -= 32;
            else
                s[begin] += 32;
            dfs(result, begin + 1, s);
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        vector<string> result;
        dfs(result, 0, s);
        return result;
    }
};