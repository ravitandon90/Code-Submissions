class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> product(n,1);

        // in two pass, 
        // i.e. Time Complexity = O(2*n), 
        // Space Complexity = O(n)
        // for(int i=1;i<n;i++)
        //     product[i]=product[i-1]*nums[i-1];
        // int pro=1;
        // for(int i=n-2;i>=0;i--)
        // {
        //     pro*=nums[i+1];
        //     product[i]*=pro;
        // }
        
        // in one pass, 
        // i.e. Time Complexity = O(n), 
        // Space Complexity = O(1)
        int fromBegin=1, fromEnd=1;
        for(int i=0;i<n;i++)
        {
            product[i]*=fromBegin;
            fromBegin*=nums[i];
            product[n-i-1]*=fromEnd;
            fromEnd*=nums[n-i-1];
        }    
        return product;
    }
};