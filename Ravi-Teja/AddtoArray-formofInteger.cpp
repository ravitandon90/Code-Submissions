class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0, n=num.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            ans.push_back((num[i]+carry+k%10)%10);
            carry=(num[i]+carry+k%10)/10;
            k=k/10;
        }
        while(k>0){
            ans.push_back((k%10 + carry)%10);
            carry=(carry+k%10)/10;
            k=k/10;
        }
        if(carry>0){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};