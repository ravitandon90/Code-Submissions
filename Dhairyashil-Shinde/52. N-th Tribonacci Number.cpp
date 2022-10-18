class Solution {
public:
    int tribonacci(int n) {
        
        // Constraints: 0 <= n <= 37
        vector<int> v(39); 
        
        // given 3 values term number 0,1,2
        v[0] = 0; 
        v[1] = 1;
        v[2] = 1;
        
        if(n<=2) return v[n];
        
        // We are calculating for all the term from 0 to 37
        for(int i=3; i<=n; i++) {
            v[i] = v[i-1] + v[i-2] + v[i-3];
        }
        
        // returning the only value they asked for
        return v[n];
    }
};
