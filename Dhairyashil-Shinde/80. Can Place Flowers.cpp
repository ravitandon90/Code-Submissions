class Solution {
public:
    
    // Another Solution (More neet code)
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Edge cases:
        if (n == 0) return true;
        if (flowerbed.size() == 0) return false;
        if (flowerbed.size() == 1) return flowerbed[0] == 0;
        
        // Add empty plots in the beginning and end:
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        
        // Check if there are three empty plots in a row:
        int flowers = 0, i = 0;
        while ((i < flowerbed.size() - 2) && (flowers < n)) {
            if ((flowerbed[i] == 0) && (flowerbed[i+1] == 0) && (flowerbed[i+2] == 0)) {
                flowers++;
                flowerbed[i+1] = 1;
            }
            i++;
        }
        return flowers == n;
    }
    
    /*
    // Passes All test cases!
    // Similar Solution like me:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (n == 0) return true;
        
        for (int i=0; i<flowerbed.size(); i++) {
            
            if (flowerbed[i] == 0 
                && (i == 0 || flowerbed[i - 1] == 0) 
                && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) 
            { // can place?
                --n;
                if (n == 0) return true;
                flowerbed[i] = 1; // place!
            }
        }
        return false;
    }
    */
    
    /*
    // Gives Wrong Answer for test case:
    // [0,0]
    // 2
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int len = flowerbed.size();
        if(len==1 && n==1) {
            if(flowerbed[0]==1) return false;
            else return true;
        }
        
        for(int i=1; i<len; i++) {
            
            if(n==0) break;
            
            if(flowerbed[i] == flowerbed[i-1] && flowerbed[i] == 0) {
                
                if(i-1 == 0) n--;
                
                if(i==len-1 || flowerbed[i+1] == 0) {
                    if(i-1 == 0) n--;
                    if(n!=0) n--;
                    i++;
                }
            }
        }
        
        return n==0 ? true : false;
    }
    */
};
