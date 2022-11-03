class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int numsSize=nums.size(), start, curr, next;
        vector<int> target(numsSize, -1);
        for(int i=0;i<numsSize;i++){
            if(target[index[i]]==-1){
                target[index[i]]=nums[i];
            }
            else{
                start=index[i];
                curr=nums[i];
                while(target[start]!=-1){
                    next=target[start];
                    target[start]=curr;
                    curr=next;
                    start++;
                }
                target[start]=curr;
            }
        }
        return target;
    }
};
