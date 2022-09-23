class Solution {
public:
    bool divisorGame(int n) {
        int alice = 1, bob = 0;
        int i = 1;
        while(i <= n) {
            if(n % i == 0) {
                swap(alice, bob);
                n = n - i;
                i = 1;
            }else {
                i++;
            }
        }
        if(alice) return true;
        return false;
    }
};