class NumArray {
public:
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    vector<int>v;
    int sq;
    vector<int>nums;
    NumArray(vector<int>& num) {
        int n=num.size();
        sq=ceil(1.0*sqrt(n));
        v.resize(sq);
        nums=num;
        for(int i=0;i<n;i++)
        {
            int mod=i/sq;
            v[mod]+=num[i];
        }
    }

    void update(int index, int val) {
        int mod=index/sq;
        v[mod]-=nums[index];
        v[mod]+=val;
        nums[index]=val;
    }

    int sumRange(int left, int right) {
        int sum=0;
        for(int i=left;i<=right;i++)
        {
            if(i%sq==0 && i+sq<=right)
            {
                sum+=v[i/sq];
                i+=sq-1;
            }
            else 
                sum+=nums[i];
        }
        return sum;
    }
};
