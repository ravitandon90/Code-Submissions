class Solution {
public:
    int countSetBits(int n){
        
        int cnt = 0;
        while(n) {
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string> ans;
        string h;
        
        for(int i=0;i<12;i++){
        
            for(int j=0;j<60;j++){
            
                h="";
                
                if(countSetBits(i) + countSetBits(j) == turnedOn) {
                    
                    string hours = to_string(i);
                    
                    string mins = (j>9) ? to_string(j) : "0"+to_string(j);
                    
                    h = hours + ":" + mins;
                    
                    ans.push_back(h);
                }
            }
        }
        return ans;
    }
};
