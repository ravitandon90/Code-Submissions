class OrderedStream {
public:

    /*
    // Code 1:
    vector<string>res;
    int ptr;

    OrderedStream(int n) {
        res.resize(n);
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        res[id-1] = value;
        vector<string> ans;
        
        if(ptr == id) {
            int i = ptr - 1;
            
            for(; i < res.size(); i++) {
                if(res[i] == "")
                    break;
                ans.push_back(res[i]);
            }
            ptr = i+1;
        }
        return ans;
    }
    */

    // Code 2:
    map<int,string> mp;
    int maxSize = -1;
    int currIndex = 1;
    
    OrderedStream(int n) {
        
        maxSize = n;
        
        for(int i=1; i<=n; i++) {
            mp[i] = "----";
        }
    }
    
    vector<string> insert(int idKey, string value) {
        
        vector<string> res;
        
        mp[idKey] = value;
        
        int i = 1;
        for(i=currIndex; i<=maxSize; i++) {
            if(mp[i] != "----") {
                res.push_back(mp[i]);
            }
            else {
                currIndex = i;
                break;
            }
        }
        
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
