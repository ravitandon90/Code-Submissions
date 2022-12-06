class Solution {
public:

    /*
    // Code 1:
    string reorganizeString(string S) {
        string res="";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>>pq;
        
        for(auto s: S) mp[s]++;
        for(auto m: mp) pq.push(make_pair(m.second, m.first));
        
        while(pq.size()>1) {
            auto top1= pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            res += top1.second;
            res += top2.second;
            
            top1.first -= 1;
            top2.first -= 1;
            
            if(top1.first > 0) pq.push(top1);
            if(top2.first > 0) pq.push(top2);
        }
        
        if(!pq.empty()) {
            if(pq.top().first > 1) 
                return "";
            else 
                res+=pq.top().second;
        }
        
        return res;
    }
    */

    // Code 2:
    string reorganizeString(string S) {
        vector<int> cnt(26);
        int mostFreq = 0, i = 0;

        for(char c : S) {
            if(++cnt[c - 'a'] > cnt[mostFreq]) {
                mostFreq = (c - 'a');
            }
        }            

        if(2 * cnt[mostFreq] - 1 > S.size()) {
            return "";
        }

        while(cnt[mostFreq]) {
            S[i] = ('a' + mostFreq);
            i += 2;
            cnt[mostFreq]--;
        }

        for(int j = 0; j < 26; j++) {
            while(cnt[j]) {
                
                if(i >= S.size()) {
                    i = 1;
                }

                S[i] = ('a' + j);
                cnt[j]--;
                i += 2;
            }
        }

        return S;
    }
};
