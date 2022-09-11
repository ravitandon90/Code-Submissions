class Solution {
public:
    // Sort descending if their count is equal, else sort ascending.
    bool static cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.first==b.first){
            return a.second > b.second;
        }
        return a.first<b.first;
    }

    vector<int> frequencySort(vector<int>& nums) {

        // Create a vector of pairs of length 201 as nums[i] lies between -100 and 100.
        // The first element of pair stores the frequency.
        // The second element of pair stores the element value.
        vector<pair<int,int>> cnt(201, {0,0});
        for(auto x: nums){
            cnt[x+100].first+=1;
            cnt[x+100].second=x;
        }

        // Sorting using comparison operator
        sort(cnt.begin(),cnt.end(), cmp);
        
        // Storing the result in another array by iterating each element 
        vector<int> result;
        for(int i=0;i<=200;i++){
            while(cnt[i].first--){
                result.push_back(cnt[i].second);
            }
        }
        return result;
    }
};