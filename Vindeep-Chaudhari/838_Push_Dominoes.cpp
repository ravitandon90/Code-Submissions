/**
 * Problem Link - https://leetcode.com/problems/push-dominoes/
 */

class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.length();
        vector<int> forces (n);
        
        int force = 0;
        for(int i = 0; i < dominoes.length(); i++) {
            if(dominoes[i] == 'R') {
               force = n;
            } else if(dominoes[i] == '.') {
                force = max(force-1, 0);
            } else {
                force = 0;
            }
            
            forces[i] += force;
        }
        
        force = 0;
        for(int i = dominoes.length()-1; i >= 0; i--) {
            if(dominoes[i] == 'L') {
               force = n;
            } else if(dominoes[i] == '.') {
                if (i == 0) cout<<"force --- "<<force;
                force = max(force-1, 0);
            } else {
                force = 0;
            }
            
            forces[i] -= force;
        }
        
        string ans = "";
        for(int i = 0; i < forces.size(); i++) {            
            if(forces[i] > 0) {
                ans += 'R';
            } else if (forces[i] < 0) {
                ans += 'L';
            } else {
                ans += '.';
            }
        }
        
        return ans;
    }
};