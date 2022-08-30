class Solution {
public:
    // Time complexity - O(n)
    // Space Complexity - O(n)
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n=A.size(), carry=K;
        vector<int> res;
        for(int i=n-1;i>=0 || carry>0;i--)
        {   
            if(i>=0)
                carry+=A[i];
            res.push_back(carry%10);
            carry/=10;
        }
        if(carry!=0)
            res.push_back(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};