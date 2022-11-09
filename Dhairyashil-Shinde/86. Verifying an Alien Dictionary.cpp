class Solution {
public:
    
    // Solution - I (Map Letters to Index & Check Adjacent Words)
    unordered_map<char, int> mp;
    
    // checking if two words are lexicographically sorted
    // according to alien language.
    bool checkOrder(string &a, string &b) {
        
        int lenA = a.length();
        int lenB = b.length();
        
        int i = 0;
        while(i < lenA && a[i] == b[i]) {
            i++;
        }
            
        if (lenA == i) 
            return true;
        else if (lenB == i) 
            return false;
        
        return mp[a[i]] < mp[b[i]];
    }
    
    bool isAlienSorted(vector<string>& words, string order) {        
    
        // mapping letter to its corresponding index in order
        int n = order.length();
        for(int i=0; i<n; i++) 
            mp[order[i]] = i;  
        
        int m = words.size();
        for(int i=0; i<m-1; i++)
            if(!checkOrder(words[i], words[i + 1])) 
                return false;
        
        return true;        
    }    
};
