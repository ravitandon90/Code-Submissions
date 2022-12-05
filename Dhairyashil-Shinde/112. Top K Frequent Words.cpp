/*
// Code 1:

class Solution {
public:

    struct compareOperator {
        
        bool operator() (pair<int, string> &a, pair<int, string> &b) {
            
            // In pair<int, string>
            // In int : we stored frequency
            // In string : we stored words
            
            // If frequecies are equal
            if(a.first == b.first) {
                return a.second < b.second; // put lexicographically greater element on top
            }
            // If frequecies are NOT equal
            else {
                return a.first > b.first;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        vector<string> ans;
        
        // Declare a map to store the frequency of words
        unordered_map<string, int> m;
        
        // Below both for loop will perform the same task!
        // for(int i=0; i<n; i++) {
        //     m[words[i]]++;
        // }
        
        for(auto word : words) {
            m[word]++;
        }
        
        // declare a priority queue
        priority_queue< pair<int,string> ,vector<pair<int,string>> , compareOperator> pq;
        
        for(auto x : m) {

            if(pq.size() < k) {
                pq.push({x.second, x.first});
            }
            else {
                if(pq.top().first < x.second || 
                  (pq.top().first == x.second && pq.top().second > x.first)) {
                    pq.pop();
                    pq.push({x.second, x.first});
                }
            }
        }
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    } 
};
*/

// Code 2

/*
Steps :
1. Insert all strings with their frequency into the map
2. Insert all the <string, frequency> pairs of map into a priority queue [create a custom comparator for that which sorts the strings by their frequency, and lexicographical order when frequency is same]
3. For K times, pop out from priority queue and store the string in an ans vector
4. Return the ans vector
*/


class comp { // custom comparator for priority_queue
    public:
        bool operator() (pair<string, int> &p1, pair<string, int> &p2) {
            if(p1.second < p2.second) return true;
            else if(p1.second > p2.second) return false;
            else if(p1.first < p2.first) return false;
            return true;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // step 1
        unordered_map<string, int> mp;
        for(auto word : words) {
            mp[word]++;
        }

        // step 2
        priority_queue< pair<string, int> , vector<pair<string, int>>, comp> pq;
        for(auto e : mp) {
            pq.push({e.first, e.second});
        }

        // step 3
        vector<string> ans;
        while(!pq.empty() && k > 0) {
            pair<string, int> s = pq.top();
            pq.pop();
            ans.push_back(s.first);
            k--;
        }

        // step 4
        return ans;
    }
};
        
