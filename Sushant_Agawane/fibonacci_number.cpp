class Solution {
public:
    int fib(int n) {
        //Here we will optimize the space by not using Recursive Method here.
        int a = 0, b = 1, c;
        if(n == 0) return a;
        for(int i = 2; i <= n; i++)  {
            c = a + b;
            a = b;
            b = c;
        }
        return b;    
    }
    
    
};