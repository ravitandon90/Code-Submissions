#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        func(res, n, 0, 0, "");
        return res;
    }

    void func(vector<string> &res, int n, int open, int close, string curstr)
    {
        if (curstr.size() == n * 2)
        {
            res.push_back(curstr);
            return;
        }
        if (open < n)
            func(res, n, open + 1, close, curstr + "(");
        if (close < open)
            func(res, n, open, close + 1, curstr + ")");
    }
};