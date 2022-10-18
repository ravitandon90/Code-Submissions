    bool isCheckByRecursion(vector<int>& nums, int i, int sum, unordered_map<string, bool> map) {
        
        // Memoization
        string s = to_string(i) + to_string(sum);
        if(map.find(s)!=map.end()) // string is already present in the map
            return map[s];
        
        
        // Base Cases
        if(sum < 0) // we didn't find our sum
            return false;
        if(sum == 0) // we found our sum
            return true;
        if(i==nums.size()) // we are at end of nums
            return false;
        
        // In recursive we have 2 choices for every element
        // 1. Include that element
        // 2. Don't include that element
        
        // syntax:
        // map[s] = choice 1 || choice 2
        map[s] = isCheckByRecursion(nums, i+1, sum-nums[i], map) ||
            isCheckByRecursion(nums, i+1, sum, map);
        
        return map[s];
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        
        // calculate the sum of all elements present in 'nums'
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        
        if(sum%2!=0) // Odd Value
            // we can't divide odd value in 2 partitions 
            // so return false
            return false; 
        
        // using map for memoization
        // for repeatative recusive calls
        unordered_map<string, bool> map; 
        
        // we are at this line means, sum is even, we can divide it in 2 partitions 
        // so we are going to check the condition for only 1 partition
        // bcoz both partitions are gonna have equal sum if partitions can Satisfy the gicen condition
        // so check for only one partition
        // that's why we are sending 'sum/2'
        
        // syntax
        // isCheckByRecursion(vector, iterator, sum to check in partition, map)
        return isCheckByRecursion(nums, 0, sum/2, map);
    }
};
