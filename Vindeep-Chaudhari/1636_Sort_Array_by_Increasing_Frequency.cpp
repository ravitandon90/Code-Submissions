/**
 * Problem Link - https://leetcode.com/problems/sort-array-by-increasing-frequency/submissions/
 */

class Solution {
public:
    struct comp {
        constexpr bool operator()(
            pair<int, int> const& a,
            pair<int, int> const& b)
            const noexcept
        {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            
            return a.first > b.first;
        }
    };
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map <int, int> freqMap;
        for(auto num : nums) {
            freqMap[num]++;
        }
        
        priority_queue <pair<int, int> , vector<pair<int, int>>, comp > pq;
        
        for(auto m: freqMap){
            pq.push({m.second, m.first});
        }
        
        int i = 0;
        while(pq.empty() == false) {
            auto popped = pq.top();
            pq.pop();
            
            
            while(popped.first > 0) {
                nums[i] = popped.second;
                i++;
                popped.first--;
            }
        }
        
        return nums;
    }
};